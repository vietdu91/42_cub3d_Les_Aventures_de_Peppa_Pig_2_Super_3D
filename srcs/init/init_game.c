/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:08:08 by emtran            #+#    #+#             */
/*   Updated: 2022/06/10 12:59:35 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	init_mlx_and_window(t_data *data, t_game *game, t_win *window)
{
	/////////////////////////////////////////////
	data->map->max_len_map = 20;
	data->map->lines_map = 10;
	/////////////////////////////////////////////
	window->win_height = WINDOW_HEIGHT; // data->map->max_len_map * 60;
	window->win_width = WINDOW_WIDTH; //data->map->lines_map * 60;
	game->win_ptr = mlx_new_window(game->mlx_ptr, window->win_width, \
	window->win_height, "CUB3D SA MERE LA PUTA");
	if (game->win_ptr == NULL)
		return (-1);
	return (0);
}

void	init_struct_game(t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	init_texture(game->texture);
	init_struct_peppa(game->peppa);
}
