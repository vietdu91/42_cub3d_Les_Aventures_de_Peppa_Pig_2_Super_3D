/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:14:44 by emtran            #+#    #+#             */
/*   Updated: 2022/07/03 12:00:40 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H

/*			SPRITES.C			*/

int		init_sprites_zbuff(int x, t_sprites *sprites, t_player *p1);
int		sprite_casting(t_data *data, t_sprites *sprites, t_player *p1);
int 	sprite_projection(t_data *data, t_sprites *sprites, t_player *p1);
int		lowest_highest_height_pixel(t_sprites *sprites);
int	    store_color_in_buffer(t_data *data, t_sprites *sprites);
int	    define_texy(t_sprites *sprites, int y);
int		lowest_highest_width_pixel(t_sprites *sprites);
int		sort_sprites_from_far(t_sprites *sprites, t_player *p1);

#endif

