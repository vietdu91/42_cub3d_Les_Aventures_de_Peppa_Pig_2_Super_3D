/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:12:07 by dyoula            #+#    #+#             */
/*   Updated: 2022/06/28 14:11:09 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// void	w_key(t_data *data)
// {
// 	if (data->map->map[(int)(data->game->p1->posY)][(int)(data->game->p1->posX + data->game->p1->dirX * data->game->p1->moveSpeed)] != '1')
// 		data->game->p1->posX += data->game->p1->dirX * data->game->p1->moveSpeed;
// 	if (data->map->map[(int)(data->game->p1->posY + data->game->p1->dirY * data->game->p1->moveSpeed)][(int)(data->game->p1->posX)] != '1')
// 		data->game->p1->posY += data->game->p1->dirY * data->game->p1->moveSpeed;
// }

// void	s_key(t_data *data)
// {
// 	if (data->map->map[(int)(data->game->p1->posY)][(int)(data->game->p1->posX - data->game->p1->dirX * data->game->p1->moveSpeed)] != '1')
// 		data->game->p1->posX -= data->game->p1->dirX * data->game->p1->moveSpeed;
// 	if (data->map->map[(int)(data->game->p1->posY - data->game->p1->dirY * data->game->p1->moveSpeed)][(int)(data->game->p1->posX)] != '1')
// 		data->game->p1->posY -= data->game->p1->dirY * data->game->p1->moveSpeed;
// }

// void	a_key(t_data *data)
// {
// 	if (data->map->map[(int)(data->game->p1->posY)][(int)(data->game->p1->posX + data->game->p1->dirX * data->game->p1->moveSpeed)] != '1')
// 		data->game->p1->posX += data->game->p1->dirY * data->game->p1->moveSpeed;
// 	if (data->map->map[(int)(data->game->p1->posY + data->game->p1->dirY * data->game->p1->moveSpeed)][(int)(data->game->p1->posX)] != '1')
// 		data->game->p1->posY -= data->game->p1->dirX * data->game->p1->moveSpeed;
// }

// void	d_key(t_data *data)
// {
// 	if (data->map->map[(int)(data->game->p1->posY)][(int)(data->game->p1->posX + data->game->p1->dirX * data->game->p1->moveSpeed)] != '1')
// 		data->game->p1->posX -= data->game->p1->dirY * data->game->p1->moveSpeed;
// 	if (data->map->map[(int)(data->game->p1->posY + data->game->p1->dirY * data->game->p1->moveSpeed)][(int)(data->game->p1->posX)] != '1')
// 		data->game->p1->posY += data->game->p1->dirX * data->game->p1->moveSpeed;
// }
