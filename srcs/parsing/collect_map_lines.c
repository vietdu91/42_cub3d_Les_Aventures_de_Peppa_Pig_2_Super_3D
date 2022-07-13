/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_map_lines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:17:38 by emtran            #+#    #+#             */
/*   Updated: 2022/07/13 15:16:29 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	collect_max_width_map(t_data *data, t_map *map, int first, int last)
{
	int	i;

	i = first;
	while (i <= last)
	{
		if (ft_strlen(data->file[i]) > map->max_len_map)
			map->max_len_map = ft_strlen(data->file[i]);
		i++;
	}
	return (0);
}

int	collect_gap_of_first_and_last_line(t_data *data, int first, int last)
{
	data->map->lines_map = (last + 1) - first;
	if (data->map->lines_map < 3)
		print_error_pars_and_exit(ERR_MAP_TOO_STRONG, data);
	return (0);
}

int	check_line_is_infos(char *line)
{
	if (!ft_strncmp(line, "NO", 2))
		return (0);
	else if (!ft_strncmp(line, "EA", 2))
		return (0);
	else if (!ft_strncmp(line, "SO", 2))
		return (0);
	else if (!ft_strncmp(line, "WE", 2))
		return (0);
	else if (!ft_strncmp(line, "C", 1))
		return (0);
	else if (!ft_strncmp(line, "F", 1))
		return (0);
	return (1);
}

int	collect_first_line_map(t_data *data, t_map *map, char **file)
{
	int	a;

	a = -1;
	while (++a <= data->lines_file)
	{
		if (!file[a])
			print_error_pars_and_exit(ERR_MAP, data);
		if (!check_line_is_infos(file[a]))
			continue ;
		if (!check_line_is_empty(file[a]))
			continue ;
		else if (!check_one_delimiter_line_of_map(file[a]))
		{
			map->first_line = a;
			return (0);
		}
		else
			print_error_pars_and_exit(ERR_MAP_FIRST_LINE, data);
	}
	return (0);
}

int	collect_last_line_map(t_data *data, t_map *map, char **file)
{
	int	a;

	a = data->lines_file;
	while (--a >= 0)
	{
		if (!check_line_is_empty(file[a]))
			continue ;
		else if (!check_one_delimiter_line_of_map(file[a]))
		{
			map->last_line = a;
			return (0);
		}
		else
			print_error_pars_and_exit(ERR_MAP_LAST_LINE, data);
	}
	return (0);
}
