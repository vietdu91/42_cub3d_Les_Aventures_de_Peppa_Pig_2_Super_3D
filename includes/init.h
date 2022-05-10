/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:36:15 by emtran            #+#    #+#             */
/*   Updated: 2022/05/10 18:29:06 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

typedef struct s_win
{
	int		win_width;
	int		win_height;
}	t_win;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_game;

typedef struct s_map
{
	char	**map;
	int		lines_map;
	int		max_len_map;
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

/*			INIT_STRUCTS.C			*/

void	init_data(t_data *data);
void	init_struct_game(t_game *game);
t_data	*init_struct(t_data *data);

/*			INIT_STRUCTS.C			*/

int		init_mlx_and_window(t_data *data, t_game *game, t_win *window);


#endif