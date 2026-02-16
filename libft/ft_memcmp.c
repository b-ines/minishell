/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:17:52 by inbeaumo          #+#    #+#             */
/*   Updated: 2025/11/19 18:33:01 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t size)
{
	size_t			i;
	unsigned char	*ptr1_cast;
	unsigned char	*ptr2_cast;

	i = 0;
	ptr1_cast = (unsigned char *)ptr1;
	ptr2_cast = (unsigned char *)ptr2;
	if (size == 0)
		return (0);
	while (i < (size - 1) && ptr1_cast[i] == ptr2_cast[i])
		i++;
	return (ptr1_cast[i] - ptr2_cast[i]);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char s1[] = "t\200";
	char s2[] = "t\0";
	//ft_memcmp("t\200", "t\0", 2)
	//unsigned char s1[] = {0x00, 0x7F, 0x80};
	//unsigned char s2[] = {0x00, 0x7F, 0x81};
	printf("ft_memcmp: %d\n", ft_memcmp(s1, s2, 2));
	printf("memcmp: %d\n", memcmp(s1, s2, 2));
	return (0);
}
*/
