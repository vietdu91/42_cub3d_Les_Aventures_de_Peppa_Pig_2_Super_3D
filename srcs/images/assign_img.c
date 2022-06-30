/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 10:33:08 by emtran            #+#    #+#             */
/*   Updated: 2022/06/30 11:17:17 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	assign_img_overlay(t_data *data, t_game *game)
{
	game->overlay_happy->img = mlx_xpm_file_to_image(game->mlx_ptr, \
	OVERLAY_HAPPY, &game->overlay_happy->width, &game->overlay_happy->height);
	if (!game->overlay_happy->img)
		free_all_and_exit(data);
	game->overlay_scared->img = mlx_xpm_file_to_image(game->mlx_ptr, \
	OVERLAY_SCARED, &game->overlay_scared->width, \
	&game->overlay_scared->height);
	if (!game->overlay_scared->img)
		free_all_and_exit(data);
	game->overlay_panic->img = mlx_xpm_file_to_image(game->mlx_ptr, \
	OVERLAY_PANIC, &game->overlay_panic->width, &game->overlay_panic->height);
	if (!game->overlay_panic->img)
		free_all_and_exit(data);
}

void	assign_img_intro(t_data *data, t_game *game)
{
	game->intro->img = mlx_xpm_file_to_image(game->mlx_ptr, INTRO, \
	&game->intro->width, &game->intro->height);
	if (!game->intro->img)
		free_all_and_exit(data);
	game->credit->img = mlx_xpm_file_to_image(game->mlx_ptr, CREDIT, \
	&game->credit->width, &game->credit->height);
	if (!game->credit->img)
		free_all_and_exit(data);
	game->game_over->img = mlx_xpm_file_to_image(game->mlx_ptr, GAMEOVER, \
	&game->game_over->width, &game->game_over->height);
	if (!game->game_over->img)
		free_all_and_exit(data);
	game->dylan_the_butcher->img = mlx_xpm_file_to_image(game->mlx_ptr, \
	BUTCHER, &game->dylan_the_butcher->width, \
	&game->dylan_the_butcher->height);
	if (!game->dylan_the_butcher->img)
		free_all_and_exit(data);
}
