/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:38:52 by emtran            #+#    #+#             */
/*   Updated: 2022/07/13 18:05:47 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

/*			FREE.C			*/

int		free_all(t_data *data);
int		free_all_and_exit(t_data *data);

/*			FREE_FAILED_PARSING.C */
int		check_parsing(char **argv, t_data *data);
void	free_forest(t_data *data);
int		free_parsing_failed(t_data *data);

/*			FREE_IMG.C			*/

void	destroy_walls(t_data *data, t_texture *text);
void	free_img(t_game *game, t_img *img);
void	free_color(t_color *color);
void	free_texture(t_game *game, t_texture *img);

/*			FREE_STRUCTS.C			*/

void	free_sprites(t_sprites *sprites);
void	free_maps(t_map *map);
void	free_pics(t_game *game, t_pic *pic);
void	free_game_and_mlx(t_game *game);

/*			FREE_UTILS.C			*/

void	free_d_tab(char **tb);
char	**free_split(char **split, int index);

#endif
