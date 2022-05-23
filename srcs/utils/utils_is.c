/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_is.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:48:59 by emtran            #+#    #+#             */
/*   Updated: 2022/05/23 11:23:54 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	is_space(char c)
{
	int			a;
	const char	*str = SPACES;

	a = -1;
	while (str[++a] != '\0')
	{
		if (str[a] == c)
			return (1);
	}
	return (0);
}

int	is_digit(char c)
{
	int			a;
	const char	*str = DIGITS;

	a = -1;
	while (str[++a] != '\0')
	{
		if (str[a] == c)
			return (1);
	}
	return (0);
}
