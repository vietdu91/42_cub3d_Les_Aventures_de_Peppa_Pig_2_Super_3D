/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:15:50 by dyoula            #+#    #+#             */
/*   Updated: 2022/06/30 15:03:21 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	void    *pixel;
	int		i;

	i = img->bpp - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)pixel = color;
}

void	verLine(t_data *data, int x, int y1, int y2, int color)
{
	int	y;

	y = 0;
	(void) color;
	if (data->game->p1->side == EA || data->game->p1->side == WE)
		data->game->p1->textX = y + data->game->p1->perpWallDist * data->game->p1->rayDirY;
	else
		data->game->p1->textX = x + data->game->p1->perpWallDist * data->game->p1->rayDirX;
	data->game->p1->textX -= floor(data->game->p1->textX);
	if (data->game->peppa->pos_peppa == 'N' || data->game->peppa->pos_peppa == 'E')
		x = WINDOW_WIDTH - x - 1;
	while (y <= y1)
	{
		mlx_pixel_put(data->game->mlx_ptr, data->game->win_ptr, x, y, \
		data->game->texture->celling->hexa);
		y++;
	}
	data->game->p1->textStart = y;
	display_wall(data, x, &y, y2);
	while (y <= WINDOW_GAME)
	{
		mlx_pixel_put(data->game->mlx_ptr, data->game->win_ptr, x, y, \
		data->game->texture->floor->hexa);
		y++;
	}
}
