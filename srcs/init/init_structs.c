/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:35:10 by emtran            #+#    #+#             */
/*   Updated: 2022/07/12 20:34:14 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_struct_malloc_game(t_data *data)
{
	data->game = malloc(sizeof(t_game));
	if (!data->game)
		print_error_and_exit(ERR_MALLOC, data);
	data->game->texture = malloc(sizeof(t_texture));
	if (!data->game->texture)
		print_error_and_exit(ERR_MALLOC, data);
	data->game->peppa = malloc(sizeof(t_peppa));
	if (!data->game->peppa)
		print_error_and_exit(ERR_MALLOC, data);
	data->game->p1 = malloc(sizeof(t_player));
	if (!data->game->p1)
		print_error_and_exit(ERR_MALLOC, data);
}

void	init_struct_malloc(t_data *data)
{
	init_struct_malloc_game(data);
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		print_error_and_exit(ERR_MALLOC, data);
	data->map->walls = malloc(sizeof(t_walls));
	if (!data->map->walls)
		print_error_and_exit(ERR_MALLOC, data);
	data->map->floor = malloc(sizeof(t_floor));
	if (!data->map->floor)
		print_error_and_exit(ERR_MALLOC, data);
	data->img = malloc(sizeof(t_img));
	if (!data->img)
		print_error_and_exit(ERR_MALLOC, data);
	data->sprites = malloc(sizeof(t_sprites));
	if (!data->sprites)
		print_error_and_exit(ERR_MALLOC, data);
}

void	init_data(t_data *data)
{
	data->file = NULL;
	data->lines_file = 0;
	data->max_len_file = 0;
	data->win.win_width = 0;
	data->win.win_height = 0;
}

void	init_player(t_player *p1)
{
	p1->pos_x = 0;
	p1->pos_y = 0;
	p1->dir_x = 0;
	p1->dir_y = 0;
	p1->plane_x = 0;
	p1->plane_y = 0;
	p1->time = 0;
	p1->oldtime = 0;
	p1->px = 0;
	p1->py = 0;
	p1->pdx = 0;
	p1->pdy = 0;
	p1->pa = 0.0;
}

t_data	*init_struct(t_data *data)
{
	data = malloc(sizeof(t_data));
	if (!data)
		print_error_and_exit(ERR_MALLOC, data);
	init_struct_malloc(data);
	init_img(data->img);
	init_data(data);
	init_struct_game(data, data->game);
	init_sprites(data, data->sprites);
	init_player(data->game->p1);
	init_struct_map(data->map);
	return (data);
}
