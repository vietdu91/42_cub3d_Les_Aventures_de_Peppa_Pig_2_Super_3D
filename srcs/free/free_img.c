/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:55:47 by emtran            #+#    #+#             */
/*   Updated: 2022/07/03 17:23:08 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	destroy_walls(t_data *data, t_texture *text)
{
	mlx_destroy_image(data->game->mlx_ptr, text->wall_no->mlx_img);
	mlx_destroy_image(data->game->mlx_ptr, text->wall_so->mlx_img);
	mlx_destroy_image(data->game->mlx_ptr, text->wall_we->mlx_img);
	mlx_destroy_image(data->game->mlx_ptr, text->wall_ea->mlx_img);
}

void	free_img(t_game *game, t_img *img)
{
	if (img->mlx_img)
		mlx_destroy_image(game->mlx_ptr, img->mlx_img);
	if (img)
		free(img);
}

void	free_color(t_color *color)
{
	if (color->path)
		free(color->path);
	if (color)
		free(color);
}

void	free_texture(t_game *game, t_texture *texture)
{
	if (texture->floor)
		free_color(texture->floor);
	if (texture->celling)
		free_color(texture->celling);
	if (game->step_of_game >= 3)
	{
		if (texture->wall_no->mlx_img)
			mlx_destroy_image(game->mlx_ptr, texture->wall_no->mlx_img);
		if (texture->wall_so->mlx_img)
			mlx_destroy_image(game->mlx_ptr, texture->wall_so->mlx_img);
		if (texture->wall_we->mlx_img)
			mlx_destroy_image(game->mlx_ptr, texture->wall_we->mlx_img);
		if (texture->wall_ea->mlx_img)
			mlx_destroy_image(game->mlx_ptr, texture->wall_ea->mlx_img);
	}
	if (texture->wall_no)
		free(texture->wall_no);
	if (texture->wall_so)
		free(texture->wall_so);
	if (texture->wall_we)
		free(texture->wall_we);
	if (texture->wall_ea)
		free(texture->wall_ea);
	if (texture)
		free(texture);
}
