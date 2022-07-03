/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 19:45:30 by dyoula            #+#    #+#             */
/*   Updated: 2022/07/03 19:45:29 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	player_first_location(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (0);
	return (-1);
}

void	find_player(t_data *data, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (player_first_location(data->map->map[i][j]) == 0)
			{
				*x = j;
				*y = i;
			}
			j++;
		}
		i++;
	}
}
