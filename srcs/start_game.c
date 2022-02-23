/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 02:53:16 by ahocine           #+#    #+#             */
/*   Updated: 2022/02/23 02:53:19 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_start_game(t_sl *sl)
{
	sl->win_ptr = mlx_new_window(sl->mlx_ptr, sl->resol.width, \
	sl->resol.height, "./so_long");
	ft_search_player(sl);
	ft_init_draw(sl);
	ft_init_texture(sl);
	return ;
}
