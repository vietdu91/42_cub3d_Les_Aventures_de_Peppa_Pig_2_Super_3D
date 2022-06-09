/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:55:47 by emtran            #+#    #+#             */
/*   Updated: 2022/06/09 17:18:58 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	free_color(t_color *color)
{
	if (color->path)
		free(color->path);
	if (color->hexa)
		free(color->hexa);
	if (color)
		free(color);
}

void	free_img(t_game *game, t_texture *img)
{
	if (img->floor)
		free_color(img->floor);
	if (img->celling)
		free_color(img->celling);
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
