/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:05:39 by emtran            #+#    #+#             */
/*   Updated: 2022/06/30 19:33:31 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	reset_values(t_player *p1, int x)
{
	p1->cameraX = 2 * x / (double)WINDOW_WIDTH - 1;
	p1->rayDirX = p1->dirX + p1->planeX * p1->cameraX;
	p1->rayDirY = p1->dirY + p1->planeY * p1->cameraX;
	p1->mapX = (int)p1->posX;
	p1->mapY = (int)p1->posY;
	p1->deltaDistX = fabs(1 / p1->rayDirX);
	p1->deltaDistY = fabs(1 / p1->rayDirY);
	p1->hit = 0;
	p1->textX = 0;
	p1->textStart = 0;
	p1->lineHeight = 0;
}

void	step_manager(t_player *p1)
{
	if (p1->rayDirX < 0)
	{
		p1->stepX = -1;
		p1->sideDistX = (p1->posX - p1->mapX) * p1->deltaDistX;
	}
	else
	{
		p1->stepX = 1;
		p1->sideDistX = (p1->mapX + 1.0 - p1->posX) * p1->deltaDistX;
	}
	if (p1->rayDirY < 0)
	{
		p1->stepY = -1;
		p1->sideDistY = (p1->posY - p1->mapY) * p1->deltaDistY;
	}
	else
	{
		p1->stepY = 1;
		p1->sideDistY = (p1->mapY + 1.0 - p1->posY) * p1->deltaDistY;
	}
}

void	jump_next_map_square(t_data *data, t_player *p1)
{
	while (p1->hit == 0)
	{
		if (p1->sideDistX < p1->sideDistY)
		{
			p1->sideDistX += p1->deltaDistX;
			p1->mapX += p1->stepX;
			if (p1->rayDirX > 0)
				p1->side = EA;
			else
				p1->side = WE;
		}
		else
		{
			p1->sideDistY += p1->deltaDistY;
			p1->mapY += p1->stepY;
			p1->side = 1;
			if (p1->rayDirY > 0)
				p1->side = SO;
			else
				p1->side = NO;
		}
		if (data->map->map[p1->mapY][p1->mapX] == '1')
			p1->hit = 1;
	}
}

void	check_side(t_player *p1)
{
	if (p1->side == EA || p1->side == WE)
		p1->perpWallDist = (p1->mapX - \
		p1->posX + (1 - p1->stepX) / 2) / p1->rayDirX;
	else
		p1->perpWallDist = (p1->mapY - p1->posY + (1 - p1->stepY) / 2) / p1->rayDirY;
	p1->lineHeight = (int)(WINDOW_HEIGHT / p1->perpWallDist);
}

int		set_view_of_peppa(t_data *data, t_player *p1)
{
	if (data->game->peppa->pos_peppa == 'N')
	{
		p1->dirX = 0;
		p1->dirY = -1;
		p1->planeX = -0.66;
		p1->planeY = 0;
	}
	else if (data->game->peppa->pos_peppa == 'S')
	{
		p1->dirX = 0;
		p1->dirY = 1;
		p1->planeX = -0.66;
		p1->planeY = 0;
	}
	else if (data->game->peppa->pos_peppa == 'W')
	{
		p1->dirX = -1;
		p1->dirY = 0;
		p1->planeX = 0;
		p1->planeY = -0.66;
	}
	else if (data->game->peppa->pos_peppa == 'E')
	{
		p1->dirX = 1;
		p1->dirY = 0;
		p1->planeX = 0;
		p1->planeY = -0.66;
	}
	return (0);
}

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
		verLine(data, x, draw_start, draw_end, colors(data, data->game->p1));
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
