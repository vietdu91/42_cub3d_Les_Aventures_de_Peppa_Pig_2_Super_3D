/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:39:39 by emtran            #+#    #+#             */
/*   Updated: 2022/05/13 13:59:48 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	free_all(t_data *data)
{
	free_maps(data->map);
	free_img(data->game, data->game->img);
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
	free_maps(data->map);
	free_img(data->game, data->game->img);
	free_game_and_mlx(data->game);
	if (data->game)
		free(data->game);
	if (data->file)
		free_d_tab(data->file);
	if (data)
		free(data);
	exit(EXIT_SUCCESS);
}
