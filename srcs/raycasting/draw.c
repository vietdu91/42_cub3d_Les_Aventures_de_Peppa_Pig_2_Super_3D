/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:15:50 by dyoula            #+#    #+#             */
/*   Updated: 2022/07/04 10:30:04 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	colors(t_data *data, t_player *p1)
{
	int	color;

	if (data->map->map[p1->mapY][p1->mapX] == '1')
		color = RED;
	else if (data->map->map[p1->mapY][p1->mapX] == '0')
		color = BLUE;
	else if (is_player(data->map->map[p1->mapY][p1->mapX]) == OKAY)
		return (0);
	else
		color = WHITE;
	if (p1->side == 1)
		color = GREEN;
	return (color);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	void	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *) pixel = color;
}

void	assign_textx(t_player *p1)
{
	if (p1->side == EA || p1->side == WE)
		p1->textX = p1->posY + p1->perpWallDist * p1->rayDirY;
	else
		p1->textX = p1->posX + p1->perpWallDist * p1->rayDirX;
	p1->textX -= floor(p1->textX);
}

t_img	*verline(t_data *data, int x, int y1, int y2)
{
	t_img	*img;
	int		y;

	y = 0;
	img = NULL;
	assign_textx(data->game->p1);
	if (data->game->peppa->pos_peppa == 'N' || \
	data->game->peppa->pos_peppa == 'E')
		x = WINDOW_WIDTH - x - 1;
	while (y < y1)
	{
		img_pix_put(data->game->screen, x, y, \
		data->game->texture->celling->hexa);
		y++;
	}
	data->game->p1->textStart = y1;
	display_wall(data, x, &y, y2);
	while (y < WINDOW_GAME)
	{
		img_pix_put(data->game->screen, x, y, \
		data->game->texture->floor->hexa);
		y++;
	}
	return (img);
}
