/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:10:48 by emtran            #+#    #+#             */
/*   Updated: 2022/06/30 11:52:51 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define ACCEPTED_VALUES "0WSEN"
# define ACCEPTED_VALUES_AND_WALLS " 01WSEN"
# define POSITION "WSEN"
# define BIN "01"

/*			COLLECT_CELLING_FLOOR.C			*/

int		check_collect_rgb_is_good(t_data *data, char **split);
int		collect_celling_floor(t_data *data, char **file);
int		collect_rgb(t_data *data, t_color *color);

/*			COLLECT_FILE.C				*/

int		collect_nb_lines_file(t_data *data, int fd);
int		print_file(t_data *data, int fd, int i);
int		collect_file(t_data *data, char **argv);

/*          COLLECT_MAP.C               */

char	**save_map(t_data *data, t_map *map);
int		collect_map(t_data *data, t_map *map);

/*          COLLECT_MAP_LINES.C         */

int		collect_gap_of_first_and_last_line(t_data *data, int first, int last);
int		collect_max_width_map(t_data *data, t_map *map, int first, int last);
int		check_line_is_infos(char *line);
int		collect_first_line_map(t_data *data, t_map *map, char **file);
int		collect_last_line_map(t_data *data, t_map *map, char **file);

/*			COLLECT_WALLS.C				*/

int		collect_walls(t_data *data, char **file);
int		put_wall_in_structure(t_walls *walls, char **split, char *type);
int		put_img_wall_to_mlx(t_data *data, char *path, t_img *img);
int		create_img_of_walls(t_data *data, t_walls *walls, t_texture *img);

#endif
