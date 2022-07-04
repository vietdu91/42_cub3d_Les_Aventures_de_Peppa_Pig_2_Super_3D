/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:12:07 by dyoula            #+#    #+#             */
/*   Updated: 2022/07/04 19:29:53 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_nope_wall(t_player *p1, char letter)
{
	double result;

	result = 0.2;
	if ((letter = 'x' && p1->dir_x < 0) || (letter = 'y' && p1->dir_y < 0))
	{
	//	printf("DIR X : %f == DIR Y : %f \n", p1->dir_x, p1->dir_y);
		result *= -1;
		return (result);
	}
	return (result);
}

void	w_key(t_data *data)
{
	if (data->map->map[(int)(data->game->p1->pos_y) + check_nope_wall(data->game->p1, 'y')] \
	[(int)(data->game->p1->pos_x \
	+ data->game->p1->dir_y * data->game->p1->move_speed) + check_nope_wall(data->game->p1, 'x')] != '1')
		data->game->p1->pos_x += data->game->p1->dir_x * \
		data->game->p1->move_speed;
	if (data->map->map[(int)(data->game->p1->pos_y + data->game->p1->dir_x * \
	data->game->p1->move_speed) + check_nope_wall(data->game->p1, 'y')][(int)(data->game->p1->pos_x) + check_nope_wall(data->game->p1, 'x')] != '1')
		data->game->p1->pos_y += data->game->p1->dir_y * \
		data->game->p1->move_speed;
	if (data->game->good_or_bad == false)
		sprites_move(data, 1, data->game->p1);
}

void	s_key(t_data *data)
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;

	x1 = (data->game->p1->pos_x - data->game->p1->dir_x * data->game->p1->move_speed);
	y1 = (data->game->p1->pos_y);
	x2 = (data->game->p1->pos_x);
	y2 = (data->game->p1->pos_y - data->game->p1->dir_y * data->game->p1->move_speed);

	printf("Y1 : %f\n", y1);
	printf("MUR 1: %c\n", data->map->map[(int)(y1)][(int)(x1)]);
	printf("MAP[Y][X] 1 : [%d][%d]\n", (int)(y1) , (int)(x1));
	printf("POS X : %f\n", data->game->p1->pos_x);
	printf("DIR X 1 : %f\n", data->game->p1->dir_x);
	printf("DIR Y 1 : %f\n", data->game->p1->dir_y);
	printf("========================\n");
	if (data->map->map[(int)(y1)][(int)x1] != '1')
	{
		printf("prout\n");
		data->game->p1->pos_x -= data->game->p1->dir_x * data->game->p1->move_speed;
	}
	printf("MUR 2: %c\n", data->map->map[(int)y2][(int)x2]);
	printf("MAP[Y][X] 2 : [%d][%d]\n", (int)y2 , (int)x2);
	printf("========================\n");
	if (data->map->map[(int)(y2)][(int)x2] != '1')
		data->game->p1->pos_y -= data->game->p1->dir_y * data->game->p1->move_speed;
	if (data->game->good_or_bad == false)
		sprites_move(data, 2, data->game->p1);
}

void	a_key(t_data *data)
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;

	x1 = (data->game->p1->pos_x + data->game->p1->dir_y * data->game->p1->move_speed) + check_nope_wall(data->game->p1, 'x');
	y1 = (data->game->p1->pos_y) + check_nope_wall(data->game->p1, 'y');
	x2 = (data->game->p1->pos_x) + check_nope_wall(data->game->p1, 'x');
	y2 = (data->game->p1->pos_y + data->game->p1->dir_x * data->game->p1->move_speed) + check_nope_wall(data->game->p1, 'y');

	// printf("X1 : %f\n", x1);
	// printf("MUR 1: %c\n", data->map->map[(int)y1][(int)floor(x1)]);
	// printf("MAP[Y][X] 1 : [%d][%d]\n", (int)y1 , (int)floor(x1));
	// printf("POS X : %f\n", data->game->p1->pos_x);
	// printf("DIR X 1 : %f\n", data->game->p1->dir_x);
	// printf("DIR Y 1 : %f\n", data->game->p1->dir_y);
	// printf("========================\n");
	if (data->map->map[(int)y1][(int)(x1)] != '1')
		data->game->p1->pos_x += data->game->p1->dir_y * data->game->p1->move_speed;
	// printf("MUR 2: %c\n", data->map->map[(int)y2][(int)x2]);
	// printf("MAP[Y][X] 2 : [%d][%d]\n", (int)y2 , (int)x2);
	// printf("========================\n");

	if (data->map->map[(int)y2][(int)x2] != '1')
		data->game->p1->pos_y -= data->game->p1->dir_x * data->game->p1->move_speed;
	if (data->game->good_or_bad == false)
		sprites_move(data, 1, data->game->p1);
	// printf("POS X : %f == POS Y : %f \n", data->game->p1->pos_x, data->game->p1->pos_y);
	// printf("========================\n");

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

