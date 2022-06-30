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

void	ft_check_nb_elements(t_sl *sl, int p, int c, int e)
{
	if (p != 1 || c < 1 || e != 1)
	{
		if (p > 1)
		{
			ft_putstr_fd("IL FAUT EXACTEMENT 1 JOUEUR. ", _STD_ERR);
			ft_putnbr_fd(p, _STD_ERR);
			ft_putstr_fd(" ONT ETE TROUVES.\n", _STD_ERR);
		}
		else if (!p)
			ft_putstr_fd("VOUS AVEZ OUBLIE LE JOUEUR.\n", _STD_ERR);
		if (c < 1)
			ft_putstr_fd("IL MANQUE LES COLLECTIBLES !\n", _STD_ERR);
		if (!e || e > 1)
			ft_putstr_fd("IL FAUT EXACTEMENT 1 SORTIE.\n", _STD_ERR);
		ft_error(sl, -1);
	}
}

static void	ft_pixel(t_pixel *pixel)
{
	pixel->right_pxl = 0;
	pixel->case_h = 0;
	pixel->case_w = 0;
}

void	ft_init_draw(t_sl *sl)
{
	sl->iend.case_w = sl->resol.width / 3;
	sl->iend.case_h = sl->resol.height / 3;
	sl->el.case_h = sl->resol.height / sl->map.longu;
	sl->el.case_w = sl->resol.width / sl->map.large;
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
	sl->resol.height = 600;
	sl->resol.width = 600;
}
