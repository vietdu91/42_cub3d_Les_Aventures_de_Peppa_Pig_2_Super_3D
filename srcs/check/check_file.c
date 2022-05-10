/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 10:43:59 by emtran            #+#    #+#             */
/*   Updated: 2022/05/10 19:50:36 by emtran           ###   ########.fr       */
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
	return (0);
}

int	check_extension_cub(char *str, t_data *data)
{
	int		a;
	int		b;
	char	*path;

	a = 0;
	b = 0;
	path = CUB;
	while (str[a] && str[a] != '.')
		a++;
	if (!str[a])
		return (print_error_and_exit(ERR_CUB, data));
	else if (!a)
		return (print_error_and_exit(ERR_CUB, data));
	while (str[a + b] && path[b])
	{
		if (str[a + b] == path[b])
			b++;
		else
			return (print_error_and_exit(ERR_CUB, data));
	}
	if (b == 4 && str[a + b] == '\0' && path[b] == '\0')
		return (0);
	return (print_error_and_exit(ERR_CUB, data));
}
