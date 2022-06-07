/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:04:04 by dyoula            #+#    #+#             */
/*   Updated: 2022/06/07 23:27:01 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	find_width(char **map)
{
	int	i;
	int	j;
	int max;

	i = -1;
	max = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (j > max)
				max = j;
		}
	}
	return (max);
}

int	render(t_data *data)
{
	// printf("yo\n");
	if (data->game->win_ptr != NULL)
		mlx_pixel_put(data->game->mlx_ptr, data->game->win_ptr, \
		WINDOW_WIDTH /2, WINDOW_HEIGHT / 2, RED);
	return (0);
}
int	draw_map(t_data *data, int x, int y)
{
	(void)data;
	(void)x;
	(void)y;
	// data->img = NULL;
	// data->addr = NULL;
	// data->endian = 0;
	// data->line_length = x;
	// data->bits_per_pixel = 8;
	// data->img = mlx_new_image(data->game->mlx_ptr, x, y);
	// data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);

	// int offset = (y * data->line_length + x * (data->bits_per_pixel / 8));
	// printf("salut offset = %d\n", offset);
	return (0);
}

int	size_map(t_data *data)
{
	int	size_x;
	int	size_y;
	int	len_max;

	len_max = find_width(data->map->map);
	size_x = data->win.win_width / len_max;
	size_y = data->win.win_height / size_dtab(data->map->map);
	printf("salut x = %d et y = %d\n", size_x, size_y);
	draw_map(data, size_x, size_y);
	return (0);
}
int	convert_map_to_lines(t_data *data, char **map)
{
	// int i;
	// int j;
	(void)data;
	(void)map;
	// i = -1;
	// while (map[++i])
	// {
	// 	j = -1;
	// 	while (map[i][++j])
	// 	{
	// 		printf("%c", map[i][j]);
	// 	}
	// 	printf("\n");
	// }
	return (0);
}
