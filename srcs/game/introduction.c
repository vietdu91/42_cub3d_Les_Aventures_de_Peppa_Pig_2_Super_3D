/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introduction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:19:13 by emtran            #+#    #+#             */
/*   Updated: 2022/07/02 19:09:19 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	introduction_of_game(t_data *data, t_game *game)
{
	game->step_of_game = 1;
	mlx_key_hook(data->game->win_ptr, &key_press, data);
	mlx_hook(game->win_ptr, 33, 131072, &free_all_and_exit, data);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->intro->img, 0, 0);
	mlx_loop(game->mlx_ptr);
}

void	credit_of_game(t_data *data, t_game *game)
{
	game->step_of_game = 2;
	mlx_key_hook(data->game->win_ptr, &key_press, data);
	mlx_hook(game->win_ptr, 33, 131072, &free_all_and_exit, data);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->credit->img, 0, 0);
	mlx_loop(game->mlx_ptr);
}

