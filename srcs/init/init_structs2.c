/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:51:21 by emtran            #+#    #+#             */
/*   Updated: 2022/05/13 14:19:41 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_pic(t_pic *pic)
{
	pic->img = NULL;
	pic->width = 0;
	pic->height = 0;
}

void	init_img(t_img *img)
{
	img->wall_no = malloc(sizeof(t_pic));
	init_pic(img->wall_no);
	img->wall_so = malloc(sizeof(t_pic));
	init_pic(img->wall_so);
	img->wall_we = malloc(sizeof(t_pic));
	init_pic(img->wall_we);
	img->wall_ea = malloc(sizeof(t_pic));
	init_pic(img->wall_ea);
}
