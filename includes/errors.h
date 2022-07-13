/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 10:31:50 by emtran            #+#    #+#             */
/*   Updated: 2022/07/13 13:56:43 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_L_ARG "Error\nI think there is something missing... \
Your self-esteem?\n"
# define ERR_H_ARG "Error\nOne can never have too many arguments! \
In fact, it is!\n"
# define ERR_CHAR "Error\nAn intruder is among us! Who is the guilty?\n"
# define ERR_COLOR "Error\nBlack and white creates a strange dreamscape \
that color never can.\n"
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
# define ERR_MAP "Error\nPas de map, ca derape !\n"
# define ERR_MAP_MANY_LINES "Error\nWOOOOW, you've a \
BIG height under your trousers\n"
# define ERR_MAP_MANY_LEN "Error\nWOOOOW, you've a BIG width under \
your trousers\n"
# define ERR_MAP_CLOSE "Error\nIl convient de fermer les yeux lorsque ceux-ci \
révèlent les pensées\n"
# define ERR_MAP_LINE "Error\nAll you need is the plan, the road map, and the \
courage to press on to your destination.\n"
# define ERR_MAP_FIRST_LINE "Error\nEvery story has a beginning! Especially the \
problems, especially if there is a problem in the first lines of the map!\n"
# define ERR_MAP_LAST_LINE "Error\nEvery story has an ending! Especially the \
problems, especially if there is a problem in the last lines of the map!\n"
# define ERR_MAP_TOO_STRONG "Error\nYour map is too strong like a string!\n"
# define ERR_NB_ARG_WALLS "Error\nЕсть слишком много аргументов, чтобы оформить \
твою стену, придурок!\n"
# define ERR_NB_NB_COLOR "Error\nToo much color harms the viewer!\n"
# define ERR_NB_ARG_COLOR "Error\n有太多关于颜色争论的争论了，婊子!\n"
# define ERR_PEPPA_MUCH "Error\nIt is impossible to have more than two Peppa Pigs \
in this universe!\n"
# define ERR_NO_PEPPA "Error\nThere's no game without a hero, like you... ❤️\n"
# define ERR_READ "Error\nYour problem with reading file is that you get \
distracted by your beautiful neighbour!\n"
# define ERR_MALLOC "Error\nOur memory is not a more perfect world than the \
universe\n"
# define ERR_MLC_IMG "Error\nNo good path, no good pic of dick\n"
# define NO_ENV "Error\nOn est rien sans l'environnement... \
Sauvons la planete !\n"

/*			PRINT_ERROR.C		*/

int			print_error(char *error);
int			print_error_and_exit(char *error, t_data *data);
int			print_error_pars_and_exit(char *error, t_data *data);
void		check_error_arg(int argc);

#endif
