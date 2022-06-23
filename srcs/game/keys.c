/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:39:21 by emtran            #+#    #+#             */
/*   Updated: 2022/06/23 15:50:47 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	move_player(t_data *data, int key)
{
	int	x;
	int	y;
	// int speed;
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

int	key_press(int key, t_data *data)
{
	printf("salut %d\n", key);
	// printf("%f\n", data->game->p1->moveSpeed);
//	printf("resukt = %f\n", data->game->p1->posX);
	if (key == KEY_W)
	{
		printf("movespeed = %f\n", data->game->p1->moveSpeed);
		if (data->map->map[(int)(data->game->p1->posX + data->game->p1->dirX * data->game->p1->moveSpeed)][(int)(data->game->p1->posY)] == '0')
		{
			printf("dirx = %f\n", data->game->p1->dirX);
			printf("rez = %f\n", data->game->p1->dirX * data->game->p1->moveSpeed);
			data->game->p1->posX += data->game->p1->dirX * data->game->p1->moveSpeed;
		}
		printf("X %f & Y = %f\n", data->game->p1->posX, data->game->p1->posY);
		if (data->map->map[(int)(data->game->p1->posX)][(int)(data->game->p1->posY + data->game->p1->dirY * data->game->p1->moveSpeed)] == '0')
			data->game->p1->posY += data->game->p1->dirY * data->game->p1->moveSpeed;
	}
	//move backwards if no wall behind you
	else if (key == KEY_S)
	{
		printf("resukt = %d\n", (int)(data->game->p1->posX + data->game->p1->dirX * data->game->p1->moveSpeed));
		if (!data->map->map[(int)(data->game->p1->posX - data->game->p1->dirX * data->game->p1->moveSpeed)][(int)(data->game->p1->posY)])
			data->game->p1->posX -= data->game->p1->dirX * data->game->p1->moveSpeed;
		if (!data->map->map[(int)(data->game->p1->posX)][(int)(data->game->p1->posY - data->game->p1->dirY * data->game->p1->moveSpeed)])
			data->game->p1->posY -= data->game->p1->dirY * data->game->p1->moveSpeed;
	}
	//rotate to the right
	else if (key == KEY_D)
	{
		//both camera direction and camera plane must be rotated
		data->game->p1->oldDirX = data->game->p1->dirX;
		data->game->p1->dirX = data->game->p1->dirX * cos(-data->game->p1->rotSpeed) - data->game->p1->dirY * sin(-data->game->p1->rotSpeed);
		data->game->p1->dirY = data->game->p1->oldDirX * sin(-data->game->p1->rotSpeed) + data->game->p1->dirY * cos(-data->game->p1->rotSpeed);
		data->game->p1->oldPlaneX = data->game->p1->planeX;
		data->game->p1->planeX = data->game->p1->planeX * cos(-data->game->p1->rotSpeed) - data->game->p1->planeY * sin(-data->game->p1->rotSpeed);
		data->game->p1->planeY = data->game->p1->oldPlaneX * sin(-data->game->p1->rotSpeed) + data->game->p1->planeY * cos(-data->game->p1->rotSpeed);
	}
	//rotate to the left
	else if (key == KEY_A)
	{
		//both camera direction and camera plane must be rotated
		data->game->p1->oldDirX = data->game->p1->dirX;
		data->game->p1->dirX = data->game->p1->dirX * cos(data->game->p1->rotSpeed) - data->game->p1->dirY * sin(data->game->p1->rotSpeed);
		data->game->p1->dirY = data->game->p1->oldDirX * sin(data->game->p1->rotSpeed) + data->game->p1->dirY * cos(data->game->p1->rotSpeed);
		data->game->p1->oldPlaneX = data->game->p1->planeX;
		data->game->p1->planeX = data->game->p1->planeX * cos(data->game->p1->rotSpeed) - data->game->p1->planeY * sin(data->game->p1->rotSpeed);
		data->game->p1->planeY = data->game->p1->oldPlaneX * sin(data->game->p1->rotSpeed) + data->game->p1->planeY * cos(data->game->p1->rotSpeed);
	}
	else if (key == ESC)
		exit(0);
	return (0);
}
