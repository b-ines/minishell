/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:03:13 by inbeaumo          #+#    #+#             */
/*   Updated: 2025/11/19 18:25:03 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *search, int to_find, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if ((unsigned char)to_find % 256
			== *(unsigned char *)(search + i))
			return ((void *)(search + i));
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	main() {
	char data[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	const unsigned int size = 10;
	
	void *found = memchr(data, 57, size);
	void *ft_found = ft_memchr(data, 57, size);
	printf( "57 is %s\n", (found != NULL ? "found" : "not found" ));
	printf("ft : 57 is %s\n", (ft_found != NULL ? "found" : "not found"));
	
	found = memchr(data, 50, size);
	ft_found = ft_memchr(data, 50, size);
	printf( "50 is %s\n", (found != NULL ? "found" : "not found" ));
	printf("ft : 50 is %s\n", (ft_found != NULL ? "found" : "not found"));
	return (0);
}
*/
