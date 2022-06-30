/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:05:39 by emtran            #+#    #+#             */
/*   Updated: 2022/06/30 21:56:28 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	game_running(t_data *data)
{
	int x;
	int	line_Height;
	int draw_start;
	int	draw_end;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		reset_values(data->game->p1, x);
		step_manager(data->game->p1);
		while (data->game->p1->hit == 0)
			jump_next_map_square(data, data->game->p1);
		check_side(data->game->p1);
		line_Height = (int)(WINDOW_GAME / data->game->p1->perpWallDist);
		draw_start = -line_Height / 2 + WINDOW_GAME / 2;
		if(draw_start < 0)
			draw_start = 0;
		draw_end = line_Height / 2 + WINDOW_GAME / 2;
		if (draw_end >= WINDOW_GAME)
			draw_end = WINDOW_GAME - 1;
		verline(data, x, draw_start, draw_end);
		x++;
	}
	if (data->game->good_or_bad == true)
		mlx_put_image_to_window(data->game->mlx_ptr, data->game->win_ptr,
				data->game->overlay_happy->img, 0, 800);
	else
		mlx_put_image_to_window(data->game->mlx_ptr, data->game->win_ptr,
				data->game->overlay_scared->img, 0, 800);
	mlx_put_image_to_window(data->game->mlx_ptr, data->game->win_ptr,\
		data->img->mlx_img, 725, 800);
	return (0);
}

int loop(t_data *data)
{
	game_running(data);
	mlx_put_image_to_window(data->game->mlx_ptr, data->game->win_ptr,\
			data->img->mlx_img, 0, 0);
	return (0);
}

int	game_start(t_data *data)
{
	// t_img	*mini_map;

	data->game->step_of_game = 3;
	data->img->mlx_img = mlx_new_image(data->game->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bpp, &data->img->line_len, &data->img->endian);
	
	// mini_map = NULL;
	// mini_map = malloc (sizeof(t_img));
	
	init_val(data->game->p1);
	data->game->p1->posX = data->game->peppa->x_peppa;
	data->game->p1->posY = data->game->peppa->y_peppa;
	set_view_of_peppa(data, data->game->p1);

	
	data->img->mlx_img = mlx_new_image(data->game->mlx_ptr, 500, 250);
	data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bpp, &data->img->line_len, &data->img->endian);
	size_map(data, &data->map->size_x, &data->map->size_y);
	// mlx_put_image_to_window(data->game->mlx_ptr, data->game->win_ptr,\
	// 	data->img->mlx_img, 800, 600);

		
	create_img_of_walls(data, data->map->walls, data->game->texture);
	mlx_loop_hook(data->game->mlx_ptr, &game_running, data);
	mlx_hook(data->game->win_ptr, 0, KeyPressMask, &key_press, data);
	mlx_hook(data->game->win_ptr, 33, 131072, &free_all_and_exit, data);
	mlx_loop(data->game->mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc == 2)
	{
		data = init_struct(data);
		data->game->mlx_ptr = mlx_init();
		if (!data->game->mlx_ptr)
			print_error_and_exit(NO_ENV, data);
		check_extension_cub(argv[1], data);
		check_file(argv, data);
		check_map(data, data->map);
		assign_img_intro(data, data->game);
		assign_img_overlay(data, data->game);
		init_mlx_and_window(data, data->game, &data->win);
		introduction_of_game(data, data->game);
		game_start(data);
		free_all(data);
	}
	else
		check_error_arg(argc);
	return (0);
}
