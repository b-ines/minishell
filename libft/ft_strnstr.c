/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:47:42 by inbeaumo          #+#    #+#             */
/*   Updated: 2025/11/19 18:28:14 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *search, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_find[i] == '\0')
		return ((char *)search);
	while (i < len && search[i])
	{
		j = 0;
		while (search[i + j] == to_find[j] && to_find[j] && (i + j) < len)
		{
			if (to_find[j + 1] == '\0')
				return ((char *)(search + i));
			j++;
		}
		i++;
	}
	return ((void *)0);
}
/*
#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
	const char search[] = "ca coucou ca va";
	const char to_find[] = "ca";
	printf("ft_strnstr : %s\n", ft_strnstr("lorem ipsum dolor sit amet", "", 10));
	printf("strnstr : %s\n", strnstr("lorem ipsum dolor sit amet", "", 10));
	return (0);
}
*/
