/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:39:21 by emtran            #+#    #+#             */
/*   Updated: 2022/06/14 21:36:10 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	move_player(t_data *data, int key)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	draw_player(data,data->game->p1->posX, data->game->p1->posY, BLACK);
	if (!wall_touched(data, data->map->size_x, data->map->size_y, key))
	{
		draw_player(data,data->game->p1->posX, data->game->p1->posY, RED);
		return (-1);
	}
	if (key == KEY_W)
		data->game->p1->posY -= 1;
	else if (key == KEY_S)
		data->game->p1->posY -= -1;
	else if (key == KEY_A)
		data->game->p1->posX -= 1;
	else if (key == KEY_D)
		data->game->p1->posX += 1;
	draw_player(data,data->game->p1->posX, data->game->p1->posY, RED);
	draw_map(data, x, y);
	return (0);
}

int	keys_main(int key_code, t_data *data)
{
	if (key_code == ESC)
		free_all_and_exit(data);
	else if (key_code == KEY_W)
		move_player(data, key_code);
	else if (key_code == KEY_S)
		move_player(data, key_code);
	else if (key_code == KEY_A)
		move_player(data, key_code);
	else if (key_code == KEY_D)
		move_player(data, key_code);
	printf("pos x = %f pos = %f\n", data->game->p1->posX, data->game->p1->posY);
	return (0);
}

int	key_release_main(int keysym, void *data)
{
	(void)data;
	printf("release %d\n", keysym);
	return (0);
}

int	angle_manager(int keysim, t_player *p1)
{
	if (keysim == LOOK_LEFT)
		p1->pa -= 0.1;
	else if (keysim == LOOK_RIGHT)
		p1->pa += 0.1;
	if (p1->pa > 2 * PI)
		p1->pa = 0;
	if (p1->pa < 0)
		p1->pa = 2 * PI;
	printf("salut => pa %f\n", p1->pa);
	return (0);
}