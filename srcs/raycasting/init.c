/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:45:45 by dyoula            #+#    #+#             */
/*   Updated: 2022/06/30 18:40:11 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	translate_direction_player(t_player *p1, char c)
{
	if (c == 'N')
	{
		p1->dirX = p1->posX;
		p1->dirY = p1->posY - 2;
	}
	else if (c == 'S')
	{
		p1->dirX = p1->posX;
		p1->dirY = p1->posY + 2;
	}
	else if (c == 'W')
	{
		p1->dirX = p1->posX - 2;
		p1->dirY = p1->posY;
	}
	else if (c == 'E')
	{
		p1->dirX = p1->posX + 2;
		p1->dirY = p1->posY;
	}
}

int	draw_first_vector(t_data *data, int size_x, int size_y, int direction)
{
	data->game->p1->dirY = data->game->p1->posY;
	data->game->p1->dirX = data->game->p1->posX;
	if (direction == 'N')
		while (vector_has_touched(data, size_x, size_y, KEY_W) < 0)
			img_pix_put(data->img, data->game->p1->posX, \
			(data->game->p1->dirY--), GREEN);
	else if (direction == 'S')
		while (vector_has_touched(data, size_x, size_y, KEY_S) < 0)
			img_pix_put(data->img, data->game->p1->posX, \
			(data->game->p1->dirY++), GREEN);
	else if (direction == 'E')
		while (vector_has_touched(data, size_x, size_y, KEY_D) < 0)
			img_pix_put(data->img, data->game->p1->dirX++, \
			(data->game->p1->posY), GREEN);
	else if (direction == 'W')
		while (vector_has_touched(data, size_x, size_y, KEY_A) < 0)
			img_pix_put(data->img, data->game->p1->dirX--, \
			(data->game->p1->posY), GREEN);
	return (0);
}

int	draw_right_vector(t_data *data)
{
	float	i;

	(void)data;
	i = 0;
	printf("salut right vector\n");
	printf("2 * PI / 3 = %f\n", 2 * PI / 3);
	{
		while (i < 2 * PI / 3)
		{
			i += 0.1;
			printf("i = %f\n", i);
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
