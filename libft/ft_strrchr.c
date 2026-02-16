/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:41:12 by inbeaumo          #+#    #+#             */
/*   Updated: 2025/11/13 19:12:21 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (c % 256 == str[i])
			return ((char *)str + i);
		i--;
	}
	return ((void *)0);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char str[] = "cc ca va c cool";
	
	printf("ft: %s\n", ft_strrchr(str, 'c'));
	printf("off: %s\n", strrchr(str, 'c'));
	return (0);
}
*/
