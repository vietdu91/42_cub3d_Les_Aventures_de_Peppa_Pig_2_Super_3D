/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:46:20 by emtran            #+#    #+#             */
/*   Updated: 2022/05/13 11:46:37 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	free_d_tab(char **tb)
{
	int	i;

	i = -1;
	if (!tb)
		return ;
	while (tb[++i])
	{
		if (tb[i])
			free(tb[i]);
	}
	free(tb);
	tb = NULL;
}

char	**free_split(char **split, int index)
{
	while (index >= 0)
		free(split[index--]);
	free(split);
	return (NULL);
}