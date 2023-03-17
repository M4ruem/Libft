/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:58:45 by cormiere          #+#    #+#             */
/*   Updated: 2022/10/06 12:02:30 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*elmt;
	t_list	*prev;

	if (!lst || !f || !del)
		return (0);
	new = 0;
	while (lst)
	{
		elmt = ft_lstnew(lst->content);
		if (!elmt)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		if (new == 0)
			new = elmt;
		else
			prev->next = elmt;
		elmt->content = f(elmt->content);
		prev = elmt;
		lst = lst->next;
	}
	return (new);
}
