/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:12:48 by emtran            #+#    #+#             */
/*   Updated: 2022/07/13 15:12:47 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	check_color(int n)
{
	if (n >= 0 && n <= 255)
		return (1);
	return (0);
}

int	ft_rgb_to_hex(int r, int g, int b)
{
	int		hex;

	if (check_color(r) == 0 || check_color(g) == 0 || check_color(b) == 0)
		return (-1);
	hex = (0 << 24 | r << 16 | g << 8 | b);
	return (hex);
}
