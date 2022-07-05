/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:33:04 by emtran            #+#    #+#             */
/*   Updated: 2022/07/05 14:43:11 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	lowest_highest_height_pixel(t_sprites *sprites)
{
	sprites->sprite_height = abs((int)(WINDOW_GAME / sprites->transformy)) - 20;
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
	sprites->sprite_width = abs((int)(WINDOW_GAME / sprites->transformy));
	sprites->draw_start_x = -sprites->sprite_width * \
	0.5 + sprites->spritescreenx;
	if (sprites->draw_start_x < 0)
		sprites->draw_start_x = 0;
	sprites->draw_end_x = sprites->sprite_width / 2 + sprites->spritescreenx;
	if (sprites->draw_end_x >= WINDOW_GAME)
		sprites->draw_end_x = WINDOW_GAME - 1;
	return (0);
}

int	sprite_projection(t_data *data, t_sprites *sprites, t_player *p1)
{
	sprites->spritex = sprites->x - p1->pos_x;
	sprites->spritey = sprites->y - p1->pos_y;
	sprites->invdet = 1.0 / (p1->plane_x * p1->dir_y - p1->dir_x * p1->plane_y);
	sprites->transformx = sprites->invdet * (p1->dir_y * sprites->spritex \
	- p1->dir_x * sprites->spritey);
	sprites->transformy = sprites->invdet * (-p1->plane_y * sprites->spritex \
	+ p1->plane_x * sprites->spritey);
	sprites->spritescreenx = (int)(WINDOW_WIDTH / 2) \
	*((sprites->transformx / sprites->transformy + 1));
	lowest_highest_height_pixel(sprites);
	lowest_highest_width_pixel(sprites);
	store_color_in_buffer(data, sprites);
	return (0);
}

int	init_sprites_zbuff(int x, t_sprites *sprites, t_player *p1)
{
	sprites->z_buffer[x] = p1->perp_wall_dist;
	return (0);
}

int	sprite_casting(t_data *data, t_sprites *sprites, t_player *p1)
{
	assign_place_of_butcher(data, sprites, p1);
	sort_sprites_from_far(sprites, p1);
	sprite_projection(data, sprites, p1);
	return (0);
}
