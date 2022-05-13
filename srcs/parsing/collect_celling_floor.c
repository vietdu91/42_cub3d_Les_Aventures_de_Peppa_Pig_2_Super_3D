/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_celling_floor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:06:26 by emtran            #+#    #+#             */
/*   Updated: 2022/05/13 16:38:06 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	collect_celling_floor(t_data *data, char **file)
{
	int	i;

	i = 0;
	while (i < data->lines_file)
	{
		if (!is_it_an_id_in_file(data, file, "C", i))
			check_good_path_floor(data, data->map->floor, file[i], "C");
		if (!is_it_an_id_in_file(data, file, "F", i))
			check_good_path_floor(data, data->map->floor, file[i], "F");
		i++;
	}
	return (0);
}

int	put_floor_celling_in_structure(t_floor *floor, char **split, char *type)
{
	if (!ft_strcmp("C", type))
		floor->path_celling = ft_strdup(split[1]);
	else if (!ft_strcmp("F", type))
		floor->path_floor = ft_strdup(split[1]);
	return (0);
}
