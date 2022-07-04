/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:12:07 by dyoula            #+#    #+#             */
/*   Updated: 2022/07/04 17:34:23 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_nope_wall(t_player *p1, char letter)
{
	double result;

	result = 0.3;
	if ((letter = 'x' && p1->dir_x < 0) || (letter = 'y' && p1->dir_y < 0))
	{
	//	printf("DIR X : %f == DIR Y : %f \n", p1->dir_x, p1->dir_y);
		result = 0.3 * -1;
		return (result);
	}
	return (result);
}

void	w_key(t_data *data)
{
	if (data->map->map[(int)(data->game->p1->pos_y) + check_nope_wall(data->game->p1, 'y')] \
	[(int)(data->game->p1->pos_x \
	+ data->game->p1->dir_x * data->game->p1->move_speed) + check_nope_wall(data->game->p1, 'x')] != '1')
		data->game->p1->pos_x += data->game->p1->dir_x * \
		data->game->p1->move_speed;
	if (data->map->map[(int)(data->game->p1->pos_y + data->game->p1->dir_y * \
	data->game->p1->move_speed) + check_nope_wall(data->game->p1, 'y')][(int)(data->game->p1->pos_x) + check_nope_wall(data->game->p1, 'x')] != '1')
		data->game->p1->pos_y += data->game->p1->dir_y * \
		data->game->p1->move_speed;
	if (data->game->good_or_bad == false)
		sprites_move(data, 1, data->game->p1);
}

void	s_key(t_data *data)
{
	if (data->map->map[(int)(data->game->p1->pos_y)] \
	[(int)(data->game->p1->pos_x \
	- data->game->p1->dir_x * data->game->p1->move_speed)] != '1')
		data->game->p1->pos_x -= data->game->p1->dir_x * \
		data->game->p1->move_speed;
	if (data->map->map[(int)(data->game->p1->pos_y - data->game->p1->dir_y * \
	data->game->p1->move_speed)][(int)(data->game->p1->pos_x)] != '1')
		data->game->p1->pos_y -= data->game->p1->dir_y * \
		data->game->p1->move_speed;
	if (data->game->good_or_bad == false)
		sprites_move(data, 2, data->game->p1);
}

void	a_key(t_data *data)
{
	printf("MUR 1: %c\n", data->map->map[(int)(data->game->p1->pos_y) + check_nope_wall(data->game->p1, 'y')] \
	[(int)(data->game->p1->pos_x \
	+ data->game->p1->dir_x * data->game->p1->move_speed) + check_nope_wall(data->game->p1, 'x')]);
	printf("MAP[Y][X] : [%d][%d]\n", (int)((data->game->p1->pos_y) + check_nope_wall(data->game->p1, 'y')) ,(int)((data->game->p1->pos_x + data->game->p1->dir_x * data->game->p1->move_speed) + check_nope_wall(data->game->p1, 'x')));
	if (data->map->map[(int)((data->game->p1->pos_y) + check_nope_wall(data->game->p1, 'y'))] \
	[(int)(data->game->p1->pos_x \
	+ data->game->p1->dir_x * data->game->p1->move_speed) + check_nope_wall(data->game->p1, 'x')] != '1')

		data->game->p1->pos_x += data->game->p1->dir_y * \
		data->game->p1->move_speed;

	printf("MUR 2: %c\n", data->map->map[(int)(data->game->p1->pos_y +\
	data->game->p1->dir_y * \
	data->game->p1->move_speed) + check_nope_wall(data->game->p1, 'y')][(int)(data->game->p1->pos_x) + check_nope_wall(data->game->p1, 'x')]);

	if (data->map->map[(int)(data->game->p1->pos_y + \
	data->game->p1->dir_y * \
	data->game->p1->move_speed) + check_nope_wall(data->game->p1, 'y')][(int)(data->game->p1->pos_x) + check_nope_wall(data->game->p1, 'x')] != '1')

		data->game->p1->pos_y -= data->game->p1->dir_x * \
		data->game->p1->move_speed;

	if (data->game->good_or_bad == false)
		sprites_move(data, 1, data->game->p1);
	printf("POS X : %f == POS Y : %f \n", data->game->p1->pos_x, data->game->p1->pos_y);
}

void	d_key(t_data *data)
{
	if (data->map->map[(int)(data->game->p1->pos_y)] \
	[(int)(data->game->p1->pos_x + data->game->p1->dir_x * \
	data->game->p1->move_speed)] != '1')
	{
		data->game->p1->pos_x -= data->game->p1->dir_y * \
		data->game->p1->move_speed;
	}
	if (data->map->map[(int)(data->game->p1->pos_y + data->game->p1->dir_y * \
	data->game->p1->move_speed)][(int)(data->game->p1->pos_x)] != '1')
		data->game->p1->pos_y += data->game->p1->dir_x * \
		data->game->p1->move_speed;
	if (data->game->good_or_bad == false)
		sprites_move(data, 1, data->game->p1);
}

