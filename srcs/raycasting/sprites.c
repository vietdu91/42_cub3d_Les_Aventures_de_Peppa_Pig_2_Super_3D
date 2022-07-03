/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:33:04 by emtran            #+#    #+#             */
/*   Updated: 2022/07/02 23:54:49 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	sort_sprites_from_far(t_data *data, t_sprites *sprites, t_player *p1)
{
	sprites->sprite_distance = ((p1->posX - sprites->x) * \
	(p1->posx - sprites->x) + (p1->posY - sprites->y) * \
	(p1->posY - sprites->y));
	return (0);
}

int	lowest_highest_height_pixel(t_sprites *sprites)
{
	sprites->sprite_height = abs((int)(WINDOW_GAME) / sprites->transformy);
	sprites->draw_start_y = -sprites->sprite_height * 0.5 + WINDOW_GAME * 0.5;
	if (sprites->draw_start_y < 0)
		sprites->draw_start_y = 0;
	sprites->draw_end_y = sprites->sprite_height * 0.5 + WINDOW_GAME * 0.5;
	if (sprites->draw_end_y >= WINDOW_GAME)
		sprites->draw_end_y = WINDOW_GAME - 1;
	return (0);
}

int	lowest_highest_width_pixel(t_sprites *sprites)
{
	sprites->sprite_width = abs((int)(WINDOW_GAME) / sprites->transformy);
	sprites->draw_start_x = -sprites->sprite_width * 0.5 + sprites->spritescreenx;
	if (sprites->draw_start_x < 0)
		sprites->draw_start_x = 0;
	sprites->draw_end_x = sprites->sprite_width / 2 + sprites->spritescreenx;
	if (sprites->draw_end_x >= WINDOW_GAME)
		sprites->draw_end_x = WINDOW_GAME - 1;
	return (0);
}

int	store_color_in_buffer(t_data *data, t_sprites *sprites)
{
	u_int32_t	color;
	int			y;

	sprites->stripe = sprites->draw_start_x;
	while (sprites->stripe < sprites->draw_end_x)
	{
		sprites->tex_x = (int)((256 * (sprites->stripe - (-sprites->sprite_width \
		* 0.5 + sprites->spritescreenx)) * SPRITE_W / sprites->sprite_width) / 256);
		if (sprites->transformy > 0 && sprites->stripe > 0 && sprites->stripe < WINDOW_WIDTH \
		&& sprites->transformy < sprites->ZBuffer[data->sprites->stripe])
		{
			y = sprites->draw_start_y;
			while (y < sprites->draw_end_y)
			{
				// define_texy(sprites, y);
				color = store_color(data, sprites, color);
			//	draw_sprite(data, data->sprites-)
			}
		}
	}
	return (0);
}

int sprite_projection(t_data *data, t_sprites *sprites, t_player *p1)
{
	sprites->spritex = sprites->x - p1->posX;
	sprites->spritey = sprites->y - p1->posY;
	sprites->invdet = 1.0 / (p1->planeX * p1->dirY - p1->dirX * p1->planeY);
	sprites->transformx = sprites->invdet * (p1->dirY * sprites->spritex \
	- p1->dirX * sprites->spritey);
	sprites->transformy = sprites->invdet * (-p1->planeY * sprites->spritex \
	+ p1->planeX * sprites->spritey);
	sprites->spritescreenx = (int)(WINDOW_WIDTH / 2) * (1 + sprites->transformx \
	/ sprites->transformy);
	lowest_highest_height_pixel(sprites);
	lowest_highest_width_pixel(sprites);
	store_color_in_buffer(data, sprites);
	return (0);
}

int	init_sprites_zbuff(int x, t_sprites *sprites, t_player *p1)
{
	sprites->ZBuffer[x] = p1->perpWallDist;
	return (0);
}

int	sprite_casting(t_data *data, t_sprites *sprites, t_player *p1)
{
	sprites->x = 5;
	sprites->y = 5;
	sort_sprites_from_far(data, sprites, p1);
	sprite_projection(data, sprites, p1);
	return (0);
}
