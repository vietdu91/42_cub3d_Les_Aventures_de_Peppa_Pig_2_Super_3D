/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:38:52 by emtran            #+#    #+#             */
/*   Updated: 2022/06/10 12:49:58 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

/*			FREE.C			*/

int		free_all(t_data *data);
int		free_all_and_exit(t_data *data);

/*			FREE_IMG.C			*/

void	free_img(t_game *game, t_img *img);
void	free_color(t_color *color);
void	free_texture(t_game *game, t_texture *img);

/*			FREE_STRUCTS.C			*/

void	free_maps(t_map *map);
void	free_game_and_mlx(t_game *game);

/*			FREE_UTILS.C			*/

void	free_d_tab(char **tb);
char	**free_split(char **split, int index);

#endif
