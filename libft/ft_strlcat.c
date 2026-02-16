/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:04:52 by inbeaumo          #+#    #+#             */
/*   Updated: 2025/11/19 19:26:03 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_size;
	size_t	src_size;
	size_t	fill;
	size_t	i;

	if (!dest && size == 0)
		return (0);
	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	fill = size - dest_size - 1;
	i = 0;
	if (dest_size >= size)
		return (src_size + size);
	while (src[i] && fill--)
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	return (dest_size + src_size);
}
/*
#include <bsd/string.h>
int	main(void)
{
	#include <stdio.h>
	#include <bsd/string.h>
	//char *ft_dest;
	//char *dest;
	//char test[82];
	//printf("%lu", sizeof(test));
	//ft_dest = (char *)malloc(15);
	//dest = (char *)malloc(15);
	//ft_dest[14] = 'a';
	//dest[14] = 'a';

	//char *src = "lorem ipsum";
	//printf("ft : %lu - %s\n", ft_strlcat(ft_dest, src, 0), ft_dest);
	//printf("off : %lu - %s\n", strlcat(dest, src, 0), dest);
	printf("ft_strlcat: %zu\n", ft_strlcat("", "", 0));
	printf("strlcat: %zu\n", strlcat("", "", 0));
	return (0);
}
*/