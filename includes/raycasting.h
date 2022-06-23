/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:17:10 by dyoula            #+#    #+#             */
/*   Updated: 2022/06/16 17:00:14 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# define CUB ".cub"

void	translate_direction_player(t_player *p1, char c);
void	init_direction_player(t_data *data, int direction);
int		draw_first_vector(t_data *data, int size_x, int size_y, int direction);
int		draw_right_vector(t_data *data);

#endif
