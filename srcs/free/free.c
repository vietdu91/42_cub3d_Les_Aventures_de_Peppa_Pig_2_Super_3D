/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:39:39 by emtran            #+#    #+#             */
/*   Updated: 2022/05/09 14:37:58 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	free_d_tab(char **tb)
{
	int	i;

	i = -1;
	if (!tb)
		return ;
	while (tb[++i])
	{
		if (tb[i])
			free(tb[i]);
	}
	free(tb);
	tb = NULL;
}

void	free_game_and_mlx(t_game *game)
{
	// fonction qui destroy les imgs
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
}

int	free_all(t_data *data)
{
	free_game_and_mlx(data->game);
	if (data->game)
		free(data->game);
	if (data)
		free(data);
	return (0);
}

int	free_all_and_exit(t_data *data)
{
	free_game_and_mlx(data->game);
	if (data->game)
		free(data->game);
	if (data)
		free(data);
	exit(EXIT_SUCCESS);
}
