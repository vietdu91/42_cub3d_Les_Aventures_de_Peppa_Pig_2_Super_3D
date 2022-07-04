/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:17:10 by dyoula            #+#    #+#             */
/*   Updated: 2022/07/04 11:05:00 by emtran           ###   ########.fr       */
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

int		colors(t_data *data, t_player *p1);
void	img_pix_put(t_img *img, int x, int y, int color);
void	assign_text_x(t_player *p1);
t_img	*verline(t_data *data, int x, int y1, int y2);

/*				RAYCASTING.C			*/

void	reset_values(t_player *p1, int x);
void	step_manager(t_player *p1);
void	jump_next_map_square(t_data *data, t_player *p1);
void	check_side(t_player *p1);
int		set_view_of_peppa(t_data *data, t_player *p1);

/*				SET_VIEW.C				*/

int		set_view_of_peppa(t_data *data, t_player *p1);
int		set_view_of_peppa_suite(t_data *data, t_player *p1);

/*				SPRITES_MOVE.C			*/

int		sprites_move_backward(t_data *data, t_player *p1);
int		sprites_move_forward(t_data *data, t_player *p1);
int		sprites_move(t_data *data, int a, t_player *p1);

/*				TEXTURES.C				*/

char	*set_wall_direction(t_texture *text, t_player *peppa);
int		get_text_rgb(char *addr, t_data *data, int add, int y);
int		display_wall(t_data *data, int x, int *y, int y2);
int		rgb_to_hex_text(int red, int green, int blue);

#endif
