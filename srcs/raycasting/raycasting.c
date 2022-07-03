/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:59:55 by emtran            #+#    #+#             */
/*   Updated: 2022/07/03 18:23:15 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	reset_values(t_player *p1, int x)
{
	p1->cameraX = 2 * x / (double)WINDOW_WIDTH - 1;
	p1->rayDirX = p1->dirX + p1->planeX * p1->cameraX;
	p1->rayDirY = p1->dirY + p1->planeY * p1->cameraX;
	p1->mapX = (int)p1->posX;
	p1->mapY = (int)p1->posY;
	p1->deltaDistX = fabs(1 / p1->rayDirX);
	p1->deltaDistY = fabs(1 / p1->rayDirY);
	p1->hit = 0;
	p1->textX = 0;
	p1->textStart = 0;
	p1->lineHeight = 0;
}

void	step_manager(t_player *p1)
{
	if (p1->rayDirX < 0)
	{
		p1->stepX = -1;
		p1->sideDistX = (p1->posX - p1->mapX) * p1->deltaDistX;
	}
	else
	{
		p1->stepX = 1;
		p1->sideDistX = (p1->mapX + 1.0 - p1->posX) * p1->deltaDistX;
	}
	if (p1->rayDirY < 0)
	{
		p1->stepY = -1;
		p1->sideDistY = (p1->posY - p1->mapY) * p1->deltaDistY;
	}
	else
	{
		p1->stepY = 1;
		p1->sideDistY = (p1->mapY + 1.0 - p1->posY) * p1->deltaDistY;
	}
}

void	jump_next_map_square(t_data *data, t_player *p1)
{
	while (p1->hit == 0)
	{
		if (p1->sideDistX < p1->sideDistY)
		{
			p1->sideDistX += p1->deltaDistX;
			p1->mapX += p1->stepX;
			if (p1->rayDirX > 0)
				p1->side = EA;
			else
				p1->side = WE;
		}
		else
		{
			p1->sideDistY += p1->deltaDistY;
			p1->mapY += p1->stepY;
			p1->side = 1;
			if (p1->rayDirY > 0)
				p1->side = SO;
			else
				p1->side = NO;
		}
		if (data->map->map[p1->mapY][p1->mapX] == '1')
			p1->hit = 1;
	}
}

void	check_side(t_player *p1)
{
	if (p1->side == EA || p1->side == WE)
		p1->perpWallDist = p1->sideDistX - p1->deltaDistX;
	else
		p1->perpWallDist = p1->sideDistY - p1->deltaDistY;
	p1->lineHeight = (int)(WINDOW_HEIGHT / p1->perpWallDist);
}
