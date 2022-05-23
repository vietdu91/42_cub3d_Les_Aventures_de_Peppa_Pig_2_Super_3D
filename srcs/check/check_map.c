/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:40:37 by emtran            #+#    #+#             */
/*   Updated: 2022/05/23 17:49:19 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_first_and_last_letters_of_line(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	while(map[i])
	{
		j = ft_strlen(map[i]) - 1;
		while (is_space(map[i][j]))
			j--;
		if (map[i][j] != '1')
			print_error_and_exit(ERR_MAP_CLOSE, data);
		i++;
	}
	i = 0;
	while(map[i])
	{
		j = 0;
		while (is_space(map[i][j]))
			j++;
		if (map[i][j] != '1')
			print_error_and_exit(ERR_MAP_CLOSE, data);
		i++;
	}
	return (0);
}

int	check_map(t_data *data, t_map *map)
{
	collect_map(data, map);
	check_first_and_last_letters_of_line(data, map->map);
	return (0);
}