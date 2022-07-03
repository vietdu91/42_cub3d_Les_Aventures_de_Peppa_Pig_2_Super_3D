/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:39:39 by emtran            #+#    #+#             */
/*   Updated: 2022/07/03 17:25:24 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	free_all(t_data *data)
{
	free_sprites(data->sprites);
	free_maps(data->map);
	free_texture(data->game, data->game->texture);
	free_img(data->game, data->img);
	free_game_and_mlx(data->game);
	if (data->game)
		free(data->game);
	if (data->file)
		free_d_tab(data->file);
	if (data)
		free(data);
	return (0);
}

int	free_all_and_exit(t_data *data)
{
	free_sprites(data->sprites);
	free_maps(data->map);
	free_texture(data->game, data->game->texture);
	if (data->game->step_of_game >= 3)
		free_img(data->game, data->img);
	else
		free(data->img);
	free_game_and_mlx(data->game);
	if (data->game)
		free(data->game);
	if (data->file)
		free_d_tab(data->file);
	if (data)
		free(data);
	exit(EXIT_SUCCESS);
}
