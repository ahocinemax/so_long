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

void	ft_init_struct(t_sl *sl)
{
	sl->nb_c = 0;
	sl->nb_p = 0;
	sl->nb_e = 0;
	sl->map.x = 0;
	sl->map.y = 0;
	sl->player.x = 0;
	sl->player.y = 0;
	sl->map.large = 0;
	sl->map.longu = 1;
	sl->move.av = 0;
	sl->move.arr = 0;
	sl->move.left = 0;
	sl->move.right = 0;
	sl->speed_move = 0;
	sl->map.map = NULL;
	sl->resol.height = 900;
	sl->resol.width = 900;
}

void	ft_init_resol(t_sl *sl)
{
	int	max_x;
	int	max_y;

	if (!sl->resol.height || !sl->resol.width)
		return ;
	if (sl->resol.height < 100 || sl->resol.width < 100)
	{
		ft_putstr_fd("Resolution trop faible, redimentionnement \
		a 100 * 100.\n", _STD_OUT);
		sl->resol.height = 100;
		sl->resol.width = 100;
	}
	if (sl->resol.height > max_y)
	{
		ft_putstr_fd("Trop grand, redimentionnement automatique.\n", _STD_OUT);
		sl->resol.height = max_y;
	}
	if (sl->resol.width > max_x)
	{
		ft_putstr_fd("Trop grand, redimentionnement automatique.\n", _STD_OUT);
		sl->resol.width = max_x;
	}
}

void	ft_fill_map(int fd, t_sl *sl)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	sl->map.map = (char **)malloc(sizeof(char *) * (sl->map.longu + 1));
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) != sl->map.large)
			return ;
		sl->map.map[sl->map.x] = line;
		sl->map.x++;
	}
	if (!*line)
		free(line);
	sl->map.map[sl->map.large] = NULL;
	ft_check_border_map(sl->map.map, sl->map);
	ft_check_inside_map(sl->map.map, sl->map, sl);
}

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

void	ft_size_map(int fd, t_sl *sl)
{
	char	*line;

	line = get_next_line(fd);
	sl->map.large = ft_strlen(line);
	while (line && *line)
	{
		free(line);
		line = NULL;
		sl->map.longu++;
		line = get_next_line(fd);
	}
	if (*line)
		sl->map.longu++;
	free(line);
}

int	ft_nb_elements(int p, int c, int e)
{
	if (!p)
		;
	if (p > 1)
		;
	if (c < 1)
		;
	if (!e)
		;
	if (e > 1)
		;
}

int	ft_key_control(int key, t_sl *sl)
{
	sl->speed_move = 0.2;
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
	sl->speed_move = 0.2;
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
	free(sl);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_sl	sl;
	int		fd;

	if (argc != 2)
		return (EXIT_FAILURE);
	argv++;
	ft_init_struct(&sl);
	ft_init_resol(&sl);
	ft_check_args(&sl, argv);
	fd = open(*argv, O_RDONLY);
	if (fd == -1)
		return (-1);
	ft_map_size(fd, &sl);
	close(fd);
	fd = open(*argv, O_RDONLY);
	ft_fill_map(fd, &sl);
	close(fd);
	return (EXIT_SUCCESS);
}
