/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:08:34 by emtran            #+#    #+#             */
/*   Updated: 2022/07/04 11:05:09 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	left_key(t_data *data)
{
	data->game->p1->olddir_x = data->game->p1->dir_x;
	data->game->p1->dir_x = data->game->p1->dir_x * \
	cos(-data->game->p1->rot_speed) - data->game->p1->dir_y * \
	sin(-data->game->p1->rot_speed);
	data->game->p1->dir_y = data->game->p1->olddir_x * \
	sin(-data->game->p1->rot_speed) + data->game->p1->dir_y * \
	cos(-data->game->p1->rot_speed);
	data->game->p1->oldplane_x = data->game->p1->plane_x;
	data->game->p1->plane_x = data->game->p1->plane_x * \
	cos(-data->game->p1->rot_speed) - data->game->p1->plane_y * \
	sin(-data->game->p1->rot_speed);
	data->game->p1->plane_y = data->game->p1->oldplane_x * \
	sin(-data->game->p1->rot_speed) + data->game->p1->plane_y * \
	cos(-data->game->p1->rot_speed);
}

void	right_key(t_data *data)
{
	data->game->p1->olddir_x = data->game->p1->dir_x;
	data->game->p1->dir_x = data->game->p1->dir_x * \
	cos(data->game->p1->rot_speed) - data->game->p1->dir_y * \
	sin(data->game->p1->rot_speed);
	data->game->p1->dir_y = data->game->p1->olddir_x * \
	sin(data->game->p1->rot_speed) + data->game->p1->dir_y * \
	cos(data->game->p1->rot_speed);
	data->game->p1->oldplane_x = data->game->p1->plane_x;
	data->game->p1->plane_x = data->game->p1->plane_x * \
	cos(data->game->p1->rot_speed) - data->game->p1->plane_y * \
	sin(data->game->p1->rot_speed);
	data->game->p1->plane_y = data->game->p1->oldplane_x * \
	sin(data->game->p1->rot_speed) + data->game->p1->plane_y * \
	cos(data->game->p1->rot_speed);
}
