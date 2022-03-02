/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 22:12:33 by ahocine           #+#    #+#             */
/*   Updated: 2021/06/28 22:12:34 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!new)
		return ;
	if (!*alst)
	{
		*alst = new;
		(*alst)->prev = NULL;
		(*alst)->next = NULL;
	}
	else
	{
		new->prev = NULL;
		new->next = *alst;
		(*alst)->prev = new;
		*alst = new;
	}
}
