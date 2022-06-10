/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:12:07 by dyoula            #+#    #+#             */
/*   Updated: 2022/06/10 21:58:57 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	move_player(t_data *data, t_img *img, int key)
{
	draw_player(data, data->game->p1->posX, data->game->p1->posY, BLACK);
	if (key == KEY_W)
	{
		data->game->p1->posY - 0.1;
		draw_player(data, data->game->p1->posX, data->game->p1->posY, RED);
	}
}
