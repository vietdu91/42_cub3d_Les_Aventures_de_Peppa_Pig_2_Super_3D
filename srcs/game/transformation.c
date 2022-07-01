/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:50:20 by emtran            #+#    #+#             */
/*   Updated: 2022/07/01 10:07:45 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	to_the_house_of_peppa(t_data *data)
{
	data->game->good_or_bad = true;
	create_img_of_walls(data, data->map->walls, data->game->texture);
	mlx_put_image_to_window(data->game->mlx_ptr, data->game->win_ptr,
		data->game->overlay_happy->img, 0, 800);
	mlx_loop_hook(data->game->mlx_ptr, &game_running, data);
	mlx_hook(data->game->win_ptr, 0, KeyPressMask, &key_press, data);
	mlx_hook(data->game->win_ptr, 33, 131072, &free_all_and_exit, data);
	mlx_loop(data->game->mlx_ptr);
	return(0);
}

int	to_the_house_of_butcher(t_data *data)
{
	data->game->good_or_bad = false;
	data->game->step_of_game = 4;
	mlx_put_image_to_window(data->game->mlx_ptr, data->game->win_ptr,
	data->game->overlay_scared->img, 0, 800);
	create_img_of_walls(data, data->map->walls, data->game->texture);
	mlx_loop_hook(data->game->mlx_ptr, &game_running, data);
	mlx_hook(data->game->win_ptr, 0, KeyPressMask, &key_press, data);
	mlx_hook(data->game->win_ptr, 33, 131072, &free_all_and_exit, data);
	mlx_loop(data->game->mlx_ptr);
	return(0);
}
