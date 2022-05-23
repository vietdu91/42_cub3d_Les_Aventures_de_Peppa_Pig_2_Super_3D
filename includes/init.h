/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:36:15 by emtran            #+#    #+#             */
/*   Updated: 2022/05/23 12:24:59 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

typedef struct s_win
{
	int		win_width;
	int		win_height;
}	t_win;

typedef struct s_color
{
	char	*path;
	char	*hexa;
	int		r;
	int		g;
	int		b;
}	t_color;

typedef struct s_pic
{
	void	*img;
	int		width;
	int		height;
}	t_pic;

typedef struct s_img
{
	t_pic	*wall_no;
	t_pic	*wall_so;
	t_pic	*wall_we;
	t_pic	*wall_ea;
	t_color	*floor;
	t_color	*celling;
}	t_img;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
}	t_game;

typedef struct s_walls
{
	bool	check_no;
	char	*path_no;
	bool	check_so;
	char	*path_so;
	bool	check_we;
	char	*path_we;
	bool	check_ea;
	char	*path_ea;
}	t_walls;

typedef struct s_floor
{
	bool	check_floor;
	bool	check_celling;
}	t_floor;

typedef struct s_map
{
	char	**map;
	int		first_line;
	int		last_line;
	int		lines_map;
	int		max_len_map;
	t_walls	*walls;
	t_floor	*floor;
}	t_map;

typedef struct s_data
{
	char	**file;
	int		lines_file;
	int		max_len_file;
	t_game	*game;
	t_map	*map;
	t_win	win;
}	t_data;

/*			INIT_GAME.C			*/

int		init_mlx_and_window(t_data *data, t_game *game, t_win *window);

/*			INIT_MAP.C			*/

void	init_struct_walls(t_walls *walls);
void	init_struct_floor(t_floor *floor);
void	init_struct_map(t_map *map);

/*			INIT_STRUCTS.C			*/

void	init_data(t_data *data);
void	init_struct_game(t_game *game);
t_data	*init_struct(t_data *data);
void	init_img(t_img *img);
void	init_pic(t_pic *pic);
void	init_color(t_color *color);

#endif