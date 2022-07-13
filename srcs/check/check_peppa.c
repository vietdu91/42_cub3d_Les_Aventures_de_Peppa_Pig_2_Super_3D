/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_peppa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:42:03 by emtran            #+#    #+#             */
/*   Updated: 2022/07/13 16:34:55 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_peppa_is_not_in_void(t_data *data, t_peppa *peppa, char **map)
{
	if (!is_bin(map[peppa->y_peppa][peppa->x_peppa - 1]))
		print_error_pars_and_exit(ERR_MAP_CLOSE, data);
	else if (!is_bin(map[peppa->y_peppa - 1][peppa->x_peppa]))
		print_error_pars_and_exit(ERR_MAP_CLOSE, data);
	else if (!is_bin(map[peppa->y_peppa][peppa->x_peppa + 1]))
		print_error_pars_and_exit(ERR_MAP_CLOSE, data);
	else if (!is_bin(map[peppa->y_peppa + 1][peppa->x_peppa]))
		print_error_pars_and_exit(ERR_MAP_CLOSE, data);
	return (0);
}

int	zero_is_not_in_void(t_data *data, int y, int x, char **map)
{
	if (!is_good_value_and_walls(map[y][x - 1]))
		print_error_pars_and_exit(ERR_MAP_CLOSE, data);
	else if (!is_good_value_and_walls(map[y - 1][x]))
		print_error_pars_and_exit(ERR_MAP_CLOSE, data);
	else if (!is_good_value_and_walls(map[y][x + 1]))
		print_error_pars_and_exit(ERR_MAP_CLOSE, data);
	else if (!is_good_value_and_walls(map[y + 1][x]))
		print_error_pars_and_exit(ERR_MAP_CLOSE, data);
	return (0);
}

int	check_position_of_peppa(t_data *data, t_peppa *peppa, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[++y])
	{
		x = 0;
		while (map[y][++x])
		{
			if (is_position(map[y][x]))
			{
				peppa->check_peppa++;
				if (peppa->check_peppa > 1)
					print_error_pars_and_exit(ERR_PEPPA_MUCH, data);
				peppa->pos_peppa = map[y][x];
				peppa->x_peppa = x;
				peppa->y_peppa = y;
				check_peppa_is_not_in_void(data, peppa, map);
			}
		}
	}
	if (!peppa->check_peppa)
		print_error_pars_and_exit(ERR_NO_PEPPA, data);
	return (0);
}
