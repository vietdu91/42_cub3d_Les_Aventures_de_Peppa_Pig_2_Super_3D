/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:05:39 by emtran            #+#    #+#             */
/*   Updated: 2022/06/23 18:38:13 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	void    *pixel;
	int		i;

	i = img->bpp - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)pixel = color;
	// while (i >= 0)
	// {
	// 	if (img->endian != 0)
	// 		*pixel++ = (color >> i) & 0xFF;
	// 	else
	// 		*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
	// 	i -= 8;
	// }
}

void	verLine(t_data *data, int x, int y1, int y2, int color)
{
	int	y;

	y = 0;
//	printf("Celling : %s\n", data->game->texture->celling->hexa);
//	printf("Floor : %s\n", data->game->texture->floor->hexa);
	while (y <= y1)
	{
		mlx_pixel_put(data->game->mlx_ptr, data->game->win_ptr, x, y, ft_atoi(data->game->texture->celling->hexa));
		y++;		
	}
	while (y <= y2)
	{
		mlx_pixel_put(data->game->mlx_ptr, data->game->win_ptr, x, y, color);
		y++;
	}
	while (y <= WINDOW_HEIGHT)
	{
		mlx_pixel_put(data->game->mlx_ptr, data->game->win_ptr, x, y, ft_atoi(data->game->texture->celling->hexa));
		y++;		
	}
}

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
	//jump to next map square, OR in x-direction, OR in y-direction
	if (p1->sideDistX < p1->sideDistY)
	{
		p1->sideDistX += p1->deltaDistX;
		p1->mapX += p1->stepX;
		p1->side = 0;
	}
	else
	{
		p1->sideDistY += p1->deltaDistY;
		p1->mapY += p1->stepY;
		p1->side = 1;
	}
	//Check if ray has hit a wall
	// printf("MAPX : %d\n", p1->mapX);
	// printf("posY : %f\n", p1->posY);
	// printf("MAPY : %d\n", p1->mapY);

	if (data->map->map[p1->mapY][p1->mapX] > '0')
		p1->hit = 1;
}

void	check_side(t_player *p1)
{
	if (p1->side == 0)
		p1->perpWallDist = (p1->mapX - \
		p1->posX + (1 - p1->stepX) / 2) / p1->rayDirX;
	else
		p1->perpWallDist = (p1->mapY - p1->posY + (1 - p1->stepY) / 2) /\
		p1->rayDirY;
}

int		colors(t_data *data, t_player *p1)
{
		int	color;
	//	printf("%c\n", data->map->map[p1->mapY][p1->mapX]);
		if (data->map->map[p1->mapY][p1->mapX] == '1')
			color = RED;
		else if (data->map->map[p1->mapY][p1->mapX] == '0')
			color = BLUE;
		// else if (data->map->map[p1->mapY][p1->mapX] == 3)
		// 	color = 0x0000FF;
		// else if (data->map->map[p1->mapY][p1->mapX] == 4)
		// 	color = 0xFFFFFF;
		else
			color = WHITE;
		if (p1->side == 1)
			color = GREEN;
		return (color);
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
		line_Height = (int)(WINDOW_HEIGHT / data->game->p1->perpWallDist);
		draw_start = -line_Height / 2 + WINDOW_HEIGHT / 2;
		if(draw_start < 0)
			draw_start = 0;
		draw_end = line_Height / 2 + WINDOW_HEIGHT / 2;
		if (draw_end >= WINDOW_HEIGHT)
			draw_end = WINDOW_HEIGHT - 1;
	//	verLine(data, x, )
		verLine(data, x, draw_start, draw_end, colors(data, data->game->p1));
		x++;
		//printf()
	}
	return (0);
}

int loop(t_data *data)
{
	game_running(data);
	mlx_put_image_to_window(data->game->mlx_ptr, data->game->win_ptr,\
			data->img->mlx_img, 0, 0);
	return (0);
	// mlx_put_image_to_window(info->mlx, info->win, &info->img, 0, 0);
}

void	init_val(t_player *p1)
{
	p1->posX = 0;
	p1->posY = 0;
	p1->dirX = -1;
	p1->dirY = 0;
	p1->planeX = 0;
	p1->planeY = 0.66;
	p1->moveSpeed = 0.3;
	p1->rotSpeed = 0.05;
	p1->cameraX = 0;
	p1->mapX = 0;
	p1->mapY = 0;
	p1->deltaDistX = 0;
	p1->deltaDistY = 0;
	p1->hit = 0;
	p1->rayDirX = 0;
	p1->rayDirY = 0;	
}

int	game_start(t_data *data)
{
	data->img->mlx_img = mlx_new_image(data->game->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bpp, &data->img->line_len, &data->img->endian);
	init_val(data->game->p1);
	// size_map(data, &data->map->size_x, &data->map->size_y);
	data->game->p1->posX = 5;
	data->game->p1->posY = 6;
	// printf("size_x = %d && size_y = %d", data->map->size_x, data->map->size_y);
	// exit (0);
	// int i;
	// int v;

	// i = 0;
	// while (++i < 300)
	// {
	// 	v = 2 * i * PI;
	// 	printf("salut v = %d\n", v);
	// 	mlx_pixel_put(data->game->mlx_ptr, data->game->win_ptr, i, v, RED);
	// }
	// mlx_loop_hook(data->game->mlx_ptr, &render, data);
	printf("resukt = %f\n", data->game->p1->posX);
	mlx_loop_hook(data->game->mlx_ptr, &game_running, data);
	mlx_hook(data->game->win_ptr, KeyRelease, KeyPressMask, &key_press, data);
	// mlx_mouse_hook (data->game->win_ptr, &mouse_manager, data);
	// render(data);
	// mlx_hook(data->game->win_ptr, KeyRelease, KeyReleaseMask, &keys_main, data);
	// mlx_hook(data->game->win_ptr, KeyPress, KeyPressMask, &angle_manager, data->game->p1);
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
		init_mlx_and_window(data, data->game, &data->win);
		game_start(data);
		free_all(data);
	}
	else
		check_error_arg(argc);
	return (0);
}
