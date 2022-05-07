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

static void	ft_error2(t_sl *sl, int code)
{
	if (code == 5)
		ft_putstr_fd("Mauvaise extention.\n", _STD_ERR);
	else if (code == 6)
		ft_putstr_fd("Bords non geres.\n", _STD_ERR);
	else if (code == 7)
		ft_putstr_fd("Bords lateraux non geres.\n", _STD_ERR);
	else if (code == 8)
		ft_putstr_fd("Caractere invalide trouve.\n", _STD_ERR);
	else if (code == 9)
		ft_putstr_fd("Le fichier n'a pas pu etre ouvert\n", _STD_ERR);
	else if (code == -1)
		ft_close_cross(sl);
}

void	ft_error(t_sl *sl, int code)
{
	int	i;

	i = 0;
	if (sl && sl->map.map)
	{
		while (sl->map.longu--)
			free(sl->map.map[i++]);
		free(sl->map.map);
	}
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
	else
		ft_error2(sl, code);
	if (sl->mlx_ptr && sl->win_ptr)
		mlx_destroy_window(sl->mlx_ptr, sl->win_ptr);
	if (sl->win_ptr)
		mlx_destroy_display(sl->mlx_ptr);
	exit(EXIT_FAILURE);
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

int	ft_close_cross(t_sl *sl)
{
	int	i;

	i = 0;
	if (sl && sl->map.map)
	{
		while (sl->map.longu--)
			free(sl->map.map[i++]);
		free(sl->map.map);
	}
	ft_destroy_texture(sl);
	mlx_destroy_window(sl->mlx_ptr, sl->win_ptr);
	mlx_destroy_image(sl->mlx_ptr, sl->img.img);
	mlx_destroy_display(sl->mlx_ptr);
	free(sl->mlx_ptr);
	exit(EXIT_SUCCESS);
}
