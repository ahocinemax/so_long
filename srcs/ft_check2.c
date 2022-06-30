/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:11:55 by ahocine           #+#    #+#             */
/*   Updated: 2022/06/30 14:11:58 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_malloc_map(t_sl *sl)
{
	int	i;

	i = 0;
	sl->map.map = (char **)malloc(sizeof(char *) * (sl->map.longu + 1));
	if (!sl->map.map)
		ft_error(sl, 10);
	while (i < sl->map.longu)
	{
		sl->map.map[i] = (char *)malloc(sizeof(char) * (sl->map.large + 1));
		if (!sl->map.map[i++])
			ft_error(sl, 10);
	}
}
