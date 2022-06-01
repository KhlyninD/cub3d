/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:00:44 by bbellatr          #+#    #+#             */
/*   Updated: 2022/05/30 16:00:44 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_elem;
	t_list	*temp;
	t_list	*temp2;

	if (!lst)
		return (NULL);
	first_elem = ft_lstnew((*f)(lst->content));
	if (!first_elem)
		return (NULL);
	temp = first_elem;
	lst = lst->next;
	while (lst)
	{
		temp2 = ft_lstnew((*f)(lst->content));
		if (!temp2)
		{
			ft_lstclear(&first_elem, del);
			return (NULL);
		}
		temp->next = temp2;
		temp = temp->next;
		lst = lst->next;
	}
	return (first_elem);
}
