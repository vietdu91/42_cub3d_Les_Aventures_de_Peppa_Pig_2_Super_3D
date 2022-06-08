/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognize_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:00:15 by dyoula            #+#    #+#             */
/*   Updated: 2022/06/08 18:11:38 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int is_player(char c)
{
	printf("salut %c \n", c);
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
	if ((c >= 9 && c <= 13 ) || c == 32)
		return (0);
	else if (c == '1')
		return (0);
	return (-1);
}
