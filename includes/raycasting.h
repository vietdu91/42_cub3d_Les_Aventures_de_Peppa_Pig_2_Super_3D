/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:17:10 by dyoula            #+#    #+#             */
/*   Updated: 2022/06/28 14:28:33 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# define CUB ".cub"

void	translate_direction_player(t_player *p1, char c);
void	init_direction_player(t_data *data, int direction);
int		draw_first_vector(t_data *data, int size_x, int size_y, int direction);
int		draw_right_vector(t_data *data);

/*					DRAW.C					*/
void	verLine(t_data *data, int x, int y1, int y2, int color);


t_ray	*ray_casting(t_data *data, t_ray *ray);
t_ray	*ray_dist(t_data *data, t_player *p1, t_ray *ray);

t_ray	*ray_init(t_data *data, t_player *p1, int x);
t_ray	*ray_main(t_data *data, t_player *p1, int x);



#endif
