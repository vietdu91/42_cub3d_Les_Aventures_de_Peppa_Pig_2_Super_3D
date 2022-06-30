/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:14:33 by dyoula            #+#    #+#             */
/*   Updated: 2022/06/30 18:30:43 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	find_width(char **map)
{
	int	i;
	int	j;
	int	max;

	i = -1;
	max = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (j > max)
				max = j;
		}
	}
	return (max);
}

int	size_map(t_data *data, int *x, int *y)
{
	int	len_max;
	int	direction;

	len_max = find_width(data->map->map);
	*x = MAP_WIDTH / len_max;
	*y = MAP_HEIGHT / size_dtab(data->map->map);
	direction = place_player(data, *x, *y);
	return (0);
}

float	to_radian(int degrees)
{
	return ((PI / 180) * degrees);
}
