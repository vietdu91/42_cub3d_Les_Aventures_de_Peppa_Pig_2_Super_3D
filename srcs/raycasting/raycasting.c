/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:59:55 by emtran            #+#    #+#             */
/*   Updated: 2022/07/05 14:21:53 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	reset_values(t_player *p1, int x)
{
	p1->camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
	p1->raydir_x = p1->dir_x + p1->plane_x * p1->camera_x;
	p1->raydir_y = p1->dir_y + p1->plane_y * p1->camera_x;
	p1->map_x = (int)p1->pos_x;
	p1->map_y = (int)p1->pos_y;
	p1->delta_dist_x = fabs(1 / p1->raydir_x);
	p1->delta_dist_y = fabs(1 / p1->raydir_y);
	p1->hit = 0;
	p1->text_x = 0;
	p1->text_start = 0;
	p1->line_height = 0;
}

void	step_manager(t_player *p1)
{
	if (p1->raydir_x < 0)
	{
		p1->step_x = -1;
		p1->side_dist_x = (p1->pos_x - p1->map_x) * p1->delta_dist_x;
	}
	else
	{
		p1->step_x = 1;
		p1->side_dist_x = (p1->map_x + 1.0 - p1->pos_x) * p1->delta_dist_x;
	}
	if (p1->raydir_y < 0)
	{
		p1->step_y = -1;
		p1->side_dist_y = (p1->pos_y - p1->map_y) * p1->delta_dist_y;
	}
	else
	{
		p1->step_y = 1;
		p1->side_dist_y = (p1->map_y + 1.0 - p1->pos_y) * p1->delta_dist_y;
	}
}

void	else_jump_next_map_square(t_player *p1)
{
	p1->side_dist_y += p1->delta_dist_y;
	if (p1->map_y > 0)
		p1->map_y += p1->step_y;
	if (p1->raydir_y > 0)
		p1->side = SO;
	else
		p1->side = NO;
}

void	jump_next_map_square(t_data *data, t_player *p1)
{
	while (p1->hit == 0)
	{
		if (p1->side_dist_x < p1->side_dist_y)
		{
			p1->side_dist_x += p1->delta_dist_x;
			if (p1->map_x > 0)
				p1->map_x += p1->step_x;
			if (p1->raydir_x > 0)
				p1->side = EA;
			else
				p1->side = WE;
		}
		else
			else_jump_next_map_square(p1);
		if (p1->map_y < 0 || p1->map_x < 0 || p1->map_y >= \
		data->map->lines_map || p1->map_x >= data->map->max_len_map)
			p1->hit = 1;
		else if (data->map->map[p1->map_y][p1->map_x] == '1')
			p1->hit = 1;
	}
}

void	check_side(t_player *p1)
{
	if (p1->side == EA || p1->side == WE)
		p1->perp_wall_dist = p1->side_dist_x - p1->delta_dist_x;
	else
		p1->perp_wall_dist = p1->side_dist_y - p1->delta_dist_y;
	p1->line_height = (int)(WINDOW_HEIGHT / p1->perp_wall_dist);
}
