/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:08:08 by emtran            #+#    #+#             */
/*   Updated: 2022/05/16 19:00:37 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	init_mlx_and_window(t_data *data, t_game *game, t_win *window)
{
	/////////////////////////////////////////////
	data->map->max_len_map = 20;
	data->map->lines_map = 10;
	/////////////////////////////////////////////
	window->win_height = data->map->max_len_map * 60;
	window->win_width = data->map->lines_map * 60;
	game->win_ptr = mlx_new_window(game->mlx_ptr, window->win_width, \
	window->win_height, "CUB3D SA MERE LA PUTA");
	if (game->win_ptr == NULL)
		return (-1);
	mlx_key_hook(game->win_ptr, &keys_main, data);
	mlx_hook(game->win_ptr, 33, 131072, &free_all_and_exit, data);
	mlx_loop(game->mlx_ptr);
	return (0);
}
