/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:27:15 by emtran            #+#    #+#             */
/*   Updated: 2022/07/03 19:20:43 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define INTRO "./textures/intro.xpm"
# define CREDIT "./textures/credit.xpm"
# define GAMEOVER "./textures/game_over.xpm"
# define BUTCHER "./textures/butcher.xpm"
# define OVERLAY_HAPPY "./textures/Peppa_is_happy.xpm"
# define OVERLAY_SCARED "./textures/Peppa_has_peur.xpm"
# define OVERLAY_PANIC "./textures/Peppa_is_panic.xpm"

# define BUTCHER_NO "./textures/paint_blood_wall.xpm"
# define BUTCHER_SO "./textures/no_window_wall_2.xpm"
# define BUTCHER_WE "./textures/bad_pig_wall.xpm"
# define BUTCHER_EA "./textures/you_re_next_wall.xpm"

# ifdef __linux__
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_P 112
#  define KEY_UP 65362
#  define KEY_LEFT 65361
#  define KEY_DOWN 65364
#  define KEY_RIGHT 65363
#  define KEY_SHIFT 65505
#  define ESC 65307
#  define ESP 32
# else
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_Q 12
#  define KEY_E 14
#  define KEY_UP 126
#  define KEY_LEFT 123
#  define KEY_DOWN 125
#  define KEY_RIGHT 124
#  define ESC 53
# endif

int		to_the_house_of_peppa(t_data *data);
int		to_the_house_of_butcher(t_data *data);
void	img_pix_put(t_img *img, int x, int y, int color);
int		game_start(t_data *data);

/*			INTRODUCTION.C		*/

void	introduction_of_game(t_data *data, t_game *game);
void	credit_of_game(t_data *data, t_game *game);
void	death_of_peppa_pig(t_data *data, t_game *game);

/*          KEYS.C          */
int		keys_main(int key_code, t_data *data);
int		key_release_main(int keysym, void *data);
int		angle_manager(int keysim, t_player *p1);
int		key_press(int key, t_data *data);


/*			CAMERA.C		*/

void	right_key(t_data *data);
void	left_key(t_data *data);


/*			MOVE.C			*/

void	w_key(t_data *data);
void	s_key(t_data *data);
void	a_key(t_data *data);
void	d_key(t_data *data);
void	right_key(t_data *data);
void	left_key(t_data *data);

/*			TRANSFORMATION.C		*/

int		to_the_house_of_peppa(t_data *data);
int		to_the_house_of_butcher(t_data *data);

#endif
