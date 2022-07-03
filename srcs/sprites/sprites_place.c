/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:09:04 by emtran            #+#    #+#             */
/*   Updated: 2022/07/03 20:09:44 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	sort_sprites_from_far(t_sprites *sprites, t_player *p1)
{
	sprites->sprite_distance = ((p1->posX - sprites->x) * \
	(p1->posX - sprites->x) + (p1->posY - sprites->y) * \
	(p1->posY - sprites->y));
	return (0);
}

int	first_zero_of_map(t_map *map, t_sprites *sprites)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->lines_map)
	{
		j = 0;
		while (j < map->max_len_map)
		{
			if (map->map[i][j] == '0')
			{
				sprites->x = j;
				sprites->y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	last_zero_of_map(t_map *map, t_sprites *sprites)
{
	int	i;
	int	j;

	i = map->lines_map - 1;
	while (i >= 0)
	{
		j = map->max_len_map - 1;
		while (j >= 0)
		{
			if (map->map[i][j] == '0')
			{
				sprites->x = j;
				sprites->y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	assign_place_of_butcher(t_data *data, t_sprites *sprites, t_player *p1)
{
	if ((p1->posX >= (data->map->max_len_map / 4)) && \
	(p1->posY >= (data->map->lines_map / 4)))
		last_zero_of_map(data->map, sprites);
	else
		first_zero_of_map(data->map, sprites);
	return (0);
}

