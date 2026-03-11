/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all_malloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:59:17 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/11 17:59:18 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_free_all_malloc(void)
{
	t_malloc_list	**malloc_list;
	t_malloc_list	*node_to_free;

	malloc_list = get_malloc_list();
	while ((*malloc_list) != NULL)
	{
		node_to_free = *malloc_list;
		*malloc_list = (*malloc_list)->next;
		if (node_to_free->ptr)
			free(node_to_free->ptr);
		free(node_to_free);
	}
}
