/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 10:38:37 by emtran            #+#    #+#             */
/*   Updated: 2022/04/24 14:46:31 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# define CUB ".cub"

/*			CHECK_FILE.C		*/

int	check_file(char **argv, t_data *data);
int	check_extension_cub(char *str, t_data *data);

#endif