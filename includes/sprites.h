/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:14:44 by emtran            #+#    #+#             */
/*   Updated: 2022/07/02 23:50:26 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H

// /*			SPRITES.C			*/

int		init_sprites_zbuff(int x, t_sprites *sprites, t_player *p1);
int		sprite_casting(t_data *data, t_sprites *sprites, t_player *p1);
int 	sprite_projection(t_data *data, t_sprites *sprites, t_player *p1);
int		lowest_highest_height_pixel(t_sprites *sprites);

#endif

