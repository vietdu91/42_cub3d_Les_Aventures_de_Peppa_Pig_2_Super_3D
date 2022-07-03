/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 10:33:08 by emtran            #+#    #+#             */
/*   Updated: 2022/07/03 17:12:24 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	assign_img_overlay(t_data *data, t_game *game)
{
	game->overlay_happy->img = mlx_xpm_file_to_image(game->mlx_ptr, \
	OVERLAY_HAPPY, &game->overlay_happy->width, &game->overlay_happy->height);
	if (!game->overlay_happy->img)
		print_error_and_exit(ERR_MLC_IMG, data);
	game->overlay_scared->img = mlx_xpm_file_to_image(game->mlx_ptr, \
	OVERLAY_SCARED, &game->overlay_scared->width, \
	&game->overlay_scared->height);
	if (!game->overlay_scared->img)
		print_error_and_exit(ERR_MLC_IMG, data);
	game->overlay_panic->img = mlx_xpm_file_to_image(game->mlx_ptr, \
	OVERLAY_PANIC, &game->overlay_panic->width, &game->overlay_panic->height);
	if (!game->overlay_panic->img)
		print_error_and_exit(ERR_MLC_IMG, data);
}

void	assign_butcher(t_data *data, t_game *game, t_sprites *sprites)
{
	int	x;
	int	y;

	y = 0;
	put_img_wall_to_mlx(data, BUTCHER, game->dylan_the_butcher);
	if (!game->dylan_the_butcher)
		print_error_and_exit(ERR_MLC_IMG, data);
// 	while (y < game->dylan_the_butcher->width)
// 	{
// 		x = 0;
// 		while (x < game->dylan_the_butcher->height)
// 		{
// 			sprites->tex[SPRITE_H * y + x] = \
// 			game->dylan_the_butcher->addr[SPRITE_H * y + x];
// 			x++;
// 		}
// 		y++;
// 	}
	while (y < game->dylan_the_butcher->width)
	{
		x = 0;
		while (x < game->dylan_the_butcher->height)
		{
			sprites->tex[SPRITE_H * y + x] = \
			game->dylan_the_butcher->addr[SPRITE_H * y + x];
			x++;
		}
		y++;
	}
}

void	assign_img_intro(t_data *data, t_game *game)
{
	game->intro->img = mlx_xpm_file_to_image(game->mlx_ptr, INTRO, \
	&game->intro->width, &game->intro->height);
	if (!game->intro->img)
		print_error_and_exit(ERR_MLC_IMG, data);
	game->credit->img = mlx_xpm_file_to_image(game->mlx_ptr, CREDIT, \
	&game->credit->width, &game->credit->height);
	if (!game->credit->img)
		print_error_and_exit(ERR_MLC_IMG, data);
	game->game_over->img = mlx_xpm_file_to_image(game->mlx_ptr, GAMEOVER, \
	&game->game_over->width, &game->game_over->height);
	if (!game->game_over->img)
		print_error_and_exit(ERR_MLC_IMG, data);
	assign_butcher(data, game, data->sprites);
}
