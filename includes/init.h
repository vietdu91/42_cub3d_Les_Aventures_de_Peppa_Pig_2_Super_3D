/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:36:15 by emtran            #+#    #+#             */
/*   Updated: 2022/04/24 15:10:01 by emtran           ###   ########.fr       */
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

typedef struct s_data
{
	char	**map;
	int		lines;
	t_game	*game;
	t_win	win;
}	t_data;

/*			INIT_STRUCTS.C			*/

void	init_data(t_data *data);
void	init_game(t_game *game);
t_data	*init_struct(t_data *data);

#endif