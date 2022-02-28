/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 01:13:31 by ahocine           #+#    #+#             */
/*   Updated: 2022/02/28 01:13:34 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_image_pixel(t_image *image, int x, int y, int color)
{
	char	*res;

	res = image->address + (y * image->line_l + x * (image->bpx / 8));
	*(unsigned int *)res = color;
}

void	ft_draw_bg(t_sl *sl, t_texture *txture, int bg)
{
	int	color;
	int	x;
	int	y;
	int	k;

	x = -1;
	while (sl->d.pos_x + x < 0)
		x++;
	while (++x <= sl->el.case_w)
	{
		sl->d.txture_x = x * (txture->width / sl->el.case_w);
		y = sl->d.top_pxl - 1;
		k = -1;
		while (++y < sl->d.down_pxl)
		{
			++k;
			sl->d.top_pxl - 1;
			if (sl->d.txture_y < 0)
				sl->d.txture_y = 0;
			color = ft_get_pxl_color(txture, sl->d.txture_x, sl->d.txture_y);
			if (color != bg)
				ft_image_pixel(&sl->img, sl->d.pos_x + x, y, color);
		}
	}
}

void	ft_draw_pxl(t_sl *sl, t_texture *txture)
{
	int	color;
	int	x;
	int	y;
	int	k;

	x = -1;
	while (sl->d.pos_x + x < 0)
		x++;
	while (++x <= sl->el.case_w)
	{
		sl->d.txture_x = x * (txture->width / sl->el.case_w);
		y = sl->d.top_pxl - 1;
		k = -1;
		while (++y < sl->d.down_pxl)
		{
			++k;
			sl->d.txture_y = (k * (txture->height / sl->el.case_h));
			if (sl->d.txture_y < 0)
				sl->d.txture_y = 0;
			color = ft_get_pxl_color(txture, sl->d.txture_x, sl->d.txture_y);
			ft_image_pixel(&sl->img, sl->d.pos_x + x, y, color);
		}
	}
}
