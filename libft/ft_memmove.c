/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:10:13 by inbeaumo          #+#    #+#             */
/*   Updated: 2025/11/17 15:51:09 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char	*dest_c;

	dest_c = (unsigned char *)dest;
	if (dest == src || size == 0)
		return (dest);
	else if (dest > src && dest <= (src + size))
	{	
		while (size--)
			dest_c[size] = *(unsigned char *)(src + size);
	}
	else
		ft_memcpy(dest, src, size);
	return (dest);
}
/*
int	main(void)
{
	#include <stdio.h>
	#include <string.h>
	char ft_src[] = "a shiny white sphere";
	char src[] = "a shiny white sphere";
	printf("ft src : %s\nsrc : %s\n", ft_src, src);
	ft_memmove(ft_src + 8, ft_src + 2, 5);
	memmove(src + 8, src + 2, 5);
	printf("ft dest : %s\n dest : %s\n", ft_src, src);
	return (0);
}
*/
