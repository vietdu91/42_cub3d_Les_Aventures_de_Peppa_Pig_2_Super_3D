/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 10:31:50 by emtran            #+#    #+#             */
/*   Updated: 2022/05/13 15:53:48 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_L_ARG "Error\nI think there is something missing... \
Your self-esteem?\n"
# define ERR_H_ARG "Error\nOne can never have too many arguments! \
In fact, it is!\n"
# define ERR_CUB "Error\nBut ... Your .cub file is badly formatted ! \
Naughty guy ! \n"
# define ERR_DIR "Error\nDid you try to scam me with a file? You asshole.\n"
# define ERR_FILE "Error\nBad boys, bad file!\n"
# define ERR_ID "Error\nYour ID of direction walls in map is wrong, bastard!\n"
# define ERR_ID_MISS "Error\nYour ID of direction walls in map is missing, \
encule de pie!\n"
# define ERR_ID_FC "Error\nYour ID of floor celling in map is wrong, bastard!\n"
# define ERR_ID_FC_MISS "Error\nYour ID of floor celling in map is missing, \
encule de pie!\n"
# define ERR_NB_ARG_WALLS "Error\nЕсть слишком много аргументов, чтобы оформить \
твою стену, придурок!\n"
# define ERR_READ "Error\nYour problem with reading file is that you get \
distracted by your beautiful neighbour!\n"
# define ERR_MALLOC "Error\nOur memory is not a more perfect world than the \
universe\n"
# define ERR_MLC_IMG "Error\nNo good path, no good pic of dick\n"

/*			PRINT_ERROR.C		*/

int			print_error(char *error);
int			print_error_and_exit(char *error, t_data *data);
void		check_error_arg(int argc);

#endif