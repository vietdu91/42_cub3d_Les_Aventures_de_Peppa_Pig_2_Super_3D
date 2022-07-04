/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:34:35 by dyoula            #+#    #+#             */
/*   Updated: 2022/07/04 10:57:33 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	wall_touched(t_data *data, int s_x, int s_y, int dir)
{
	int	x;
	int	y;

	x = data->game->p1->pos_x;
	y = data->game->p1->pos_y;
	if ((x) % s_x == 0 && dir == KEY_A)
		return (is_a_space_or_is_wall \
		(data->map->map[y / s_y][(x - 1) / s_x]));
	else if ((x) % s_x == 0 && dir == KEY_D)
		return (is_a_space_or_is_wall(data->map->map[y / s_y] \
		[(x + 1) / s_x]));
	else if ((y) % s_y == 0 && dir == KEY_S)
		return (is_a_space_or_is_wall \
		(data->map->map[(y + 2) / s_y][x / s_x]));
	else if ((y) % s_y == 0 && dir == KEY_W)
		return (is_a_space_or_is_wall \
		(data->map->map[(y - 1) / s_y][x / s_x]));
	return (-1);
}

int	vector_has_touched(t_data *data, int s_x, int s_y, int dir)
{
	int	x;
	int	y;

	x = data->game->p1->dir_x;
	y = data->game->p1->dir_y;
	if ((x) % s_x == 0 && dir == KEY_A)
		return (is_a_space_or_is_wall \
		(data->map->map[y / s_y][(x - 1) / s_x]));
	else if ((x) % s_x == 0 && dir == KEY_D)
		return (is_a_space_or_is_wall(data->map->map[y / s_y][(x + 1) / s_x]));
	else if ((y) % s_y == 0 && dir == KEY_S)
		return (is_a_space_or_is_wall \
		(data->map->map[(y + 2) / s_y][x / s_x]));
	else if ((y) % s_y == 0 && dir == KEY_W)
		return (is_a_space_or_is_wall(data->map->map[(y -1) / s_y][x / s_x]));
	return (-1);
}
