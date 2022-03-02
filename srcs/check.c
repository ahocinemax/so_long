/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:39:10 by ahocine           #+#    #+#             */
/*   Updated: 2022/02/14 15:39:12 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_end_game(t_sl *sl)
{
	if (sl->nb_sprite)
	{
		ft_putstr_fd("GAME OVER - TOUS N'A PAS ETE RAMASSE\n", _STD_OUT);
		sl->loose = 1;
	}
	else
	{
		ft_putstr_fd("C'EST GAGNE !\n", _STD_OUT);
		sl->win = 1;
	}
}

void	ft_check_args(t_sl *sl, char **argv)
{
	int	i;

	i = 0;
	if (ft_strlen(*argv) < 4)
		return ;
	while (*argv[i])
		i++;
	sl->ext = ft_substr(*argv, ft_strlen(*argv) - 4, ft_strlen(*argv));
	if (ft_strncmp(".ber", sl->ext, 4))
		return ;
	free(sl->ext);
}

int	ft_char_valid(char c)
{
	return (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P');
}

int	ft_check_border_map(char **map, t_map m)
{
	int	x_max;
	int	y_max;
	int	i;

	i = 0;
	x_max = m.large;
	y_max = m.longu;
	while (i < x_max)
	{
		if (map[0][i] != '1' || map[x_max - 1][i] != '1')
			return (-1);
		i++;
	}
	i = 0;
	while (i < y_max)
	{
		if (map[i][0] != '1' || map[i][y_max - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_check_inside_map(char **map, t_map m, t_sl *sl)
{
	int	x;
	int	y;

	x = 0;
	while (x < m.large)
	{
		y = 0;
		while (y < m.longu)
		{
			if (!ft_char_valid(map[x][y]))
				return (-1);
			if (map[x][y] == 'P')
				sl->nb_p++;
			else if (map[x][y] == 'C')
				sl->nb_c++;
			else if (map[x][y] == 'E')
				sl->nb_e++;
			y++;
		}
		x++;
	}
	ft_check_nb_elements(sl->nb_p, sl->nb_c, sl->nb_e);
}
