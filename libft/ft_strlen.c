/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:47:37 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/10 16:05:54 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}
/*
int	main(void)
{
	#include <string.h>
	#include <stdio.h>
	char str[] = "miam	mi\nam miam";
	printf("ft : %lu\n", ft_strlen(str));
	printf("off : %lu\n", strlen(str));
	return (0);
}
*/
