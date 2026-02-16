/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:07:16 by inbeaumo          #+#    #+#             */
/*   Updated: 2025/11/19 18:20:00 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c % 256)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == c % 256)
		return ((char *)str + i);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char		str[] = "bonjour";
	printf("ft: %s", ft_strchr(str, '\0'));
	printf("off: %s", strchr(str, '\0'));
	return (0);
}*/
