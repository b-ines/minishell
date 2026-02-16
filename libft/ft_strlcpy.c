/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:46:26 by inbeaumo          #+#    #+#             */
/*   Updated: 2025/11/19 18:55:18 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	int		src_size;

	i = 0;
	src_size = 0;
	while (src[src_size])
	{	
		if (i < (size - 1) && size > 0)
		{
			dest[i] = src[i];
			i++;
		}
		src_size++;
	}
	if (size != 0)
		dest[i] = '\0';
	return (src_size);
}
/*
#include <bsd/string.h>
int	main(void)
{
	
	#include <stdio.h>
	char ft_dest[15];
	char	dest[15];
	//char *src = "Bonjour";
	printf("ft : %d - %s\n", ft_strlcpy(ft_dest, "lorem", 5), ft_dest);
	printf("strlcpy : %zu - %s\n", strlcpy(dest, "lorem", 5), dest);
	return (0);
}
*/
