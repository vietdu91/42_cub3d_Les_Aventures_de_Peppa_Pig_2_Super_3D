/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:40:02 by emtran            #+#    #+#             */
/*   Updated: 2022/07/13 18:11:06 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	is_it_an_id_in_file(t_data *data, char **file, char *id, int i)
{
	if (!ft_strncmp(file[i], id, 2))
	{
		if (!is_space(file[i][2]))
			print_error_pars_and_exit(ERR_ID, data);
		return (0);
	}
	return (-1);
}

int	check_good_path_wall(t_data *data, t_walls *walls, char *line_file, \
char *type)
{
	char	**split;

	split = NULL;
	split = ft_split_charset(line_file, SPACES);
	if (!split[1] || split[2])
	{
		free_d_tab(split);
		print_error_pars_and_exit(ERR_NB_ARG_WALLS, data);
	}
	put_wall_in_structure(walls, split, type);
	free_d_tab(split);
	return (0);
}

int	are_check_all_walls_is_ok(t_data *data, t_walls *walls)
{
	if (!walls->check_no || !walls->check_so || !walls->check_we || \
		!walls->check_ea)
		return (print_error_pars_and_exit(ERR_ID_MISS, data));
	return (0);
}

bool	inverse_bool_wall(bool check)
{
	if (!check)
		check = true;
	else
		check = false;
	return (check);
}

int	check_walls(t_data *data, char **file)
{
	int		i;

	i = 0;
	while (i < data->lines_file)
	{
		if (!is_it_an_id_in_file(data, file, "NO", i))
			data->map->walls->check_no = \
			inverse_bool_wall(data->map->walls->check_no);
		else if (!is_it_an_id_in_file(data, file, "SO", i))
			data->map->walls->check_so = \
			inverse_bool_wall(data->map->walls->check_so);
		else if (!is_it_an_id_in_file(data, file, "WE", i))
			data->map->walls->check_we = \
			inverse_bool_wall(data->map->walls->check_we);
		else if (!is_it_an_id_in_file(data, file, "EA", i))
			data->map->walls->check_ea = \
			inverse_bool_wall(data->map->walls->check_ea);
		i++;
	}
	are_check_all_walls_is_ok(data, data->map->walls);
	collect_walls(data, file);
	return (0);
}
