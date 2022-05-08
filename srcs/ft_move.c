/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:39:53 by ahocine           #+#    #+#             */
/*   Updated: 2022/02/28 18:39:56 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_freeze_player(t_sl *sl, int x, int y)
{
	return ((sl->map.map[x][y] == '1') || (sl->map.map[x][y] == '2'));
}

void	ft_play_rules(t_sl *sl, int x, int y)
{
	if (sl->map.map[sl->player.i][sl->player.j] == 'E')
	{
		ft_fill_background(sl, x, y, &sl->bg);
		ft_fill_element(sl, sl->player.i, sl->player.j, &sl->door2);
		ft_check_end_game(sl);
	}
	else if (sl->map.map[sl->player.i][sl->player.j] == 'C')
		sl->nb_sprite--;
}

void	ft_move(t_sl *sl, int x, int y)
{
	int	a;
	int	b;

	a = sl->player.i;
	b = sl->player.j;
	sl->nb_move++;
	ft_putnbr_fd(sl->nb_move, _STD_OUT);
	ft_putchar_fd('\n', _STD_OUT);
	sl->map.map[sl->player.i][sl->player.j] = '0';
	sl->player.i = x;
	sl->player.j = y;
	if (sl->map.map[x][y] == 'E' || sl->map.map[x][y] == 'C')
		ft_play_rules(sl, a, b);
	sl->map.map[x][y] = 'P';
}

void	ft_up_down(t_sl *sl)
{
	int		tmp_x;
	int		tmp_y;

	tmp_x = sl->player.i;
	tmp_y = sl->player.j;
	if (sl->move.av && !ft_freeze_player(sl, sl->player.i - 1, sl->player.j))
		ft_move(sl, tmp_x - 1, tmp_y);
	if (sl->move.arr && !ft_freeze_player(sl, sl->player.i + 1, sl->player.j))
		ft_move(sl, tmp_x + 1, tmp_y);
	if (sl->nb_move >= 70 && (sl->move.arr || sl->move.av))
	{
		ft_putstr_fd("GAME OVER - NOMBRE DE MVMT MAX DEPASSE\n", _STD_OUT);
		ft_close_cross(sl);
	}
	sl->move.arr = 0;
	sl->move.av = 0;
}

void	ft_left_right(t_sl *sl)
{
	int		tmp_x;
	int		tmp_y;

	tmp_x = sl->player.i;
	tmp_y = sl->player.j;
	if (sl->move.left && !ft_freeze_player(sl, sl->player.i, sl->player.j - 1))
		ft_move(sl, tmp_x, tmp_y - 1);
	if (sl->move.right && !ft_freeze_player(sl, sl->player.i, sl->player.j + 1))
		ft_move(sl, tmp_x, tmp_y + 1);
	if (sl->nb_move >= 70 && (sl->move.left || sl->move.right))
	{
		ft_putstr_fd("GAME OVER - NOMBRE DE MVMT MAX DEPASSE\n", _STD_OUT);
		ft_close_cross(sl);
	}
	sl->move.left = 0;
	sl->move.right = 0;
}
