/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:51:21 by emtran            #+#    #+#             */
/*   Updated: 2022/06/30 12:07:17 by emtran           ###   ########.fr       */
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
	color->hexa = 0;
	color->r = 0;
	color->g = 0;
	color->b = 0;
}
