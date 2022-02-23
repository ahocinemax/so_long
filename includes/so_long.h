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
# include <mlx.h>
# include "../libft/libft.h"

# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100

typedef struct s_move
{
	int					av;
	int					left;
	int					arr;
	int					right;
}				t_move;

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

typedef struct s_pixel
{
	float				case_h;
	float				case_w;
	float				right_pxl;
}				t_pixel;

typedef struct s_image
{
	void				*img;
	char				*address;
	int					bpx;
	int					line_l;
	int					endian;
}				t_image;

typedef struct s_texture
{
	int					width;
	int					height;
	t_image				img;
}				t_texture;

typedef struct s_color
{
	int					r;
	int					g;
	int					b;
	int					hex;
}				t_color;

typedef struct s_sl
{
	t_texture			game;
	t_texture			wall;
	t_texture			door1;
	t_texture			door2;
	t_texture			back;
	t_player			player;
	t_resol				resol;
	t_pixel				iend;
	t_pixel				el;
	t_move				move;
	t_map				map;
	double				speed_move;
	int					sprite_nb;
	void				*mlx_ptr;
	void				*win_ptr;
	char				*ext;
	int					nb_c;
	int					nb_e;
	int					nb_p;
}				t_sl;

#endif
