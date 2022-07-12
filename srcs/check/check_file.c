/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 10:43:59 by emtran            #+#    #+#             */
/*   Updated: 2022/07/12 19:02:52 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	check_file(char **argv, t_data *data)
{
	int	fd;

	if (open(argv[1], O_DIRECTORY) != -1)
		return (print_error_and_exit(ERR_DIR, data));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (print_error_and_exit(ERR_FILE, data));
	collect_nb_lines_file(data, fd);
	collect_file(data, argv);
	check_walls(data, data->file);
	check_celling_floor(data, data->file);
	check_good_order_in_file(data, data->file);
	return (0);
}

int	check_extension_cub(char *str, t_data *data)
{
	int		a;
	int		b;
	char	*path;

	(void)data;
	a = 0;
	b = 0;
	path = CUB;
	while (str[a] && str[a] != '.')
		a++;
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
