/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:23:55 by dyoula            #+#    #+#             */
/*   Updated: 2022/07/03 00:44:19 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	draw_bottom(t_data *data, int *x, int *y, int size_x)
{
	int	i;

	i = 0;
	while (i < size_x)
	{
		img_pix_put(data->img, \
		(*x + i), *y, WHITE);
		i++;
	}
	return (0);
}

int	draw_right_wall(t_data *data, int *x, int *y, int size_y)
{
	int i;

	i = 0;
	while (i < size_y)
	{
		img_pix_put(data->img, \
		*x, *y + i, WHITE);
		i++;
	}
	return (0);
}

void	distinct_walls(t_data *data, int *x, int y, int size_x)
{
	int	i;

	i = 0;
	while (i < size_x)
	{
		img_pix_put(data->img, *x + i, y, WHITE);
		i++;
	}
}

void	draw_player(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	j = -1;
	x = data->game->p1->posX * data->map->size_x;
	y = data->game->p1->posY * data->map->size_y;
	while (j < 2)
	{
		i = 0;
		while (i < 2)
		{
			img_pix_put(data->img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}
