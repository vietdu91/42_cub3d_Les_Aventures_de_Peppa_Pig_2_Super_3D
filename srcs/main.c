/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:05:39 by emtran            #+#    #+#             */
/*   Updated: 2022/06/10 21:58:14 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

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

int	game_start(t_data *data)
{
	int x;
	int	y;

	y = 0;
	x = 0;
	data->img->mlx_img = mlx_new_image(data->game->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bpp, &data->img->line_len, &data->img->endian);
	printf(", bpp = %d, line_len = %d, endian = %d\n", data->img->bpp, data->img->line_len, data->img->endian);
	size_map(data, &x, &y);
	mlx_loop_hook(data->game->mlx_ptr, &render, data);
	mlx_key_hook(data->game->win_ptr, &keys_main, data);
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
