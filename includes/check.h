/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 10:38:37 by emtran            #+#    #+#             */
/*   Updated: 2022/07/13 18:51:53 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# define CUB ".cub"

/*          CHECK_CELLING_FLOOR.C        */

int		is_it_an_id_celling_floor_in_file(t_data *data, char **file, char *id, \
		int i);
int		check_path_arg_color_is_good(t_data *data, char *line_file, \
		char **split);
int		check_good_path_floor(t_data *data, t_color *color, char *line_file, \
		char *type);
int		are_check_all_floor_celling_is_ok(t_data *data, t_floor *floor);
int		check_celling_floor(t_data *data, char **file);

/*			CHECK_FILE.C		    */

int		check_file(char **argv, t_data *data);
int		check_extension_cub(char *str);

/*			CHECK_MAP.C				*/

int		second_check_map_is_close(t_data *data, char **map);
int		check_map_is_close(t_data *data, char **map);
int		check_letters_of_map(t_data *data, char **map);
int		check_first_and_last_letters_of_line(t_data *data, char **map);
int		check_map(t_data *data, t_map *map);

/*			CHECK_ORDER_IN_FILE.C	*/

int		check_infos_in_first(char *line, int *count_info);
int		check_line_is_empty(char *line);
int		check_one_delimiter_line_of_map(char *line);
int		check_good_order_in_file(t_data *data, char **file);

/*			CHECK_PEPPA.C				*/

int		check_peppa_is_not_in_void(t_data *data, t_peppa *peppa, char **map);
int		check_position_of_peppa(t_data *data, t_peppa *peppa, char **map);
int		zero_is_not_in_void(t_data *data, int y, int x, char **map);

/*			CHECK_RGB.C				*/

int		check_color(int n);
int		ft_rgb_to_hex(int r, int g, int b);

/*          CHECK_WALLS.C           */

int		is_it_an_id_in_file(t_data *data, char **file, char *id, int i);
int		check_good_path_wall(t_data *data, t_walls *walls, char *line_file, \
		char *type);
int		are_check_all_walls_is_ok(t_data *data, t_walls *walls);
int		check_walls(t_data *data, char **file);
bool	inverse_bool_wall(bool check);

#endif
