/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:12:07 by dyoula            #+#    #+#             */
/*   Updated: 2022/06/24 20:12:43 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	w_key(t_data *data)
{
		if (data->map->map[(int)(data->game->p1->posY)][(int)(data->game->p1->posX + data->game->p1->dirX * data->game->p1->moveSpeed)] == '0')
			data->game->p1->posX += data->game->p1->dirX * data->game->p1->moveSpeed;
		if (data->map->map[(int)(data->game->p1->posY + data->game->p1->dirY * data->game->p1->moveSpeed)][(int)(data->game->p1->posX)] == '0')
			data->game->p1->posY += data->game->p1->dirY * data->game->p1->moveSpeed;
}

void	s_key(t_data *data)
{
	if (data->map->map[(int)(data->game->p1->posY)][(int)(data->game->p1->posX - data->game->p1->dirX * data->game->p1->moveSpeed)] == '0')
		data->game->p1->posX -= data->game->p1->dirX * data->game->p1->moveSpeed;
	if (data->map->map[(int)(data->game->p1->posY - data->game->p1->dirY * data->game->p1->moveSpeed)][(int)(data->game->p1->posX)] == '0')
		data->game->p1->posY -= data->game->p1->dirY * data->game->p1->moveSpeed;
}

void	d_key(t_data *data)
{
	data->game->p1->oldDirX = data->game->p1->dirX;
	data->game->p1->dirX = data->game->p1->dirX * cos(-data->game->p1->rotSpeed) - data->game->p1->dirY * sin(-data->game->p1->rotSpeed);
	data->game->p1->dirY = data->game->p1->oldDirX * sin(-data->game->p1->rotSpeed) + data->game->p1->dirY * cos(-data->game->p1->rotSpeed);
	data->game->p1->oldPlaneX = data->game->p1->planeX;
	data->game->p1->planeX = data->game->p1->planeX * cos(-data->game->p1->rotSpeed) - data->game->p1->planeY * sin(-data->game->p1->rotSpeed);
	data->game->p1->planeY = data->game->p1->oldPlaneX * sin(-data->game->p1->rotSpeed) + data->game->p1->planeY * cos(-data->game->p1->rotSpeed);
}

void	a_key(t_data *data)
{
	data->game->p1->oldDirX = data->game->p1->dirX;
	data->game->p1->dirX = data->game->p1->dirX * cos(data->game->p1->rotSpeed) - data->game->p1->dirY * sin(data->game->p1->rotSpeed);
	data->game->p1->dirY = data->game->p1->oldDirX * sin(data->game->p1->rotSpeed) + data->game->p1->dirY * cos(data->game->p1->rotSpeed);
	data->game->p1->oldPlaneX = data->game->p1->planeX;
	data->game->p1->planeX = data->game->p1->planeX * cos(data->game->p1->rotSpeed) - data->game->p1->planeY * sin(data->game->p1->rotSpeed);
	data->game->p1->planeY = data->game->p1->oldPlaneX * sin(data->game->p1->rotSpeed) + data->game->p1->planeY * cos(data->game->p1->rotSpeed);
}
