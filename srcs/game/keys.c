/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:39:21 by emtran            #+#    #+#             */
/*   Updated: 2022/06/10 21:44:52 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	move_player(t_data *data, int key)
{
	draw_player(data,data->game->p1->posX, data->game->p1->posY, BLACK);
	if (key == KEY_W)
	{
		data->game->p1->posY -= 2;
		draw_player(data,data->game->p1->posX, data->game->p1->posY, RED);
	}
	else if (key == KEY_S)
	{
		data->game->p1->posY -= -2;
		draw_player(data,data->game->p1->posX, data->game->p1->posY, RED);
	}
	else if (key == KEY_A)
	{
		data->game->p1->posX -= 2;
		draw_player(data,data->game->p1->posX, data->game->p1->posY, RED);
	}
	else if (key == KEY_D)
	{
		data->game->p1->posX += 2;
		draw_player(data,data->game->p1->posX, data->game->p1->posY, RED);
	}
	return (0);
}

int	keys_main(int key_code, t_data *data)
{
	if (key_code == ESC)
		free_all_and_exit(data);
	else if (key_code == KEY_W)
	{
		move_player(data, key_code);
	}
	else if (key_code == KEY_S)
	{
		move_player(data, key_code);
	}
	else if (key_code == KEY_A)
	{
		move_player(data, key_code);
	}
	else if (key_code == KEY_D)
	{
		move_player(data, key_code);
	}
	return (0);
}
