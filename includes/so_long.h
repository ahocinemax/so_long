/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 22:59:59 by ahocine           #+#    #+#             */
/*   Updated: 2022/02/12 23:00:01 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"

typedef struct s_move
{
	int					av;
	int					left;
	int					arr;
	int					right;
}						t_move;

typedef struct s_map
{
	int					x;
	int					y;
	int					large;
	int					longu;
	char				**map;
}				t_map;

typedef struct s_resol
{
	int					height;
	int					width;
}				t_resol;

typedef struct s_player
{
	int					x;
	int					y;
	int					i;
	int					j;
}				t_player;

typedef struct s_sl
{
	double				speed_move;
	int					sprite_nb;
	char				*ext;
	int					nb_c;
	int					nb_e;
	int					nb_p;
	t_resol				resol;
	t_player			player;
	t_move				move;
	t_map				map;
}				t_sl;

# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100

#endif
