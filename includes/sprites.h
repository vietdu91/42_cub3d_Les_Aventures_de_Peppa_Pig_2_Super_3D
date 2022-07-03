/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:14:44 by emtran            #+#    #+#             */
/*   Updated: 2022/07/03 20:12:00 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H

/*			SPRITES.C			*/

int			init_sprites_zbuff(int x, t_sprites *sprites, t_player *p1);
int			sprite_casting(t_data *data, t_sprites *sprites, t_player *p1);
int 		sprite_projection(t_data *data, t_sprites *sprites, t_player *p1);
int			lowest_highest_height_pixel(t_sprites *sprites);
int			lowest_highest_width_pixel(t_sprites *sprites);

int	   		define_texy(t_sprites *sprites, int y);
int			get_text_rgb_sprites(char *addr, t_data *data, int add, int y);
u_int32_t	store_color(t_sprites *sprites, u_int32_t color);
int	    	store_color_in_buffer(t_data *data, t_sprites *sprites);

int			sort_sprites_from_far(t_sprites *sprites, t_player *p1);
int			first_zero_of_map(t_map *map, t_sprites *sprites);
int			last_zero_of_map(t_map *map, t_sprites *sprites);
int			assign_place_of_butcher(t_data *data, t_sprites *sprites, t_player *p1);

int 		sprites_move_backward(t_data *data, t_player *p1);
int 		sprites_move_forward(t_data *data, t_player *p1);
int			sprites_move(t_data *data, int a, t_player *p1);

#endif

