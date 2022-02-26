/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:39:10 by ahocine           #+#    #+#             */
/*   Updated: 2022/02/26 11:14:19 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    ft_fill_background(t_sl *sl, int i, int j, t_texture *txture)
{
    int background;

    sl->d.top_pxl = i * sl->el.case_h;
    sl->d.down_pxl = (i + 1) * sl->el.case_h;
    sl->d.pos_x = j * sl->el.case_w;
    background = get_pixel_color(txture, 0, 0);
    ft_draw_bg(sl, txture, background);
}

void    ft_fill_element(t_sl *sl, int i, int j, t_texture *txture)
{
    sl->d.top_pxl = i * sl->el.case_h;
    sl->d.down_pxl = (i + 1) * sl->el.case_h;
    sl->d.pos_x = j * sl->el.case_w;
    ft_draw_pxl(sl, txture);
}

int ft_get_pxl_color(t_texture *txture, int x, int y)
{
    char    *dst;

    if (x < 0)
        x = 0;
    if (y < 0)
        y = 0;
    if (x > txture->width)
        x = txture->width;
    if (y > txture->height)
        y = txture->height;
    dst = txture->img.address + (y * txture->img.line_l + x * \
        txture->img.bpx / 8);
    return (*(unsigned int *)dst);
}

void    ft_init_img(t_sl *sl)
{
    sl->img.img = mlx_new_image(sl->mlx_ptr, sl->resol.width, \
        sl->resol.height);
    sl->img.address = mlx_get_data_addr(sl->img.img, &sl->img.bpx, \
        &sl->img.line_l, &sl->img.endian);
}

void    ft_put_elements(void)
{
    int i;
    int j;

    i = -1;
    init_img(sl);
    while (++i < sl->map.longu)
    {
        j = 0;
        while (j < sl->map.large)
        {
            if (sl->map.map[i][j] != '1')
                ft_fill_background(sl, i, j, &sl->background);
            if (sl->map.map[i][j] == 'E')
                ft_fill_element(sl, i, j, &sl->background);
            if (sl->map.map[i][j] != 'P')
                ft_fill_element(sl, i, j, &sl->player);
            if (sl->map.map[i][j] != 'C')
                ft_fill_element(sl, i, j, &sl->background);
            if (sl->map.map[i][j] == '1')
                ft_fill_element(sl, i, j, &sl->wall);
            j++;
        }
    }
    return ;
}