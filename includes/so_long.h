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

typedef struct s_draw
{
	float				txture_x;
	float				txture_y;
	float				down_pxl;
	float				top_pxl;
	float				pos_x;
}				t_draw;

typedef struct s_color
{
	int					r;
	int					g;
	int					b;
	int					hex;
}				t_color;

typedef struct s_sl
{
	t_texture			door1;
	t_texture			door2;
	t_texture			game;
	t_texture			wall;
	t_texture			col;
	t_texture			bg;
	t_player			player;
	t_image				img;
	t_resol				resol;
	t_pixel				iend;
	t_pixel				el;
	t_move				move;
	t_draw				d;
	t_map				map;
	int					nb_sprite;
	void				*mlx_ptr;
	void				*win_ptr;
	int					nb_move;
	int					loose;
	char				*ext;
	int					nb_c;
	int					nb_e;
	int					nb_p;
	int					end;
	int					win;
	int					pv;
}				t_sl;

void	ft_fill_background(t_sl *solong, int i, int j, t_texture *texture);
void	ft_fill_element(t_sl *solong, int i, int j, t_texture *texture);
void	ft_draw_bg(t_sl *solong, t_texture *texture, int background);
void	ft_image_pixel(t_image *image, int x, int y, int color);
void	ft_check_inside_map(char **map, t_map m, t_sl *solong);
void	ft_check_border_map(t_sl *solong, char **map, t_map m);
int		ft_get_pxl_color(t_texture *txture, int x, int y);
int		ft_freeze_player(t_sl *solong, int x, int y);
void	ft_draw_pxl(t_sl *solong, t_texture *txture);
void	ft_play_rules(t_sl *solong, int	x, int y);
void	ft_check_nb_elements(int p, int c, int e);
void	ft_check_args(t_sl *solong, char **argv);
int		ft_key_control2(int key, t_sl *solong);
void	ft_error(t_sl *solong, int error_code);
int		ft_key_control(int key, t_sl *solong);
void	ft_move(t_sl *solong, int x, int y);
void	ft_size_map(int fd, t_sl *solong);
void	ft_fill_map(int fd, t_sl *solong);
void	ft_check_end_game(t_sl *solong);
void	ft_texture(t_texture *texture);
void	ft_search_player(t_sl *solong);
void	ft_put_elements(t_sl *solong);
void	ft_init_texture(t_sl *solong);
void	ft_init_struct2(t_sl *solong);
void	ft_init_struct(t_sl *solong);
void	ft_destroy_texture(t_sl *sl);
void	ft_nb_elements(t_sl *solong);
int		ft_close_cross(t_sl *solong);
void	ft_init_resol(t_sl *solong);
void	ft_start_game(t_sl *solong);
void	ft_left_right(t_sl *solong);
void	ft_init_draw(t_sl *solong);
void	ft_init_img(t_sl *solong);
void	ft_up_down(t_sl *solong);
int		ft_play(t_sl *solong);
int		ft_char_valid(char c);

#endif
