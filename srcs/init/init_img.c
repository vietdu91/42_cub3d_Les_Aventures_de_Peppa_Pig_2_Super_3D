/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:39:42 by dyoula            #+#    #+#             */
/*   Updated: 2022/06/09 18:15:46 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	init_img(t_data *data)
{
	data->img->mlx_img = NULL;
	data->img->addr = NULL;
	data->img->bpp = 0;
	data->img->line_len = 0;
	data->img->endian = 0;
	return (0);
}
