/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_celling_floor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:28:40 by emtran            #+#    #+#             */
/*   Updated: 2022/07/13 15:17:13 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	is_it_an_id_celling_floor_in_file(t_data *data, char **file, char *id, \
int i)
{
	if (!ft_strncmp(file[i], id, 1))
	{
		if (!is_space(file[i][1]))
			print_error_pars_and_exit(ERR_ID_FC, data);
		return (0);
	}
	return (-1);
}

int	check_path_arg_color_is_good(t_data *data, char *line_file, char **split)
{
	int	len;

	len = ft_strlen(line_file);
	if (line_file[len - 1] == ',')
	{
		free_d_tab(split);
		print_error_pars_and_exit(ERR_NB_ARG_COLOR, data);
	}
	return (0);
}

int	check_good_path_floor(t_data *data, t_color *color, char *line_file, \
char *type)
{
	char	**split;

	split = NULL;
	split = ft_split_charset(line_file, SPACES);
	check_path_arg_color_is_good(data, line_file, split);
	if (!split[1] || split[2])
	{
		free_d_tab(split);
		print_error_pars_and_exit(ERR_NB_ARG_COLOR, data);
	}
	if (!ft_strcmp(type, "C"))
		color->path = ft_strdup(split[1]);
	else if (!ft_strcmp(type, "F"))
		color->path = ft_strdup(split[1]);
	free_d_tab(split);
	collect_rgb(data, color);
	return (0);
}

int	are_check_all_floor_celling_is_ok(t_data *data, t_floor *floor)
{
	if (!floor->check_floor || !floor->check_celling)
		return (print_error_pars_and_exit(ERR_ID_FC_MISS, data));
	return (0);
}

int	check_celling_floor(t_data *data, char **file)
{
	int	i;

	i = 0;
	while (i < data->lines_file)
	{
		if (!is_it_an_id_celling_floor_in_file(data, file, "C", i))
			data->map->floor->check_floor = true;
		else if (!is_it_an_id_celling_floor_in_file(data, file, "F", i))
			data->map->floor->check_celling = true;
		i++;
	}
	are_check_all_floor_celling_is_ok(data, data->map->floor);
	collect_celling_floor(data, file);
	return (0);
}
