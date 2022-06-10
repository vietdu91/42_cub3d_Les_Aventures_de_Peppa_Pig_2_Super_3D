/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:23:55 by dyoula            #+#    #+#             */
/*   Updated: 2022/06/10 16:56:17 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int draw_bottom(t_data *data, int *x, int *y, int size_x)
{
	int i;

	i = 0;
	while (i < size_x)
	{
		img_pix_put(data->game->mlx_ptr, \
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
		mlx_pixel_put(data->game->mlx_ptr, data->game->win_ptr, \
		*x, *y + i, WHITE);
		i++;
	}
	return (0);	
}

void	distinct_walls(t_data *data, int *x, int y, int size_x)
{
	int i;

	i = 0;
	while (i < size_x)
	{
		mlx_pixel_put(data->game->mlx_ptr, data->game->win_ptr, \
		*x + i, y, WHITE);
		i++;
	}
}

void	draw_player(t_data *data, int x, int y)
{
	int i;
	int j;

	j = -1;
	data->game->p1->posX = x;
	data->game->p1->posY = y;
	// printf("salut x = %d et y = %d\n", x, y);
	while (j <= 5)
	{
		i = 0;
		while (i <= 5)
		{
			printf("allo\n");
			mlx_pixel_put(data->game->mlx_ptr, data->game->win_ptr, \
			x + i, y + j, RED);
			i++;
		}
		j++;
	}
}
