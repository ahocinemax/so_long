/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:38:59 by ahocine           #+#    #+#             */
/*   Updated: 2022/02/14 15:39:02 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../get_next_line/get_next_line.h"

void	ft_init_struct(t_sl *sl)
{
	sl->mlx_ptr = NULL;
	sl->win_ptr = NULL;
	sl->nb_sprite = 0;
	sl->nb_move = 0;
	sl->ext = NULL;
	sl->loose = 0;
	sl->nb_c = 0;
	sl->nb_p = 0;
	sl->nb_e = 0;
	sl->end = 0;
	sl->win = 0;
	sl->pv = 5;
	sl->img.address = NULL;
	ft_init_struct2(sl);
}

void	ft_init_resol(t_sl *sl)
{
	int	max_x;
	int	max_y;

	if (!sl->resol.height || !sl->resol.width)
		ft_error(sl, 1);
	sl->mlx_ptr = mlx_init();
	if (!sl->mlx_ptr)
		ft_error(sl, 0);
	if (sl->resol.height < 100 || sl->resol.width < 100)
	{
		ft_putstr_fd("Resolution trop faible.\n", _STD_OUT);
		sl->resol.height = 400;
		sl->resol.width = 400;
	}
	mlx_get_screen_size(sl->mlx_ptr, &max_x, &max_y);
	if (sl->resol.height > max_y)
	{
		ft_putstr_fd("Resolution trop grande. Redimentionnement.\n", _STD_OUT);
		sl->resol.height = max_y;
	}
	if (sl->resol.width > max_x)
	{
		ft_putstr_fd("Resolution trop grande. Redimentionnement.\n", _STD_OUT);
		sl->resol.width = max_x;
	}
}

void	ft_size_map(int fd, t_sl *sl)
{
	char	*line;

	line = get_next_line(fd);
	sl->map.large = ft_strlen(line) - 1;
	while (line && *line)
	{
		sl->map.longu++;
		free(line);
		line = get_next_line(fd);
	}
	if (line && *line)
		sl->map.longu++;
	free(line);
}

void	ft_fill_map(int fd, t_sl *sl)
{
	char	*line;
	int		i;
	int		y;

	line = NULL;
	i = 0;
	sl->map.map = (char **)malloc(sizeof(char *) * (sl->map.longu + 1));
	while (i < sl->map.longu)
		sl->map.map[i++] = (char *)malloc(sizeof(char) * (sl->map.large + 1));
	line = get_next_line(fd);
	while (line && *line && *line != '\n')
	{
		if (ft_strlen(line) - 1 != sl->map.large)
			ft_error(sl, 2);
		y = -1;
		while (++y < sl->map.large)
			sl->map.map[sl->map.x][y] = line[y];
		sl->map.map[sl->map.x][y] = 0;
		free(line);
		line = get_next_line(fd);
		sl->map.x++;
	}
	free(line);
	sl->map.map[sl->map.longu] = NULL;
	ft_check_border_map(sl, sl->map.map, sl->map);
}

int	main(int argc, char **argv)
{
	t_sl	sl;
	int		fd;

	if (argc != 2)
		ft_error(NULL, 3);
	argv++;
	fd = open(*argv, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Map introuvable.\n", _STD_ERR);
		exit(EXIT_FAILURE);
	}
	ft_init_struct(&sl);
	ft_init_resol(&sl);
	ft_check_args(&sl, argv);
	ft_size_map(fd, &sl);
	close(fd);
	fd = open(*argv, O_RDONLY);
	ft_fill_map(fd, &sl);
	close(fd);
	ft_start_game(&sl);
	return (EXIT_SUCCESS);
}
