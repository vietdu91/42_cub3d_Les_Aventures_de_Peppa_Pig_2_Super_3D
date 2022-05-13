/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:10:48 by emtran            #+#    #+#             */
/*   Updated: 2022/05/13 14:36:59 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/*			COLLECT_FILE.C				*/

int		collect_nb_lines_file(t_data *data, int fd);
int		print_file(t_data *data, int fd, int i);
int		collect_file(t_data *data, char **argv);

/*			COLLECT_WALLS.C				*/

int		collect_walls(t_data *data, char **file);
int		put_wall_in_structure(t_walls *walls, char **split, char *type);
int	    put_img_wall_to_mlx(t_data *data, char *path, t_pic *pic);
int	    create_img_of_walls(t_data *data, t_walls *walls, t_img *img);

#endif