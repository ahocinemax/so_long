/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:46:44 by ahocine           #+#    #+#             */
/*   Updated: 2022/03/06 19:46:46 by ahocine          ###   ########.fr       */
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

static void	ft_pixel(t_pixel *pixel)
{
	pixel->right_pxl = 0;
	pixel->case_h = 0;
	pixel->case_w = 0;
}

static void	ft_draw(t_draw *draw)
{
	draw->txture_x = 0;
	draw->txture_y = 0;
	draw->down_pxl = 0;
	draw->top_pxl = 0;
	draw->pos_x = 0;
}

void	ft_init_struct2(t_sl *sl)
{
	sl->move.right = 0;
	sl->move.left = 0;
	sl->move.arr = 0;
	sl->move.av = 0;
	sl->map.map = NULL;
	sl->map.large = 0;
	sl->map.longu = 0;
	sl->player.x = 0;
	sl->player.y = 0;
	sl->map.x = 0;
	sl->map.y = 0;
	ft_pixel(&sl->iend);
	ft_pixel(&sl->el);
	ft_draw(&sl->d);
	ft_texture(&sl->game);
	ft_texture(&sl->wall);
	ft_texture(&sl->col);
	ft_texture(&sl->bg);
	ft_texture(&sl->door1);
	ft_texture(&sl->door2);
	sl->resol.height = 650;
	sl->resol.width = 900;
}

void	ft_destroy_texture(t_sl *sl)
{
	mlx_destroy_image(sl->mlx_ptr, sl->game.img.img);
	mlx_destroy_image(sl->mlx_ptr, sl->wall.img.img);
	mlx_destroy_image(sl->mlx_ptr, sl->door1.img.img);
	mlx_destroy_image(sl->mlx_ptr, sl->col.img.img);
	mlx_destroy_image(sl->mlx_ptr, sl->door2.img.img);
	mlx_destroy_image(sl->mlx_ptr, sl->bg.img.img);
}
