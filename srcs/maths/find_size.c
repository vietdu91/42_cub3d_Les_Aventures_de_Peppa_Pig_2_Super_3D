/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:14:33 by dyoula            #+#    #+#             */
/*   Updated: 2022/06/10 21:51:27 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// map to image

// width * 4 ici 600 => 2400

// line len == amount of bytes taken by one line our image 
// image_width * (bpp / 8);
// 
// 2400 * 10  + (5 index la ligne * 4 (nbr pixel))
// du coup len = len * 4 + (line * 4); 
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

	len_max = find_width(data->map->map);
	*x = MAP_WIDTH / len_max;
	*y = MAP_HEIGHT / size_dtab(data->map->map);
    printf("x = %d et y = %d\n", *x, *y);
	draw_map(data, *x, *y);
	place_player(data, *x, *y);
	return (0);
}
