/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:46:55 by inbeaumo          #+#    #+#             */
/*   Updated: 2025/11/19 18:25:30 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dest && !src && size > 0)
		return (0);
	while (i < size)
	{
		((unsigned char *) dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	#include <stdio.h>
	#include <string.h>
	
	char ft_src[] = "coucou ca va";
	char ft_dest[14];
	char src[] = "coucou ca va";
	char dest[14];
	printf("pre ft : %s\n pre str : %s\n", ft_src, src);
	ft_memcpy(ft_dest, ft_src, 10);
	memcpy(dest, src, 10);
	printf("post ft : %s\npost mem : %s\n", ft_dest, dest);
}
*/
