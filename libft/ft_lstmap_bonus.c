/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:34:34 by inbeaumo          #+#    #+#             */
/*   Updated: 2025/11/21 16:03:41 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*temp;
	void	*ptr;

	list = 0;
	while (lst)
	{
		ptr = f(lst->content);
		if (!ptr)
		{
			ft_lstclear(&list, del);
			return (0);
		}
		temp = ft_lstnew(ptr);
		if (!temp)
		{
			del(ptr);
			ft_lstclear(&list, del);
			return (0);
		}
		ft_lstadd_back(&list, temp);
		lst = lst->next;
	}
	return (list);
}
