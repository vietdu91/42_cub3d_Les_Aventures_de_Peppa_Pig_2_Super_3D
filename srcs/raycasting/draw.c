/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:15:50 by dyoula            #+#    #+#             */
/*   Updated: 2022/06/30 21:55:52 by dyoula           ###   ########.fr       */
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
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *) pixel = color;
}

void	assign_textx(t_player *p1, int x, int y)
{
	if (p1->side == EA || p1->side == WE)
		p1->textX = y + p1->perpWallDist * p1->rayDirY;
	else
		p1->textX = x + p1->perpWallDist * p1->rayDirX;
	p1->textX -= floor(p1->textX);
}

void	verline(t_data *data, int x, int y1, int y2)
{
	int	y;

	y = 0;
	assign_textx(data->game->p1, x, y);
	if (data->game->peppa->pos_peppa == 'N' || \
	data->game->peppa->pos_peppa == 'E')
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
