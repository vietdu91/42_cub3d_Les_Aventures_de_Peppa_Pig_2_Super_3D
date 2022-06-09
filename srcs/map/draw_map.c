/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:04:04 by dyoula            #+#    #+#             */
/*   Updated: 2022/06/08 20:24:52 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	render(t_data *data)
{
	int x;
	int	y;
	
	x = 0;
	y = 0;
	if (data->game->win_ptr != NULL)
	{
		// size_map(data, &x, &y);
	}
	return (0);
}

void	place_player(t_data *data, int size_x, int size_y)
{
	int i;
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
				draw_player(data, x + size_x / 2, y + size_y / 2);
				return ;
			}
			x += size_x;
		}
		y += size_y;
	}
}

int	draw_map(t_data *data, int size_x, int size_y)
{
	int	x;
	int	y;
	int i;
	int	j;
	int z;

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
			else
			{
				draw_bottom(data, &x, &y, size_x);
				draw_right_wall(data, &x, &y, size_y);
			}
			x += size_x;
		}
		y += size_y;
	}
	return (0);
}


int	convert_map_to_lines(t_data *data, char **map)
{

	(void)data;
	(void)map;
	return (0);
}