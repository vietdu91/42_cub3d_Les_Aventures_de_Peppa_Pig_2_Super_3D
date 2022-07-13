/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_celling_floor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:06:26 by emtran            #+#    #+#             */
/*   Updated: 2022/07/13 15:15:59 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	collect_celling_floor(t_data *data, char **file)
{
	int	i;

	i = 0;
	while (i < data->lines_file)
	{
		if (!is_it_an_id_celling_floor_in_file(data, file, "C", i))
			check_good_path_floor(data, data->game->texture->celling, \
			file[i], "C");
		else if (!is_it_an_id_celling_floor_in_file(data, file, "F", i))
			check_good_path_floor(data, data->game->texture->floor, \
			file[i], "F");
		i++;
	}
	return (0);
}

int	check_collect_rgb_is_good(t_data *data, char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if (!is_digit(split[i][j]))
			{
				free_d_tab(split);
				print_error_pars_and_exit(ERR_NB_ARG_COLOR, data);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	collect_rgb(t_data *data, t_color *color)
{
	char	**split;

	split = NULL;
	split = ft_split(color->path, ',');
	check_collect_rgb_is_good(data, split);
	if (!split[0] || !split[1] || !split[2] || split[3])
	{
		free_d_tab(split);
		print_error_pars_and_exit(ERR_NB_NB_COLOR, data);
	}
	color->r = ft_atoi(split[0]);
	color->g = ft_atoi(split[1]);
	color->b = ft_atoi(split[2]);
	color->hexa = ft_rgb_to_hex(color->r, color->g, color->b);
	if (color->hexa == -1)
	{
		free_d_tab(split);
		print_error_pars_and_exit(ERR_COLOR, data);
	}
	free_d_tab(split);
	return (0);
}
