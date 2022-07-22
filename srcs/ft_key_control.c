/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 23:01:09 by ahocine           #+#    #+#             */
/*   Updated: 2022/02/12 23:01:10 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error(t_sl *sl, int code)
{
	if (code == 0)
		ft_putstr_fd("Initialisation de la mlx echoué.\n", _STD_ERR);
	else if (code == 1)
		ft_putstr_fd("Mauvaise resolution.\n", _STD_ERR);
	else if (code == 2)
		ft_putstr_fd("Map incomplete.\n", _STD_ERR);
	else if (code == 3)
		ft_putstr_fd("Usage : ./so_long [PATH_TO_VALID_MAP].\n", _STD_ERR);
	else if (code == 4)
		ft_putstr_fd("Nom de carte non valide.\n", _STD_ERR);
	else if (code == 5)
		ft_putstr_fd("Mauvaise extention.\n", _STD_ERR);
	else if (code == 6)
		ft_putstr_fd("Bords horizontaux non geres.\n", _STD_ERR);
	else if (code == 7)
		ft_putstr_fd("Bords lateraux non geres.\n", _STD_ERR);
	else if (code == 8)
		ft_putstr_fd("Caractere invalide trouve.\n", _STD_ERR);
	else if (code == 9)
		ft_putstr_fd("Le fichier n'a pas pu etre ouvert\n", _STD_ERR);
	else if (code == 10)
		ft_putstr_fd("Espace memoire insuffisant.\n", _STD_ERR);
	else if (code == 11)
		ft_putstr_fd("Ouverture de la map echouee.\n", _STD_ERR);
	ft_close_cross(sl);
}

int	ft_key_control(int key, t_sl *sl)
{
	if (key == KEY_W)
		sl->move.av = 1;
	else if (key == KEY_A)
		sl->move.left = 1;
	else if (key == KEY_S)
		sl->move.arr = -1;
	else if (key == KEY_D)
		sl->move.right = 1;
	else if (key == KEY_ESC)
		ft_close_cross(sl);
	return (0);
}

int	ft_key_control2(int key, t_sl *sl)
{
	if (key == KEY_W)
		sl->move.av = 0;
	else if (key == KEY_A)
		sl->move.left = 0;
	else if (key == KEY_S)
		sl->move.arr = 0;
	else if (key == KEY_D)
		sl->move.right = 0;
	else if (key == KEY_ESC)
		ft_close_cross(sl);
	return (0);
}

void	ft_destroy_texture(t_sl *sl)
{
	if (sl->game.img.img)
		mlx_destroy_image(sl->mlx_ptr, sl->game.img.img);
	if (sl->wall.img.img)
		mlx_destroy_image(sl->mlx_ptr, sl->wall.img.img);
	if (sl->door1.img.img)
		mlx_destroy_image(sl->mlx_ptr, sl->door1.img.img);
	if (sl->col.img.img)
		mlx_destroy_image(sl->mlx_ptr, sl->col.img.img);
	if (sl->door2.img.img)
		mlx_destroy_image(sl->mlx_ptr, sl->door2.img.img);
	if (sl->bg.img.img)
		mlx_destroy_image(sl->mlx_ptr, sl->bg.img.img);
}

int	ft_close_cross(t_sl *sl)
{
	int	i;

	i = 0;
	if (!sl)
		exit(EXIT_SUCCESS);
	if (sl && sl->map.map)
	{
		while (sl->map.longu--)
			free(sl->map.map[i++]);
		free(sl->map.map);
	}
	if (sl->win == 1 || sl->loose == 1)
		mlx_destroy_image(sl->mlx_ptr, sl->img.img);
	ft_destroy_texture(sl);
	if (sl->mlx_ptr && sl->win_ptr)
		mlx_destroy_window(sl->mlx_ptr, sl->win_ptr);
	if (sl->mlx_ptr)
	{
		mlx_destroy_display(sl->mlx_ptr);
		free(sl->mlx_ptr);
	}
	exit(EXIT_SUCCESS);
}
