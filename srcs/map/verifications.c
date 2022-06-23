/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:34:35 by dyoula            #+#    #+#             */
/*   Updated: 2022/06/16 16:54:46 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	wall_touched(t_data *data, int s_x, int s_y, int dir)
{
	int	x;
	int	y;

	x = data->game->p1->posX;
	y = data->game->p1->posY;
	if ((x) % s_x == 0 && dir == KEY_A)
		return (is_a_space_or_is_wall \
		(data->map->map[y / s_y][(x - 1) / s_x]));
	else if ((x) % s_x  == 0 && dir == KEY_D)
		return (is_a_space_or_is_wall(data->map->map[y / s_y]\
		[(x + 1) / s_x]));
	else if ((y) % s_y == 0 && dir == KEY_S )
		return (is_a_space_or_is_wall \
		(data->map->map[(y + 2) / s_y][x / s_x]));
	else if ((y) % s_y == 0 && dir == KEY_W)
		return (is_a_space_or_is_wall\
		(data->map->map[(y - 1) / s_y][x / s_x]));
	return (-1);
}

int	vector_has_touched(t_data *data, int s_x, int s_y, int dir)
{
	int	x;
	int	y;

	x = data->game->p1->dirX;
	y = data->game->p1->dirY;
	if ((x) % s_x == 0 && dir == KEY_A)
		return (is_a_space_or_is_wall \
		(data->map->map[y / s_y][(x - 1) / s_x]));
	else if ((x) % s_x  == 0 && dir == KEY_D)
		return (is_a_space_or_is_wall(data->map->map[y / s_y][(x + 1) / s_x]));
	else if ((y) % s_y == 0 && dir == KEY_S )
		return (is_a_space_or_is_wall \
		(data->map->map[(y + 2) / s_y][x / s_x]));
	else if ((y) % s_y == 0 && dir == KEY_W)
		return (is_a_space_or_is_wall(data->map->map[(y -1) / s_y][x / s_x]));
	return (-1);
}