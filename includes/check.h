/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 10:38:37 by emtran            #+#    #+#             */
/*   Updated: 2022/05/13 11:44:42 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# define CUB ".cub"

/*			CHECK_FILE.C		    */

int	check_file(char **argv, t_data *data);
int	check_extension_cub(char *str, t_data *data);

/*          CHECK_WALLS.C           */

int	is_it_an_id_in_file(t_data *data, char **file, char *id, int i);
int	check_good_path_wall(t_data *data, t_walls *walls, char *line_file, \
char *type);
int	are_check_all_walls_is_ok(t_data *data, t_walls *walls);
int	check_walls(t_data *data, char **file);

#endif