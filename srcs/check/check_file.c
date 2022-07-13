/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 10:43:59 by emtran            #+#    #+#             */
/*   Updated: 2022/07/13 19:05:31 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	check_file(char **argv, t_data *data)
{
	int	fd;

	if (open(argv[1], O_DIRECTORY) != -1)
		return (print_error_pars_and_exit(ERR_DIR, data));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (print_error_pars_and_exit(ERR_FILE, data));
	collect_nb_lines_file(data, fd);
	collect_file(data, argv);
	check_walls(data, data->file);
	check_celling_floor(data, data->file);
	check_good_order_in_file(data, data->file);
	return (0);
}

int	check_begin_extension(char *str)
{
	int	a;

	a = 0;
	while (str[a] && str[a] != '.')
		a++;
	if (str[a] == '.' && a == 0)
	{
		a++;
		while (str[a] && str[a] != '.')
			a++;
	}
	return (a);
}

int	check_extension_cub(char *str)
{
	int		a;
	int		b;
	char	*path;

	b = 0;
	path = CUB;
	a = check_begin_extension(str);
	if (!str[a])
		return (1);
	else if (!a)
		return (1);
	while (str[a + b] && path[b])
	{
		if (str[a + b] == path[b])
			b++;
		else
			return (1);
	}
	if (b == 4 && str[a + b] == '\0' && path[b] == '\0')
		return (0);
	return (1);
}
