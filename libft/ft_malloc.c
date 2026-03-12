/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:00:53 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/12 15:01:37 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static t_malloc_list	*create_malloc_node(void *ptr)
{
	t_malloc_list	*node;

	node = malloc(sizeof(t_malloc_list));
	if (node == NULL)
	{
		free(ptr);
		return (NULL);
	}
	node->ptr = ptr;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

static int	append_malloc_node(t_malloc_list **malloc_list, t_malloc_list *node)
{
	t_malloc_list	*it;

	if (malloc_list == NULL)
		return (free(node->ptr), free(node), 0);
	if (*malloc_list == NULL)
		*malloc_list = node;
	else
	{
		it = *malloc_list;
		while (it->next != NULL)
			it = it->next;
		it->next = node;
		node->prev = it;
	}
	return (1);
}

void	*ft_malloc(unsigned int size)
{
	void			*ptr;
	t_malloc_list	*node;

	ptr = malloc(size);
	if (!ptr)
		return (0);
	node = create_malloc_node(ptr);
	if (node == NULL)
		return (NULL);
	if (!append_malloc_node(get_malloc_list(), node))
		return (NULL);
	return (ptr);
}
