/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:36:15 by emtran            #+#    #+#             */
/*   Updated: 2022/06/10 13:00:30 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

#define OKAY 0
#define WHITE 0xFFFFFF
#define RED 0xFF0000
#define GREEN 0x008000
#define WINDOW_WIDTH 1200
#define	WINDOW_HEIGHT 800

typedef	struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int 	line_len;
	int		endian;
}	t_img;

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

typedef struct s_texture
{
	t_pic	*wall_no;
	t_pic	*wall_so;
	t_pic	*wall_we;
	t_pic	*wall_ea;
	t_color	*floor;
	t_color	*celling;
}	t_texture;

typedef struct s_peppa
{
	int		check_peppa;
	char	pos_peppa;
	int		x_peppa;
	int		y_peppa;
}	t_peppa;

typedef struct s_player
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	time;
	double	oldtime;
}	t_player;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_texture	*texture;
	t_peppa		*peppa;
	t_player	*p1;
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
	char		**file;
	int			lines_file;
	int			max_len_file;
	t_game		*game;
	t_map		*map;
	t_win		win;
	t_img		*img;//potentiel tableau
}	t_data;

/*			INIT_GAME.C			*/

int		init_mlx_and_window(t_data *data, t_game *game, t_win *window);
void	init_struct_game(t_game *game);

/*			INIT_IMG.C			*/

int		init_img(t_data *data);

/*			INIT_MAP.C			*/

void	init_struct_walls(t_walls *walls);
void	init_struct_floor(t_floor *floor);
void	init_struct_map(t_map *map);

/*			INIT_STRUCTS.C			*/

void	init_struct_malloc(t_data *data);
void	init_data(t_data *data);
void	init_struct_peppa(t_peppa *peppa);
t_data	*init_struct(t_data *data);
void	init_texture(t_texture *img);
void	init_pic(t_pic *pic);
void	init_color(t_color *color);

#endif
