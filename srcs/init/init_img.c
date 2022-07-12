/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:39:42 by dyoula            #+#    #+#             */
/*   Updated: 2022/07/12 20:35:13 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	init_img(t_img *img)
{
	img->mlx_img = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
	return (0);
}

void	init_val(t_player *p1)
{
	p1->pos_x = 0;
	p1->pos_y = 0;
	p1->dir_x = 0;
	p1->dir_y = 0;
	p1->plane_x = 0;
	p1->plane_y = 0;
	p1->move_speed = 0.2;
	p1->rot_speed = 0.15;
	p1->camera_x = 0;
	p1->map_x = 0;
	p1->map_y = 0;
	p1->delta_dist_x = 0;
	p1->delta_dist_y = 0;
	p1->hit = 0;
	p1->raydir_x = 0;
	p1->raydir_y = 0;
}

void	init_texture(t_data *data, t_texture *text)
{
	text->wall_no = malloc(sizeof(t_img));
	if (!text->wall_no)
		print_error_and_exit(ERR_MALLOC, data);
	init_img(text->wall_no);
	text->wall_so = malloc(sizeof(t_img));
	if (!text->wall_so)
		print_error_and_exit(ERR_MALLOC, data);
	init_img(text->wall_so);
	text->wall_we = malloc(sizeof(t_img));
	if (!text->wall_we)
		print_error_and_exit(ERR_MALLOC, data);
	init_img(text->wall_we);
	text->wall_ea = malloc(sizeof(t_img));
	if (!text->wall_ea)
		print_error_and_exit(ERR_MALLOC, data);
	init_img(text->wall_ea);
	text->floor = malloc(sizeof(t_color));
	if (!text->floor)
		print_error_and_exit(ERR_MALLOC, data);
	init_color(text->floor);
	text->celling = malloc(sizeof(t_color));
	if (!text->celling)
		print_error_and_exit(ERR_MALLOC, data);
	init_color(text->celling);
}
