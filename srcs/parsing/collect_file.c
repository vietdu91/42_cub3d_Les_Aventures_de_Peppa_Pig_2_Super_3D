/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:10:23 by emtran            #+#    #+#             */
/*   Updated: 2022/07/13 15:16:14 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	**save_file(t_data	*data)
{
	char	**file;
	int		i;

	file = ft_calloc(data->lines_file + 1, sizeof(char *));
	if (!file)
		return (NULL);
	i = 0;
	while (i < data->lines_file)
	{
		file[i] = ft_calloc(data->max_len_file + 1, sizeof(char));
		if (!file[i])
			print_error_pars_and_exit(ERR_MALLOC, data);
		i++;
	}
	file[i] = 0;
	return (file);
}

int	collect_nb_lines_file(t_data *data, int fd)
{
	char	*line;
	int		ret;

	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (ret < 0)
		{
			close(fd);
			return (print_error_pars_and_exit(ERR_READ, data));
		}
		if (ft_strlen(line) > data->max_len_file)
			data->max_len_file = ft_strlen(line);
		data->lines_file++;
		free(line);
	}
	close(fd);
	return (0);
}

int	print_file(t_data *data, int fd, int i)
{
	char	*line;
	int		ret;
	int		j;

	j = 0;
	ret = get_next_line(fd, &line);
	if (ret < 0)
	{
		close(fd);
		return (-1);
	}
	while (j < ft_strlen(line))
	{
		data->file[i][j] = line[j];
		j++;
	}
	free(line);
	return (ret);
}

int	collect_file(t_data *data, char **argv)
{
	int		fd;
	int		ret;
	int		i;

	ret = 1;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	data->file = save_file(data);
	if (!data->file || fd < 0)
		return (print_error_pars_and_exit(ERR_FILE, data));
	while (ret)
	{
		ret = print_file(data, fd, i);
		if (ret < 0)
			print_error_pars_and_exit(ERR_READ, data);
		i++;
	}
	close(fd);
	return (0);
}
