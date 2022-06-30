/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:14:11 by emtran            #+#    #+#             */
/*   Updated: 2022/06/30 19:35:18 by emtran           ###   ########.fr       */
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

	rgb = addr[(int)(data->game->p1->textX * T_WIDTH) * \
		(data->game->texture->wall_no->bpp >> 3) + add + \
		(int)((y - data->game->p1->textStart * 1.0)	/ \
		data->game->p1->lineHeight * T_HEIGHT) * \
		data->game->texture->wall_no->line_len];
	return (rgb);
}

int	display_wall(t_data *data, int x, int *y, int y2)
{
	int		color;
	int		r;
	int		g;
	int		b;
	char	*addr;

	addr = set_wall_direction(data->game->texture, data->game->p1);
	while (*y < y2)
	{
		r = get_text_rgb(addr, data, 2, *y);
		g = get_text_rgb(addr, data, 1, *y);
		b = get_text_rgb(addr, data, 0, *y);
		color = rgb_to_hex_text(r, g, b);
		mlx_pixel_put(data->game->mlx_ptr, data->game->win_ptr, x, *y, color);
		(*y)++;
	}
	return (0);
}
