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

int	ft_play(t_sl *sl)
{
	if (!sl->win && !sl->loose && sl->pv && sl->nb_move <= 65)
	{
		ft_put_elements(sl);
		ft_up_down(sl);
		ft_left_right(sl);
		mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr, sl->img.img, 0, 0);
		mlx_destroy_image(sl->mlx_ptr, sl->img.img);
	}
	return (0);
}

void	ft_search_player(t_sl *sl)
{
	int	x;
	int	y;

	x = 1;
	while (x < sl->map.longu)
	{
		y = 1;
		while (y < sl->map.large)
		{
			if (sl->map.map[x][y] == 'P')
			{
				sl->player.i = x;
				sl->player.x = x;
				sl->player.j = y;
				sl->player.y = y;
			}
			else if (sl->map.map[x][y] == 'C')
				sl->nb_sprite++;
			y++;
		}
		x++;
	}
}

static void	ft_fill_struct(t_sl *sl, t_texture *texture, char *path_to_file)
{
	int	fd1;
	int	fd2;

	fd1 = open(path_to_file, __O_DIRECTORY);
	fd2 = open(path_to_file, O_RDONLY);
	if (fd1 > -1)
		close(fd1);
	if (fd2 > -1)
		close(fd2);
	if (fd1 != -1 || fd2 == -1)
	{
		ft_putstr_fd(path_to_file, _STD_ERR);
		ft_putstr_fd(" introuvable", _STD_ERR);
		ft_error(sl, 10);
	}
	texture->img.img = mlx_xpm_file_to_image(sl->mlx_ptr, path_to_file, \
		&texture->width, &texture->height);
	texture->img.address = mlx_get_data_addr(texture->img.img, \
		&texture->img.bpx, &texture->img.line_l, &texture->img.endian);
}

void	ft_init_texture(t_sl *sl)
{
	ft_fill_struct(sl, &sl->game, "./img/player.xpm");
	ft_fill_struct(sl, &sl->wall, "./img/wall.xpm");
	ft_fill_struct(sl, &sl->door1, "./img/door1.xpm");
	ft_fill_struct(sl, &sl->door2, "./img/door2.xpm");
	ft_fill_struct(sl, &sl->col, "./img/col.xpm");
	ft_fill_struct(sl, &sl->bg, "./img/bg.xpm");
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
	mlx_loop_hook(sl->mlx_ptr, ft_play, sl);
	mlx_hook(sl->win_ptr, 33, 1L, ft_close_cross, sl);
	mlx_loop(sl->mlx_ptr);
}
