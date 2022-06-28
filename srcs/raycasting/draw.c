/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:15:50 by dyoula            #+#    #+#             */
/*   Updated: 2022/06/28 19:40:52 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	verLine(t_data *data, int x, int y1, int y2, int color)
{
	int	y;

	y = 0;
	if (data->game->peppa->pos_peppa == 'S' || \
		data->game->peppa->pos_peppa == 'W')
		x = WINDOW_WIDTH - x - 1;
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
