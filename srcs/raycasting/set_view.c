/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:58:05 by emtran            #+#    #+#             */
/*   Updated: 2022/06/30 18:59:33 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	set_view_of_peppa_suite(t_data *data, t_player *p1)
{
	if (data->game->peppa->pos_peppa == 'W')
	{
		p1->dirX = -1;
		p1->dirY = 0;
		p1->planeX = 0;
		p1->planeY = -0.66;
	}
	else if (data->game->peppa->pos_peppa == 'E')
	{
		p1->dirX = 1;
		p1->dirY = 0;
		p1->planeX = 0;
		p1->planeY = -0.66;
	}
	return (0);
}

int	set_view_of_peppa(t_data *data, t_player *p1)
{
	if (data->game->peppa->pos_peppa == 'N')
	{
		p1->dirX = 0;
		p1->dirY = -1;
		p1->planeX = -0.66;
		p1->planeY = 0;
	}
	else if (data->game->peppa->pos_peppa == 'S')
	{
		p1->dirX = 0;
		p1->dirY = 1;
		p1->planeX = -0.66;
		p1->planeY = 0;
	}
	return (set_view_of_peppa_suite(data, p1));
}
