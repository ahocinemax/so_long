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

typedef struct	s_move
{
	int					av;
	int					left;
	int					arr;
	int					right;
}						t_move;


typedef struct s_sl
{
	double				speed_move;
	t_move				move;
}	t_sl;

# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100

#endif
