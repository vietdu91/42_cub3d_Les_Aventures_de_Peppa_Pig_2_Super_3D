/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:08:34 by emtran            #+#    #+#             */
/*   Updated: 2022/06/30 17:53:47 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	left_key(t_data *data)
{
	data->game->p1->oldDirX = data->game->p1->dirX;
	data->game->p1->dirX = data->game->p1->dirX * cos(-data->game->p1->rotSpeed) - data->game->p1->dirY * sin(-data->game->p1->rotSpeed);
	data->game->p1->dirY = data->game->p1->oldDirX * sin(-data->game->p1->rotSpeed) + data->game->p1->dirY * cos(-data->game->p1->rotSpeed);
	data->game->p1->oldPlaneX = data->game->p1->planeX;
	data->game->p1->planeX = data->game->p1->planeX * cos(-data->game->p1->rotSpeed) - data->game->p1->planeY * sin(-data->game->p1->rotSpeed);
	data->game->p1->planeY = data->game->p1->oldPlaneX * sin(-data->game->p1->rotSpeed) + data->game->p1->planeY * cos(-data->game->p1->rotSpeed);
}

void	right_key(t_data *data)
{
	data->game->p1->oldDirX = data->game->p1->dirX;
	data->game->p1->dirX = data->game->p1->dirX * cos(data->game->p1->rotSpeed) - data->game->p1->dirY * sin(data->game->p1->rotSpeed);
	data->game->p1->dirY = data->game->p1->oldDirX * sin(data->game->p1->rotSpeed) + data->game->p1->dirY * cos(data->game->p1->rotSpeed);
	data->game->p1->oldPlaneX = data->game->p1->planeX;
	data->game->p1->planeX = data->game->p1->planeX * cos(data->game->p1->rotSpeed) - data->game->p1->planeY * sin(data->game->p1->rotSpeed);
	data->game->p1->planeY = data->game->p1->oldPlaneX * sin(data->game->p1->rotSpeed) + data->game->p1->planeY * cos(data->game->p1->rotSpeed);
}
