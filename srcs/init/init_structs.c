/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:35:10 by emtran            #+#    #+#             */
/*   Updated: 2022/05/24 09:08:24 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_data(t_data *data)
{
	data->file = NULL;
	data->lines_file = 0;
	data->max_len_file = 0;
	data->win.win_width = 0;
	data->win.win_height = 0;
}

void	init_struct_peppa(t_peppa *peppa)
{
	peppa->check_peppa = 0;
	peppa->x_peppa = 0;
	peppa->y_peppa = 0;
}

void	init_struct_game(t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	init_img(game->img);
	init_struct_peppa(game->peppa);
}

t_data	*init_struct(t_data *data)
{
	data = malloc(sizeof(t_data));
	data->game = malloc(sizeof(t_game));
	data->game->img = malloc(sizeof(t_img));
	data->game->peppa = malloc(sizeof(t_peppa));
	data->map = malloc(sizeof(t_map));
	data->map->walls = malloc(sizeof(t_walls));
	data->map->floor = malloc(sizeof(t_floor));
	if (!data || !data->game || !data->map)
		print_error_and_exit(ERR_MALLOC, data);
	init_data(data);
	init_struct_game(data->game);
	init_struct_map(data->map);
	return (data);
}
