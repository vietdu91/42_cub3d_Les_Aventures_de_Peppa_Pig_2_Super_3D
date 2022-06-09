/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:51:21 by emtran            #+#    #+#             */
/*   Updated: 2022/06/09 17:45:15 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_pic(t_pic *pic)
{
	pic->img = NULL;
	pic->width = 0;
	pic->height = 0;
}

void	init_color(t_color *color)
{
	color->path = NULL;
	color->hexa = NULL;
	color->r = 0;
	color->g = 0;
	color->b = 0;
}

void	init_texture(t_texture *img)
{
	img->wall_no = malloc(sizeof(t_pic));
	init_pic(img->wall_no);
	img->wall_so = malloc(sizeof(t_pic));
	init_pic(img->wall_so);
	img->wall_we = malloc(sizeof(t_pic));
	init_pic(img->wall_we);
	img->wall_ea = malloc(sizeof(t_pic));
	init_pic(img->wall_ea);
	img->floor = malloc(sizeof(t_color));
	init_color(img->floor);
	img->celling = malloc(sizeof(t_color));
	init_color(img->celling);
}
