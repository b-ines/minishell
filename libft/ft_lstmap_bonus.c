/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lmap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:34:34 by inbeaumo          #+#    #+#             */
/*   Updated: 2025/11/21 16:03:41 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lmap(t_list *l, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*temp;
	void	*ptr;

	list = 0;
	while (l)
	{
		ptr = f(l->content);
		if (!ptr)
		{
			ft_lclear(&list, del);
			return (0);
		}
		temp = ft_lnew(ptr);
		if (!temp)
		{
			del(ptr);
			ft_lclear(&list, del);
			return (0);
		}
		ft_ladd_back(&list, temp);
		l = l->next;
	}
	return (list);
}
