/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:04:52 by inbeaumo          #+#    #+#             */
/*   Updated: 2025/11/19 18:25:53 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		((unsigned char *)pointer)[i++] = value;
	return (pointer);
}
/*
int	main(void)
{
	#include <string.h>
	#include <stdio.h>
	char ft_str[] = "Ceci est une phrase de test.";
	char str[] = "Ceci est une phrase de test.";
	printf("pre ft_memset: %s\n", ft_str);
	printf("pre memset: %s\n", str);
	ft_memset(ft_str + 2, '.', 4*sizeof(char));
	memset(str + 2, '.', 4*sizeof(char));
	printf("post ft_memset : %s\n", ft_str);
	printf("post memset : %s\n", str);
	return (0);
}
*/
