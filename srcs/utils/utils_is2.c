/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_is2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:48:59 by emtran            #+#    #+#             */
/*   Updated: 2022/06/10 13:43:55 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	has_str_only_spaces(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
	{
		if (is_space(str[a]))
			a++;
		else
			return (0);
	}
	return (1);
}

int	has_str_only_walls(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
	{
		if (str[a] == '1' || is_space(str[a]))
			a++;
		else
			return (0);
	}
	return (1);
}
