/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order_in_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:04:46 by emtran            #+#    #+#             */
/*   Updated: 2022/07/13 18:01:29 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	check_infos_in_first(char *line, int *count_info)
{
	int	tmp;

	tmp = *count_info;
	if (!ft_strncmp(line, "NO", 2))
		(*count_info)++;
	else if (!ft_strncmp(line, "EA", 2))
		(*count_info)++;
	else if (!ft_strncmp(line, "SO", 2))
		(*count_info)++;
	else if (!ft_strncmp(line, "WE", 2))
		(*count_info)++;
	else if (!ft_strncmp(line, "C", 1))
		(*count_info)++;
	else if (!ft_strncmp(line, "F", 1))
		(*count_info)++;
	if (tmp == (*count_info) - 1)
		return (0);
	return (1);
}

int	check_line_is_empty(char *line)
{
	int	i;

	i = 0;
	while (is_space(line[i]))
		i++;
	if (line[i] == '\0')
		return (0);
	return (1);
}

int	check_one_delimiter_line_of_map(char *line)
{
	int	i;

	i = 0;
	while (is_space(line[i]) || line[i] == '1')
		i++;
	if (line[i] == '\0')
		return (0);
	return (1);
}

int	check_good_order_in_file(t_data *data, char **file)
{
	int	i;
	int	count_info;

	i = -1;
	count_info = 0;
	while (file[++i])
	{
		if (!check_infos_in_first(file[i], &count_info))
			continue ;
		else if (!check_line_is_empty(file[i]))
			continue ;
		else if (!check_one_delimiter_line_of_map(file[i]) && count_info == 6)
			return (0);
		else
			print_error_pars_and_exit(ERR_MAP_LINE, data);
	}
	return (1);
}
