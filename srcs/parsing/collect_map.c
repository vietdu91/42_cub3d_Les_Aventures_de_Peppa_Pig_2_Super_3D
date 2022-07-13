/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:05:36 by emtran            #+#    #+#             */
/*   Updated: 2022/07/13 15:16:36 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	**save_map(t_data *data, t_map *map)
{
	char	**mappy;
	int		i;

	mappy = ft_calloc(map->lines_map + 1, sizeof(char *));
	if (!mappy)
		return (NULL);
	i = 0;
	while (i < map->lines_map)
	{
		mappy[i] = ft_calloc(map->max_len_map + 1, sizeof(char));
		if (!mappy[i])
			print_error_pars_and_exit(ERR_MALLOC, data);
		i++;
	}
	mappy[i] = 0;
	return (mappy);
}

int	collect_map(t_data *data, t_map *map)
{
	int	i;
	int	j;
	int	k;

	collect_first_line_map(data, map, data->file);
	collect_last_line_map(data, map, data->file);
	collect_gap_of_first_and_last_line(data, map->first_line, map->last_line);
	collect_max_width_map(data, map, map->first_line, map->last_line);
	map->map = save_map(data, map);
	i = map->first_line;
	if (!map->map)
		return (print_error_pars_and_exit(ERR_MAP, data));
	k = 0;
	while (i <= map->last_line)
	{
		j = 0;
		while (j < ft_strlen(data->file[i]))
		{
			map->map[k][j] = data->file[i][j];
			j++;
		}
		i++;
		k++;
	}
	return (0);
}
