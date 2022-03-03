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
	if (ft_strlen(*argv) < 4)
	{
		ft_putstr_fd("Mauvais nom.\n", _STD_ERR);
		exit(EXIT_FAILURE);
	}
	sl->ext = ft_substr(*argv, ft_strlen(*argv) - 4, ft_strlen(*argv));
	//ft_putstr_fd("OK!!\n", _STD_OUT);
	if (ft_strncmp(".ber", sl->ext, 4))
	{
		ft_putstr_fd("Mauvaise extention.\n", _STD_ERR);
		exit(EXIT_FAILURE);
	}
	free(sl->ext);
}

int	ft_char_valid(char c)
{
	//printf("c = %c\n", c);
	return (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P');
}

void	ft_check_border_map(char **map, t_map m)
{
	int	i;

	i = -1;
	while (++i < m.longu)
	{
		if (map[i][0] != '1' || map[i][m.large - 1] != '1')
		{
			ft_putstr_fd("Bords lateraux non geres.\n", _STD_ERR);
			exit(EXIT_FAILURE);
		}
	}	i = -1;
	while (++i < m.large)
	{
		if ((map[0][i] != '1' || map[m.longu - 1][i] != '1'))
		{
			ft_putstr_fd("Bords non geres.\n", _STD_ERR);
			exit(EXIT_FAILURE);
		}
	}
}

void	ft_check_inside_map(char **map, t_map m, t_sl *sl)
{
	int	x;
	int	y;

	x = -1;
	while (++x < m.longu)
	{
		y = -1;
		while (++y < m.large)
		{
			if (!ft_char_valid(map[x][y]))
			{
				ft_putstr_fd("Caractere invalide trouve.\n", _STD_ERR);
				exit(EXIT_FAILURE);
			}
			if (map[x][y] == 'P')
				sl->nb_p++;
			else if (map[x][y] == 'C')
				sl->nb_c++;
			else if (map[x][y] == 'E')
				sl->nb_e++;
		}
	}
	ft_check_nb_elements(sl->nb_p, sl->nb_c, sl->nb_e);
}
