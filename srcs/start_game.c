/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 02:53:16 by ahocine           #+#    #+#             */
/*   Updated: 2022/02/23 02:53:19 by ahocine          ###   ########.fr       */
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

void	ft_init_draw(t_sl *sl)
{
	sl->iend.case_w = sl->resol.width / 3;
	sl->iend.case_h = sl->resol.height / 3;
	sl->el.case_h = sl->resol.height / sl->map.longu;
	sl->el.case_w = sl->resol.width / sl->map.large;
}

void	ft_init_texture(t_sl *sl)
{
	sl->game.img.img = mlx_xpm_file_to_image(sl->mlx_ptr, "./img/player.xpm", \
		&sl->game.width, &sl->game.height);
	sl->game.img.address = mlx_get_data_addr(sl->game.img.img, \
		&sl->game.img.bpx, &sl->game.img.line_l, &sl->game.img.endian);
	sl->wall.img.img = mlx_xpm_file_to_image(sl->mlx_ptr, "./img/wall.xpm", \
		&sl->wall.width, &sl->wall.height);
	sl->wall.img.address = mlx_get_data_addr(sl->wall.img.img, \
		&sl->wall.img.bpx, &sl->wall.img.line_l, &sl->wall.img.endian);
	sl->door1.img.img = mlx_xpm_file_to_image(sl->mlx_ptr, "./img/door1.xpm", \
		&sl->door1.width, &sl->door1.height);
	sl->door1.img.address = mlx_get_data_addr(sl->door1.img.img, \
		&sl->door1.img.bpx, &sl->door1.img.line_l, &sl->door1.img.endian);
	sl->door2.img.img = mlx_xpm_file_to_image(sl->mlx_ptr, "./img/door2.xpm", \
		&sl->door2.width, &sl->door2.height);
	sl->door2.img.address = mlx_get_data_addr(sl->door2.img.img, \
		&sl->door2.img.bpx, &sl->door2.img.line_l, &sl->door2.img.endian);
	sl->back.img.img = mlx_xpm_file_to_image(sl->mlx_ptr, "./img/back.xpm", \
		&sl->back.width, &sl->back.height);
	sl->back.img.address = mlx_get_data_addr(sl->back.img.img, \
		&sl->back.img.bpx, &sl->back.img.line_l, &sl->back.img.endian);
}

void	ft_start_game(t_sl *sl)
{
	sl->win_ptr = mlx_new_window(sl->mlx_ptr, sl->resol.width, \
	sl->resol.height, "./so_long");
	ft_search_player(sl);
	ft_init_draw(sl);
	ft_init_texture(sl);
	mlx_hook(sl->win_ptr, 2, 1L << 0, ft_key_control, sl);
	mlx_hook(sl->win_ptr, 3, 1L << 0, ft_key_control2, sl);
	mlx_loop_hook(sl->mlx_ptr, /*ft_play*/NULL, sl);
	mlx_hook(sl->win_ptr, 33, 1L, ft_close_cross, sl);
	mlx_loop(sl->mlx_ptr);
	return ;
}
