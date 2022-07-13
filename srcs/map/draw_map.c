/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:04:04 by dyoula            #+#    #+#             */
/*   Updated: 2022/07/13 18:37:59 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	render(t_data *data)
{
	if (data->game->win_ptr != NULL)
	{
		mlx_put_image_to_window(data->game->mlx_ptr, data->game->win_ptr, \
			data->img->mlx_img, 0, 0);
	}
	return (0);
}

int	place_player(t_data *data, int size_x, int size_y)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	y = 0;
	while (data->map->map[++i])
	{
		j = -1;
		x = 0;
		while (data->map->map[i][++j])
		{
			if (is_player(data->map->map[i][j]) == OKAY)
			{
				draw_player(data, x + size_x / 2, y + size_y / 2, RED);
				return (data->map->map[i][j]);
			}
			x += size_x;
		}
		y += size_y;
	}
	return (0);
}

int	draw_map_background(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	z;

	i = -1;
	y = 0;
	while (data->map->map[++i])
	{
		(void)z;
		(void)x;
		(void)j;
		y += data->map->size_y;
	}
	while (y < 163)
	{
		z = -1;
		while (++z < 450)
			img_pix_put(data->img, z, y, VIOLET);
		y++;
	}
	return (0);
}

int	draw_map(t_data *data, int size_x, int size_y)
{
	int	x;
	int	y;
	int	i;
	int	j;
	int	z;

	y = 0;
	i = -1;
	while (data->map->map[++i])
	{
		j = -1;
		x = 0;
		while (data->map->map[i][++j])
		{
			if (is_a_space_or_is_wall(data->map->map[i][j]) > -1)
			{
				z = -1;
				while (++z < size_y)
					distinct_walls(data, &x, y + z, size_x);
			}
			x += size_x;
		}
		y += size_y;
	}
	return (draw_map_background(data));
}
