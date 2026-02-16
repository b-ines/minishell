/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:24:29 by inbeaumo          #+#    #+#             */
/*   Updated: 2025/11/19 18:29:03 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	if (num != 0 && (size * num) / num != size)
		return (0);
	ptr = malloc(num * size);
	if (!ptr)
		return ((void *)0);
	ft_bzero(ptr, size * num);
	return (ptr);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char *ft_str = ft_calloc(5, 1);
	char *str = calloc(5, 1);
	printf("memcmp: %d\n", memcmp(ft_str, str, 10));
	free(ft_str);
	free(str);
	return (0);
}
*/
