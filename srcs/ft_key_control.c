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

void	ft_check_nb_elements(int p, int c, int e)
{
	if (!p || p > 1 || c < 1 || !e || e > 1)
	{
		if (!p || p > 1)
			ft_putstr_fd("IL FAUT EXACTEMENT 1 JOUEUR.\n", _STD_ERR);
		if (c < 1)
			ft_putstr_fd("IL MANQUE LE SPRITE !\n", _STD_ERR);
		if (!e || e > 1)
			ft_putstr_fd("IL FAUT EXACTEMENT 1 SORTIE.\n", _STD_ERR);
		ft_error(NULL, -1);
	}
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
	int	i;

	i = 0;
	if (sl && sl->map.map)
	{
		while (sl->map.longu--)
			free(sl->map.map[i++]);
		free(sl->map.map);
	}
	exit(EXIT_SUCCESS);
}
