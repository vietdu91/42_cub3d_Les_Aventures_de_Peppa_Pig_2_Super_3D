/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:40:37 by emtran            #+#    #+#             */
/*   Updated: 2022/07/13 18:11:25 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	second_check_map_is_close(t_data *data, char **map)
{
	int	y;

	y = 0;
	while (map[++y])
	{
		if (has_str_only_spaces(map[y]))
			if (!has_str_only_walls(map[y - 1]) || \
			!has_str_only_walls(map[y + 1]))
				print_error_pars_and_exit(ERR_MAP_CLOSE, data);
	}
	return (0);
}

int	check_map_is_close(t_data *data, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[++y])
	{
		x = 0;
		while (map[y][++x])
		{
			if (is_good_value(map[y][x]))
			{
				if (is_space(map[y - 1][x]) || is_space(map[y + 1][x])
				|| is_space(map[y][x - 1]) || is_space(map[y][x + 1]))
					print_error_pars_and_exit(ERR_MAP_CLOSE, data);
				zero_is_not_in_void(data, y, x, map);
			}
		}
	}
	second_check_map_is_close(data, map);
	return (0);
}

int	check_letters_of_map(t_data *data, char **map)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (!is_good_value_and_walls(map[y][x]))
				print_error_pars_and_exit(ERR_CHAR, data);
	}
	return (0);
}

int	check_first_and_last_letters_of_line(t_data *data, char **map)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = ft_strlen(map[y]);
		if (x > 0)
			x = x - 1;
		while (is_space(map[y][x]))
			x--;
		if (map[y][x] != '1' && !is_space(map[y][x]) && map[y][x] != '\0')
			print_error_pars_and_exit(ERR_MAP_CLOSE, data);
	}
	y = -1;
	while (map[++y])
	{
		x = 0;
		while (is_space(map[y][x]))
			x++;
		if (map[y][x] != '1' && !is_space(map[y][x]) && map[y][x] != '\0')
			print_error_pars_and_exit(ERR_MAP_CLOSE, data);
	}
	return (0);
}

int	check_map(t_data *data, t_map *map)
{
	collect_map(data, map);
	check_first_and_last_letters_of_line(data, map->map);
	check_letters_of_map(data, map->map);
	check_position_of_peppa(data, data->game->peppa, map->map);
	check_map_is_close(data, map->map);
	return (0);
}
