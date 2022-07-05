/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:13:06 by dyoula            #+#    #+#             */
/*   Updated: 2022/07/05 14:49:21 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

int		render(t_data *data);
int		draw_map(t_data *data, int size_x, int size_y);
int		place_player(t_data *data, int size_x, int size_y);

/*						DRAW_LINES.C					*/
int		draw_bottom(t_data *data, int *x, int *y, int size_x);
int		draw_right_wall(t_data *data, int *x, int *y, int size_y);
void	distinct_walls(t_data *data, int *x, int y, int size_x);
void	draw_player(t_data *data, int x, int y, int color);

/*						VERIFICATIONS.C					*/
int		wall_touched(t_data *data, int size_x, int size_y, int key);
int		vector_has_touched(t_data *data, int size_x, int size_y, int dir);

#endif
