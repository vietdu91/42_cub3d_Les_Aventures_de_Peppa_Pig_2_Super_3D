/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognize_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:00:15 by dyoula            #+#    #+#             */
/*   Updated: 2022/06/30 18:33:18 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	is_player(char c)
{
	if (c == 'N')
		return (0);
	else if (c == 'S')
		return (0);
	else if (c == 'E')
		return (0);
	else if (c == 'W')
		return (0);
	return (-1);
}

int	is_a_space_or_is_wall(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (0);
	else if (c == '1')
		return (0);
	return (-1);
}
