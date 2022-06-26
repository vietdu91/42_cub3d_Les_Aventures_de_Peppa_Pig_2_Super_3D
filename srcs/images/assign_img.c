/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 10:33:08 by emtran            #+#    #+#             */
/*   Updated: 2022/06/26 16:18:03 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	assign_img_overlay(t_data *data, t_game *game)
{
	game->overlay_happy->img = mlx_xpm_file_to_image(game->mlx_ptr, OVERLAY_HAPPY, \
	&game->overlay_happy->width, &game->overlay_happy->height);
	if (!game->overlay_happy->img)
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
	if (!game->intro->img)
		free_all_and_exit(data);
}
