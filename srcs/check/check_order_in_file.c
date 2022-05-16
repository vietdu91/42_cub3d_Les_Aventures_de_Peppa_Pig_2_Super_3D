/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order_in_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:04:46 by emtran            #+#    #+#             */
/*   Updated: 2022/05/16 20:01:50 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	check_infos_in_first(char *line, int *count_info)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = *count_info;
	if (!ft_strncmp(line, "NO", 2))
		(*count_info)++;
	else if (!ft_strncmp(line, "EA", 2))
		(*count_info)++;
	else if (!ft_strncmp(line, "SO", 2))
		(*count_info)++;
	else if (!ft_strncmp(line, "WE", 2))
		(*count_info)++;
	else if (!ft_strncmp(line, "C", 1))
		(*count_info)++;
	else if (!ft_strncmp(line, "F", 1))
		(*count_info)++;
	if (tmp == (*count_info) - 1)
		return (0);
	printf("yes 1\n");
	return (1);
}

int	check_line_is_empty(char *line)
{
	int	i;

	printf("hey\n");
	i = 0;
	if (!line)
		
	while (!is_space(line[i]))
		i++;
	printf("DERNIER CHAR 2 : %d\n", line[i]);
	if (!line[i])
		return (0);
	printf("yes 2\n");
	return (1);
}

int	check_one_delimiter_line_of_map(char *line)
{
	int	i;

	i = 0;
	while (!is_space(line[i]) || line[i] == '1')
		i++;
	printf("DERNIER CHAR 3 : %d\n", line[i]);
	if (!line[i])
		return (0);
	printf("yes 3\n");
	return (1);
}

int	check_good_order_in_file(t_data *data, char **file)
{
	int	i;
	int	count_info;

	i = -1;
	count_info = 0;
	while (file[++i])
	{
		printf("LINE : %s\n", file[i]);
		if (!check_infos_in_first(file[i], &count_info))
			continue ;
		else if (!check_line_is_empty(file[i]))
			continue ;
		else if (!check_one_delimiter_line_of_map(file[i]) && count_info == 6)
		{
			printf("COUNT INFO 1 : %d\n", count_info);
			data->map->first_line = i;
			return (0);
		}
		else
			print_error_and_exit(ERR_MAP_LINE, data);
	}
	printf("COUNT INFO 2 : %d\n", count_info);
	return (1);
}
