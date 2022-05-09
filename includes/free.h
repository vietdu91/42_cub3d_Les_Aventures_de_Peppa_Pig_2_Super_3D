/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:38:52 by emtran            #+#    #+#             */
/*   Updated: 2022/05/09 14:38:11 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

/*			FREE.C			*/

void	free_d_tab(char **tb);
void	free_game_and_mlx(t_game *game);
int		free_all(t_data *data);
int		free_all_and_exit(t_data *data);

#endif