/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:15:50 by dyoula            #+#    #+#             */
/*   Updated: 2022/06/26 20:17:51 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	verLine(t_data *data, int x, int y1, int y2, int color)
{
	int	y;

	y = 0;
	while (y <= y1)
	{
		mlx_pixel_put(data->game->mlx_ptr, data->game->win_ptr, x, y, \
		data->game->texture->celling->hexa);
		y++;
	}
	while (y <= y2)
	{
		mlx_pixel_put(data->game->mlx_ptr, data->game->win_ptr, x, y, color);
		y++;
	}
	while (y <= WINDOW_GAME)
	{
		mlx_pixel_put(data->game->mlx_ptr, data->game->win_ptr, x, y, \
		data->game->texture->floor->hexa);
		y++;
	}
}
