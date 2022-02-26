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

void	ft_init_struct(t_sl *sl)
{
	sl->speed_move 			= 0;
	sl->sprite_nb			= 0;
	sl->ext 				= NULL;
	sl->loose 				= 0;
	sl->nb_c 				= 0;
	sl->nb_p				= 0;
	sl->nb_e				= 0;
	sl->end 				= 0;
	sl->win 				= 0;
	sl->map.x				= 0;
	sl->map.y 				= 0;
	sl->map.map 			= NULL;
	sl->map.large 			= 0;
	sl->map.longu 			= 1;
	sl->player.x 			= 0;
	sl->player.y 			= 0;
	sl->move.av 			= 0;
	sl->move.arr 			= 0;
	sl->move.left 			= 0;
	sl->move.right 			= 0;
	sl->game.width 			= 0;
	sl->game.height 		= 0;
	sl->game.img.address 	= NULL;
	sl->resol.height 		= 900;
	sl->resol.width 		= 900;
}

void	ft_init_resol(t_sl *sl)
{
	int	max_x;
	int	max_y;

	if (!sl->resol.height || !sl->resol.width)
		return ;
	sl->mlx_ptr = mlx_init();
	if (sl->resol.height < 100 || sl->resol.width < 100)
	{
		ft_putstr_fd("Resolution trop faible, redimentionnement \
		a 100 * 100.\n", _STD_OUT);
		sl->resol.height = 100;
		sl->resol.width = 100;
	}
	mlx_get_screen_size(sl->mlx_ptr, &max_x, &max_y);
	if (sl->resol.height > max_y)
	{
		ft_putstr_fd("Resolution trop grande, redimentionnement \
		automatique.\n", _STD_OUT);
		sl->resol.height = max_y;
	}
	if (sl->resol.width > max_x)
	{
		ft_putstr_fd("Resolution trop grande, redimentionnement \
		automatique.\n", _STD_OUT);
		sl->resol.width = max_x;
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
	ft_start_game(&sl);
	return (EXIT_SUCCESS);
}
