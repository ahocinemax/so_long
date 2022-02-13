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
	sl->map.large = 0;
	sl->map.longu = 1;
	sl->map.x = 0;
	sl->map.y = 0;
	sl->map.map = NULL;
	sl->move.arr = 0;
	sl->move.av = 0;
	sl->move.left = 0;
	sl->move.right = 0;
	sl->player.x = 0;
	sl->player.y = 0;
	sl->speed_move = 0;
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
			;
		sl->map.map[sl->map.x] = line;
		sl->map.x++;
	}
	if (!*line)
		free(line);
	sl->map.map[sl->map.large] = NULL;
	ft_check_border_map(sl->map.map, sl->map);
	ft_check_inside_map(sl->map.map, sl->map, sl);
}

int	ft_char_valid(char c)
{
	return (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P');
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
			y++;
		}
		x++;
	}
}

void	ft_check_end_game(t_sl sl)
{
	if (sl.sprite_nb)
}

int	ft_check_border_map(char **map, t_map m)
{
	int	x_max;
	int	y_max;
	int	i;

	i = 0;
	x_max = m.large;
	y_max = m.longu;
	while (i < x_max)
	{
		if (map[0][i] != '1' || map[x_max - 1][i] != '1')
			return (-1);
		i++;
	}
	i = 0;
	while (i < y_max)
	{
		if (map[i][0] != '1' || map[i][y_max - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}

void	ft_map_size(int fd, t_sl *sl)
{
	char *line;

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

int	ft_check_inside_map(char **map, t_map m, t_sl *sl)
{
	int	x;
	int	y;

	x = 0;
	while (x < m.large)
	{
		y = 0;
		while (y < m.longu)
		{
			if (!ft_char_valid(map[x][y]))
				return (-1);
			if (map[x][y] == 'P')
				sl->nb_p++;
			else if (map[x][y] == 'C')
				sl->nb_c++;
			else if (map[x][y] == 'E')
				sl->nb_e++;
			y++;
		}
		x++;
	}
	ft_nb_elements(sl->nb_p, sl->nb_c, sl->nb_e);
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
		close_cross(sl);
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
		close_cross(sl);
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
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	ft_map_size(fd, &sl);
	close(fd);
	return (0);
}