/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:36:15 by emtran            #+#    #+#             */
/*   Updated: 2022/07/04 11:06:29 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# define OKAY 0
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x008000
# define BLACK 0x000000
# define BLUE 0xB0E0E6
# define VIOLET 0xC014BC
# define LOOK_LEFT 65361
# define LOOK_RIGHT 65363
# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 1000
# define WINDOW_GAME 800
# define MAP_WIDTH 400
# define MAP_HEIGHT 200
# define T_WIDTH 150
# define T_HEIGHT 150
# define SPRITE_W 150
# define SPRITE_H 150
# define FOV 60

# define NUM_SPRITES 1

enum	e_side
{
	NO,
	SO,
	WE,
	EA
};

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_win
{
	int		win_width;
	int		win_height;
}	t_win;

typedef struct s_color
{
	char	*path;
	int		hexa;
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
	t_img	*wall_no;
	t_img	*wall_so;
	t_img	*wall_we;
	t_img	*wall_ea;
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
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	time;
	double	oldtime;
	double	px;
	double	py;
	double	pdx;
	double	pdy;
	double	pa;
	double	raydir_x;
	double	raydir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	camera_x;
	int		line_height;
	double	text_start;
	double	text_x;
	double	rot_speed;
	double	move_speed;
	double	olddir_x;
	double	oldplane_x;
}	t_player;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			step_of_game;
	bool		good_or_bad;
	t_pic		*intro;
	t_pic		*credit;
	t_pic		*game_over;
	t_img		*dylan_the_butcher;
	t_pic		*overlay_happy;
	t_pic		*overlay_scared;
	t_pic		*overlay_panic;
	t_texture	*texture;
	t_peppa		*peppa;
	t_player	*p1;
	t_img		*screen;
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
	int		size_x;
	int		size_y;
	t_walls	*walls;
	t_floor	*floor;

}	t_map;

typedef struct s_sprites
{
	char		*path;
	double		x;
	double		y;
	int			texture;
	u_int32_t	buffer[WINDOW_GAME][WINDOW_WIDTH];
	double		z_buffer[WINDOW_WIDTH];
	double		sprite_distance;
	double		spritex;
	double		spritey;
	double		invdet;
	double		transformx;
	double		transformy;
	int			spritescreenx;
	int			sprite_height;
	int			sprite_width;
	int			draw_start_y;
	int			draw_start_x;
	int			draw_end_y;
	int			draw_end_x;
	int			stripe;
	int			*tex;
	int			tex_x;
	int			tex_y;
}	t_sprites;

typedef struct s_data
{
	char		**file;
	int			lines_file;
	int			max_len_file;
	t_game		*game;
	t_map		*map;
	t_win		win;
	t_img		*img;
	t_sprites	*sprites;
}	t_data;

/*			INIT_GAME.C			*/

int		init_mlx_and_window(t_data *data, t_game *game, t_win *window);
void	init_overlays(t_data *data, t_game *game);
void	init_struct_game(t_data *data, t_game *game);

/*			INIT_IMG.C			*/

int		init_img(t_img *img);
void	init_val(t_player *p1);
void	init_texture(t_data *data, t_texture *text);

/*			INIT_MAP.C			*/

void	init_struct_walls(t_walls *walls);
void	init_struct_floor(t_floor *floor);
void	init_struct_map(t_map *map);

/*			INIT_STRUCTS.C			*/

void	init_struct_malloc(t_data *data);
void	init_data(t_data *data);
void	init_struct_peppa(t_peppa *peppa);
t_data	*init_struct(t_data *data);
void	init_pic(t_pic *pic);
void	init_color(t_color *color);
void	init_sprites(t_data *data, t_sprites *sprites);

#endif
