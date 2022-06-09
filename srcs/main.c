/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:05:39 by emtran            #+#    #+#             */
/*   Updated: 2022/06/09 22:55:19 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;
	
	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp -8 - i)) & 0xFF;
		i -= 8;
	}
}

int	game_start(t_data *data)
{
	// t_img *img;
	int x;
	int	y;

	y = 0;
	x = 0;
	printf("game start\n");
	size_map(data,&x, &y);
	data->img->mlx_img = mlx_new_image(data->game->mlx_ptr, WINDOW_WIDTH /2, WINDOW_HEIGHT /2);
	data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bpp, &data->img->line_len, &data->img->endian);
	printf(", bpp = %d, line_len = %d, endian = %d\n", data->img->bpp, data->img->line_len, data->img->endian);
	mlx_loop_hook(data->game->mlx_ptr, &render, data);
	mlx_key_hook(data->game->win_ptr, &keys_main, data);
	// mlx_hook(data->game->win_ptr, 33, 131072, &free_all_and_exit, data);
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
		// convert_map_to_lines(data, data->map->map);
		init_mlx_and_window(data, data->game, &data->win);
		game_start(data);
		free_all(data);
	}
	else
		check_error_arg(argc);
	return (0);
}
