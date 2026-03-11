/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_malloc_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:58:38 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/11 17:58:40 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_malloc_list	**get_malloc_list(void)
{
	static t_malloc_list	*head;

	*head = NULL;
	return (&head);
}
