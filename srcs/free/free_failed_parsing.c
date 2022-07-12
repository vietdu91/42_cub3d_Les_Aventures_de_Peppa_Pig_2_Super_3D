/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_failed_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:46:44 by dyoula            #+#    #+#             */
/*   Updated: 2022/07/12 20:04:22 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	check_parsing(char **argv, t_data *data)
{
	if (check_extension_cub(argv[1], data))
		return (1);
	if (check_file(argv, data))
		return (1);
	if (check_map(data, data->map))
		return (1);
	return (0);
}

void	free_forest(t_data *data)
{
	free_sprites(data->sprites);
	free_maps(data->map);
	free_texture(data->game, data->game->texture);
	free_pics(data->game, data->game->intro);
	free_pics(data->game, data->game->credit);
	free_pics(data->game, data->game->game_over);
	if (data->game->dylan_the_butcher)
		free(data->game->dylan_the_butcher);
	free_pics(data->game, data->game->overlay_happy);
	free_pics(data->game, data->game->overlay_scared);
	free_pics(data->game, data->game->overlay_panic);
}

int	free_parsing_failed(t_data *data)
{
	free_forest(data);
	if (data->game->peppa)
		free(data->game->peppa);
	if (data->game->p1)
		free(data->game->p1);
	if (data->game->screen)
		free(data->game->screen);
	mlx_destroy_display(data->game->mlx_ptr);
	free(data->game->mlx_ptr);
	if (data->game)
		free(data->game);
	if (data->file)
		free_d_tab(data->file);
	if (data->img)
		free(data->img);
	if (data)
		free(data);
	return (1);
}
