/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 21:51:35 by gcourrie          #+#    #+#             */
/*   Updated: 2015/12/02 18:40:17 by gcourrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*prev;
	t_list	*begin;
	t_list	*new;

	prev = NULL;
	while (lst)
	{
		f(lst);
		new = ft_lstnew(lst->content, lst->content_size);
		if (prev)
			prev->next = new;
		else
			begin = new;
		prev = new;
		lst = lst->next;
	}
	return (begin);
}
