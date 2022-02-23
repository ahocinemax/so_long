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

void	ft_search_player(t_sl *sl)
{
	int	x;
	int	y;

	x = 1;
	while (x < sl->map.large)
	{
		y = 1;
		while (y < sl->map.longu)
		{
			if (sl->map.map[x][y] == 'P')
			{
				sl->player.i = x;
				sl->player.x = x;
				sl->player.j = y;
				sl->player.y = y;
			}
			else if (sl->map.map[x][y] == 'C')
				sl->sprite_nb++;
			y++;
		}
		x++;
	}
}

int	ft_nb_elements(int p, int c, int e)
{
	if (!p)
		;
	if (p > 1)
		;
	if (c < 1)
		;
	if (!e)
		;
	if (e > 1)
		;
}

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
		ft_close_cross(sl);
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
		ft_close_cross(sl);
	return (0);
}

int	ft_close_cross(t_sl *sl)
{
	free(sl);
	exit(EXIT_SUCCESS);
}
