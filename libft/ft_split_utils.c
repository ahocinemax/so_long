/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:03:02 by ahocine           #+#    #+#             */
/*   Updated: 2022/02/14 19:24:06 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_all2(char **split)
{
	int	i;

	i = 0;
	if (split)
		while (split[i])
			free(split[i++]);
	free(split);
	split = NULL;
}
