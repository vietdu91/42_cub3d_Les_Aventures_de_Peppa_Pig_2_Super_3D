/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:14:11 by emtran            #+#    #+#             */
/*   Updated: 2022/07/04 11:05:00 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	rgb_to_hex_text(int red, int green, int blue)
{
	int	color;

	color = ((int)(red & 0xff) << 16) + ((int)(green & 0xff) << 8)
		+ (int)(blue & 0xff);
	return (color);
}

char	*set_wall_direction(t_texture *text, t_player *peppa)
{
	if (peppa->side == NO)
		return (text->wall_no->addr);
	else if (peppa->side == SO)
		return (text->wall_so->addr);
	else if (peppa->side == EA)
		return (text->wall_ea->addr);
	else
		return (text->wall_we->addr);
}

int	get_text_rgb(char *addr, t_data *data, int add, int y)
{
	int	rgb;

	rgb = addr[(int)(data->game->p1->text_x * T_WIDTH) \
		* (data->game->texture->wall_no->bpp >> 3) \
		+ add + (int)((y - data->game->p1->text_start * 1.0) \
		/ data->game->p1->line_height * T_HEIGHT) \
		*data->game->texture->wall_no->line_len];
	return (rgb);
}

int	display_wall(t_data *data, int x, int *y, int y2)
{
	int		color;
	int		rgb[3];
	char	*addr;

	addr = set_wall_direction(data->game->texture, data->game->p1);
	while (*y < y2)
	{
		rgb[0] = get_text_rgb(addr, data, 2, *y);
		rgb[1] = get_text_rgb(addr, data, 1, *y);
		rgb[2] = get_text_rgb(addr, data, 0, *y);
		color = rgb_to_hex_text(rgb[0], rgb[1], rgb[2]);
		rgb_to_hex_text(rgb[0], rgb[1], rgb[2]);
		(void)x;
		img_pix_put(data->game->screen, x, *y, color);
		(*y)++;
	}
	return (0);
}
