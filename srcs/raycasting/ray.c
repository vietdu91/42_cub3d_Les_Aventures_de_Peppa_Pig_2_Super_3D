/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:08:58 by emtran            #+#    #+#             */
/*   Updated: 2022/06/28 18:58:57 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"


t_ray	*ray_casting(t_data *data, t_ray *ray)
{
	while (data->map->map[ray->pos_x][ray->pos_y] != 1)
	{
		if (ray->dist_to_x < ray->dist_to_y)
		{
			ray->dist_to_x += ray->dist_from_x;
			ray->pos_x += ray->ext_x;
			ray->card = 1;
			if (ray->ext_x == 1)
				ray->card = 3;
		}
		else
		{
			ray->dist_to_y += ray->dist_from_y;
			ray->pos_y += ray->ext_y;
			ray->card = 0;
			if (ray->ext_y == 1)
				ray->card = 2;
		}
	}
	return (ray);
}

t_ray	*ray_dist(t_data *data, t_player *p1, t_ray *ray)
{
	ray->dist_from_x = 1 / ray->dir_x;
	if (ray->dist_from_x < 0)
		ray->dist_from_x *= -1;
	ray->dist_from_y = 1 / ray->dir_y;
	if (ray->dist_from_y < 0)
		ray->dist_from_y *= -1;
	if (ray->dir_x < 0)
		ray->dist_to_x = (p1->posX - ray->pos_x) * ray->dist_from_x;
	else
		ray->dist_to_x = (ray->pos_x + 1 - p1->posX) * ray->dist_from_x;
	if (ray->dir_y < 0)
		ray->dist_to_y = (p1->posY - ray->pos_y) * ray->dist_from_y;
	else
		ray->dist_to_y = (ray->pos_y + 1 - p1->posY) * ray->dist_from_y;
	return (ray_casting(data, ray));
}

t_ray	*ray_init(t_data *data, t_player *p1, int x)
{
	t_ray			*ray;
	double			dir;

	ray = (t_ray *)malloc(sizeof(t_ray));
	if (ray == 0)
		return (0);
	dir = x * 2 / (double)WINDOW_WIDTH - 1;
	ray->pos_x = (int)p1->posX;
	ray->pos_y = (int)p1->posY;
	ray->dir_x = p1->dirX + p1->planeX * dir;
	ray->dir_y = p1->dirY + p1->planeY * dir;
	if (ray->dir_x < 0)
		ray->ext_x = -1;
	else
		ray->ext_x = 1;
	if (ray->dir_y < 0)
		ray->ext_y = -1;
	else
		ray->ext_y = 1;
	return (ray_dist(data, p1, ray));
}

t_img	*choose_texture_wall(t_texture *texture, t_ray *ray)
{
	if (ray->card == 0)
		return (texture->wall_no);
	else if (ray->card == 1)
		return (texture->wall_so);
	else if (ray->card == 2)
		return (texture->wall_ea);
	else if (ray->card == 3)
		return (texture->wall_we);
	return (0);
}

t_ray	*ray_texture(t_data *data, t_player *p1, t_ray *ray)
{
	t_img			*img;

	img = choose_texture_wall(data->game->texture, ray);
	if (ray->card % 2 == 0)
		ray->wall_coord = p1->posX + ray->dir_x * ray->wall_dist;
	else
		ray->wall_coord = p1->posY + ray->dir_y * ray->wall_dist;
	ray->wall_coord -= floor(ray->wall_coord);
	ray->text_x = (int)(ray->wall_coord * (double)img->width);
	if ((ray->card % 2 && ray->dir_x > 0)
		|| (ray->card % 2 == 0 && ray->dir_y < 0))
		ray->text_x = (double)img->width - ray->text_x - 1;
	ray->text_step = 1.0 * img->height / ray->wall_height;
	ray->text_pos = (ray->wall_start - WINDOW_HEIGHT / 2 + \
	ray->wall_height / 2) * ray->text_step;
	return (ray);
}

t_ray	*ray_main(t_data *data, t_player *p1, int x)
{
	t_ray	*ray;

	(void) x;
	ray = ray_init(data, p1, x);
	if (!ray)
		return (0);
	if (ray->card % 2)
		ray->wall_dist
			= (ray->pos_x - p1->posX + (1 - ray->ext_x) / 2) / ray->dir_x;
	else
		ray->wall_dist
			= (ray->pos_y - p1->posX + (1 - ray->ext_y) / 2) / ray->dir_y;
	ray->wall_height = (int)(WINDOW_HEIGHT / ray->wall_dist);
	ray->wall_start = -ray->wall_height / 2 + WINDOW_HEIGHT / 2;
	if (ray->wall_start < 0)
		ray->wall_start = 0;
	ray->wall_end = ray->wall_height / 2 + WINDOW_HEIGHT / 2;
	if (ray->wall_end >= WINDOW_HEIGHT)
		ray->wall_end = WINDOW_HEIGHT - 1;
	return (ray_texture(data, p1, ray));
}
