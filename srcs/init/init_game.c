/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:08:08 by emtran            #+#    #+#             */
/*   Updated: 2022/07/12 20:04:45 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	init_mlx_and_window(t_data *data, t_game *game, t_win *window)
{
	(void) data;
	window->win_height = WINDOW_HEIGHT;
	window->win_width = WINDOW_WIDTH;
	game->win_ptr = mlx_new_window(game->mlx_ptr, window->win_width, \
	window->win_height, "CUB3D SA MERE LA PUTA");
	if (game->win_ptr == NULL)
		return (-1);
	return (0);
}

void	init_overlays(t_data *data, t_game *game)
{
	game->overlay_happy = malloc(sizeof(t_pic));
	init_pic(game->overlay_happy);
	if (!game->overlay_happy)
		print_error_and_exit(ERR_MALLOC, data);
	game->overlay_scared = malloc(sizeof(t_pic));
	init_pic(game->overlay_scared);
	if (!game->overlay_scared)
		print_error_and_exit(ERR_MALLOC, data);
	game->overlay_panic = malloc(sizeof(t_pic));
	init_pic(game->overlay_panic);
	if (!game->overlay_panic)
		print_error_and_exit(ERR_MALLOC, data);
}

void	init_pics(t_data *data, t_game *game)
{
	game->intro = malloc(sizeof(t_pic));
	init_pic(game->intro);
	if (!game->intro)
		print_error_and_exit(ERR_MALLOC, data);
	game->credit = malloc(sizeof(t_pic));
	init_pic(game->credit);
	if (!game->credit)
		print_error_and_exit(ERR_MALLOC, data);
	game->game_over = malloc(sizeof(t_pic));
	init_pic(game->game_over);
	if (!game->game_over)
		print_error_and_exit(ERR_MALLOC, data);
	game->dylan_the_butcher = malloc(sizeof(t_img));
	init_img(game->dylan_the_butcher);
	if (!game->dylan_the_butcher)
		print_error_and_exit(ERR_MALLOC, data);
	init_overlays(data, data->game);
}

void	init_struct_game(t_data *data, t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->step_of_game = 0;
	game->good_or_bad = true;
	game->screen = NULL;
	game->screen = malloc(sizeof(t_img));
	if (!game->screen)
		print_error_and_exit(ERR_MALLOC, data);
	init_img(game->screen);
	if (!game->screen)
		print_error_and_exit(ERR_MALLOC, data);
	init_pics(data, game);
	init_texture(data, game->texture);
	init_struct_peppa(game->peppa);
}
