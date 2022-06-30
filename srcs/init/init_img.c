/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:39:42 by dyoula            #+#    #+#             */
/*   Updated: 2022/06/30 12:25:40 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	init_img(t_img *img)
{
	img->mlx_img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
	img->x = 0;
	img->y = 0;
	img->width = 0;
	img->height = 0;
	return (0);
}

void	init_texture(t_data *data, t_texture *text)
{
	text->wall_no = (int *)malloc(sizeof(int) * T_HEIGHT * T_WIDTH);
	if (!text->wall_no)
		print_error_and_exit(ERR_MALLOC, data);
	text->wall_so = (int *)malloc(sizeof(int) * T_HEIGHT * T_WIDTH);
	if (!text->wall_so)
		print_error_and_exit(ERR_MALLOC, data);
	text->wall_we = (int *)malloc(sizeof(int) * T_HEIGHT * T_WIDTH);
	if (!text->wall_we)
		print_error_and_exit(ERR_MALLOC, data);
	text->wall_ea = (int *)malloc(sizeof(int) * T_HEIGHT * T_WIDTH);
	if (!text->wall_ea)
		print_error_and_exit(ERR_MALLOC, data);
	text->floor = malloc(sizeof(t_color));
	if (!text->floor)
		print_error_and_exit(ERR_MALLOC, data);
	init_color(v->floor);
	text->celling = malloc(sizeof(t_color));
	if (!text->celling)
		print_error_and_exit(ERR_MALLOC, data);
	init_color(text->celling);
}

int	load_xpm(t_data *data, char *path, int *tex_buf, t_img *img)
{
	int	y;
	int	x;

	img->mlx_img = mlx_xpm_file_to_image(data->mlx, path, &img->x, &img->y);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bits_per_pixel, \
	&img->line_length, &img->endian);
	y = 0;
	while (y < img->y)
	{

		x = 0;
		while (x < img->x)
		{
			tex_buf[y * 64 + x] = (int)img->addr[y * 64 + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, img->mlx_img);
	return (0);
}

int	load_textures(t_data *data, t_walls *walls, t_texture *texture)
{
	t_img	*img;

	load_xpm(data, walls->path_no, texture->wall_no, &img);
	load_xpm(data, walls->path_so, texture->wall_so, &img);
	load_xpm(data, walls->path_we, texture->wall_we, &img);
	load_xpm(data, walls->path_ea, texture->wall_ea, &img);
	return (0);
}
