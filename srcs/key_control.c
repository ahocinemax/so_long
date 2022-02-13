/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 23:01:09 by ahocine           #+#    #+#             */
/*   Updated: 2022/02/12 23:01:10 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_key_control(int key, t_sl *sl)
{
	sl->speed_move = 0.2;
	if (key == KEY_W)
		sl->move.av = 1;
	else if (key == KEY_A)
		sl->move.left = 1;
	else if (key == KEY_S)
		sl->move.arr = -1;
	else if (key == KEY_D)
		sl->move.right = 1;
	else if (key == KEY_ESC)
		close_cross(sl);
	return (0);
}

int	ft_key_control2(int key, t_sl *sl)
{
	sl->speed_move = 0.2;
	if (key == KEY_W)
		sl->move.av = 0;
	else if (key == KEY_A)
		sl->move.left = 0;
	else if (key == KEY_S)
		sl->move.arr = 0;
	else if (key == KEY_D)
		sl->move.right = 0;
	else if (key == KEY_ESC)
		close_cross(sl);
	return (0);
}	