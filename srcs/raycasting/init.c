/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:45:45 by dyoula            #+#    #+#             */
/*   Updated: 2022/07/12 20:06:35 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	translate_direction_player(t_player *p1, char c)
{
	if (c == 'N')
	{
		p1->dir_x = p1->pos_x;
		p1->dir_y = p1->pos_y - 2;
	}
	else if (c == 'S')
	{
		p1->dir_x = p1->pos_x;
		p1->dir_y = p1->pos_y + 2;
	}
	else if (c == 'W')
	{
		p1->dir_x = p1->pos_x - 2;
		p1->dir_y = p1->pos_y;
	}
	else if (c == 'E')
	{
		p1->dir_x = p1->pos_x + 2;
		p1->dir_y = p1->pos_y;
	}
}

int	draw_first_vector(t_data *data, int size_x, int size_y, int direction)
{
	data->game->p1->dir_y = data->game->p1->pos_y;
	data->game->p1->dir_x = data->game->p1->pos_x;
	if (direction == 'N')
		while (vector_has_touched(data, size_x, size_y, KEY_W) < 0)
			img_pix_put(data->img, data->game->p1->pos_x, \
			(data->game->p1->dir_y--), GREEN);
	else if (direction == 'S')
		while (vector_has_touched(data, size_x, size_y, KEY_S) < 0)
			img_pix_put(data->img, data->game->p1->pos_x, \
			(data->game->p1->dir_y++), GREEN);
	else if (direction == 'E')
		while (vector_has_touched(data, size_x, size_y, KEY_D) < 0)
			img_pix_put(data->img, data->game->p1->dir_x++, \
			(data->game->p1->pos_y), GREEN);
	else if (direction == 'W')
		while (vector_has_touched(data, size_x, size_y, KEY_A) < 0)
			img_pix_put(data->img, data->game->p1->dir_x--, \
			(data->game->p1->pos_y), GREEN);
	return (0);
}

int	draw_right_vector(t_data *data)
{
	float	i;

	(void)data;
	i = 0;
	{
		while (i < 2 * PI / 3)
		{
			i += 0.1;
		}
	}
	return (0);
}

void	init_direction_player(t_data *data, int direction)
{
	translate_direction_player(data->game->p1, direction);
	draw_first_vector(data, data->map->size_x, data->map->size_y, direction);
	draw_right_vector(data);
}
