/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:50:20 by emtran            #+#    #+#             */
/*   Updated: 2022/06/30 17:50:36 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	to_the_house_of_peppa(t_data *data)
{
	data->game->good_or_bad = true;
	create_img_of_walls(data, data->map->walls, data->game->texture);
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
	create_img_of_walls(data, data->map->walls, data->game->texture);
	mlx_loop_hook(data->game->mlx_ptr, &game_running, data);
	mlx_hook(data->game->win_ptr, 0, KeyPressMask, &key_press, data);
	mlx_hook(data->game->win_ptr, 33, 131072, &free_all_and_exit, data);
	mlx_loop(data->game->mlx_ptr);
	return(0);
}
