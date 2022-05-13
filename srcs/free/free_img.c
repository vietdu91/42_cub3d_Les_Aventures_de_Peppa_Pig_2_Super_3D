/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:55:47 by emtran            #+#    #+#             */
/*   Updated: 2022/05/13 14:41:50 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	free_img(t_game *game, t_img *img)
{
	if (img->wall_no->img)
		mlx_destroy_image(game->mlx_ptr, img->wall_no->img);
	if (img->wall_no)
		free(img->wall_no);
	if (img->wall_so->img)
		mlx_destroy_image(game->mlx_ptr, img->wall_so->img);
	if (img->wall_so)
		free(img->wall_so);
	if (img->wall_we->img)
		mlx_destroy_image(game->mlx_ptr, img->wall_we->img);
	if (img->wall_we)
		free(img->wall_we);
	if (img->wall_ea->img)
		mlx_destroy_image(game->mlx_ptr, img->wall_ea->img);
	if (img->wall_ea)
		free(img->wall_ea);
	if (img)
		free(img);
}
