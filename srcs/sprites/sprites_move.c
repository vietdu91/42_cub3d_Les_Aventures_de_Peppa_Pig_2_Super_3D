/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:49:17 by emtran            #+#    #+#             */
/*   Updated: 2022/07/03 19:27:08 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int sprites_move_backward(t_data *data, t_player *p1)
{
	int	x;
	int	y;

	x = data->map->map[(int)data->sprites->y][(int)data->sprites->x];
	y = data->map->map[(int)data->sprites->y][(int)data->sprites->x];
	if (x != '1')
	{
		data->sprites->x = data->sprites->x - \
		((data->sprites->x - p1->posX) * 0.02);
		data->sprites->y = data->sprites->y - \
		((data->sprites->y - p1->posY) * 0.02);
		if ((int)data->sprites->spritex == 0 && \
		(int)data->sprites->spritey == 0)
			return (0);
	}
	return (0);
}

int sprites_move_forward(t_data *data, t_player *p1)
{
	int	x;
	int	y;

	x = data->map->map[(int)data->sprites->y][(int)data->sprites->x];
	y = data->map->map[(int)data->sprites->y][(int)data->sprites->x];
	if (x != '1')
	{
		data->sprites->x = data->sprites->x - \
		((data->sprites->x - p1->posX) * 0.01);
		data->sprites->y = data->sprites->y - \
		((data->sprites->y - p1->posY) * 0.01);
		if ((int)data->sprites->spritex == 0 && \
		(int)data->sprites->spritey == 0)
		{
			death_of_peppa_pig(data, data->game);
			exit(0);
		}
	}
	return (0);
}

int	sprites_move(t_data *data, int a, t_player *p1)
{
	if (a == 1)
		sprites_move_forward(data, p1);
	if (a == 2)
		sprites_move_backward(data, p1);
	return (0);
}
