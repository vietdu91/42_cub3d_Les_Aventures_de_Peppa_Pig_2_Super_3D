/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:12:48 by emtran            #+#    #+#             */
/*   Updated: 2022/06/30 15:08:28 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	check_color(int n)
{
	if (n >= 0 && n <= 255)
		return (1);
	return (0);
}

int		ft_rgb_to_hex(t_data *data, int r, int g, int b)
{
	int		hex;

	if (check_color(r) == 0 || check_color(g) == 0 || check_color(b) == 0)
		print_error_and_exit(ERR_COLOR, data);
	hex = (0 << 24 | r << 16 | g << 8 | b);
	return (hex);
}
