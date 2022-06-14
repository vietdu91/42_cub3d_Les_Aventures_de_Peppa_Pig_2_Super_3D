/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:45:45 by dyoula            #+#    #+#             */
/*   Updated: 2022/06/14 23:06:04 by dyoula           ###   ########.fr       */
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
	int	vector;

	vector = 0;
	if (direction == 'N')
	{
		while (wall_touched(data, size_x, size_y, KEY_A))
		{
			img_pix_put(data->img, data->game->p1->posX, (data->game->p1->posY - 1) + vector, GREEN);
			vector++;
		}
	}
	return (0);
}

void	init_direction_player(t_data *data, int direction)
{
	translate_direction_player(data->game->p1, direction);
	// draw_first_vector(data, data->map->size_x, data->map->size_y, direction);
}

