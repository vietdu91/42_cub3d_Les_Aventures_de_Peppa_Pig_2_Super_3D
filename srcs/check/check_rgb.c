/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:12:48 by emtran            #+#    #+#             */
/*   Updated: 2022/05/16 16:46:31 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	check_color(int n)
{
	if (n >= 0 && n <= 255)
		return (1);
	return (0);
}

char	convert_to_hex(int n, char *base)
{
	char	res;

	res = base[n % 16];
	return (res);
}

char	*ft_rgb_to_hex(t_data *data, int r, int g, int b)
{
	char	*res;

	if (check_color(r) == 0 || check_color(g) == 0 || check_color(b) == 0)
		print_error_and_exit(ERR_COLOR, data);
	res = malloc(sizeof(char) * 8);
	if (!res)
		return (NULL);
	res[0] = '#';
	res[7] = '\0';
	res[1] = convert_to_hex(r / 16, HEXA);
	res[2] = convert_to_hex(r, HEXA);
	res[3] = convert_to_hex(g / 16, HEXA);
	res[4] = convert_to_hex(g, HEXA);
	res[5] = convert_to_hex(b / 16, HEXA);
	res[6] = convert_to_hex(b, HEXA);
	return (res);
}
