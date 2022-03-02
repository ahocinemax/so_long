/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 22:13:01 by ahocine           #+#    #+#             */
/*   Updated: 2021/06/28 22:13:02 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*element;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		element = ft_lstlast(*lst);
		element->next = new;
		new->prev = element;
		new->next = NULL;
	}
	else
		*lst = new;
}
