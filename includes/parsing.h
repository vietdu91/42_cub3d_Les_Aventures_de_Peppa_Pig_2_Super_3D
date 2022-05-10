/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:10:48 by emtran            #+#    #+#             */
/*   Updated: 2022/05/10 19:42:50 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/*          COLLECT_FILE.C           */

int		collect_nb_lines_file(t_data *data, int fd);
int		print_file(t_data *data, int fd, int i);
int		collect_file(t_data *data, char **argv);

#endif