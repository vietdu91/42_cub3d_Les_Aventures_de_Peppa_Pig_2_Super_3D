/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:06:57 by emtran            #+#    #+#             */
/*   Updated: 2022/06/30 17:50:11 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <X11/X.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include "../mlx/mlx.h"
# include "./init.h"
# include "./game.h"
# include "./free.h"
# include "./images.h"
# include "./utils.h"
# include "./errors.h"
# include "./check.h"
# include "./map.h"
# include "./maths.h"
# include "./parsing.h"
# include <X11/keysym.h>
# include "raycasting.h"

/*			MAIN.C		*/

int	game_start(t_data *data);
int	game_running(t_data *data);
int loop(t_data *data);

#endif
