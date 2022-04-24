/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:35:10 by emtran            #+#    #+#             */
/*   Updated: 2022/04/24 15:10:31 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_data(t_data *data)
{
	data->lines = 0;
	data->win.win_width = 0;
	data->win.win_height = 0;
}

void	init_game(t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
}

t_data	*init_struct(t_data *data)
{
	data = malloc(sizeof(t_data));
	data->game = malloc(sizeof(t_game));
	if (!data || !data->game)
		print_error_and_exit(ERR_MALLOC, data);
	init_data(data);
	init_game(data->game);
	return (data);
}
