/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:47:53 by inbeaumo          #+#    #+#             */
/*   Updated: 2025/11/19 18:32:46 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t			i;
	unsigned char	*s1_c;
	unsigned char	*s2_c;

	i = 0;
	s1_c = (unsigned char *)s1;
	s2_c = (unsigned char *)s2;
	if (size == 0)
		return (0);
	while (s1_c[i] && s2_c[i] && s1_c[i] == s2_c[i] && i < (size - 1))
		i++;
	return (s1_c[i] - s2_c[i]);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char *s1 = "ABC";
	char *s2 = "AB";
	unsigned int size = 3;
	printf("ft: %d\n", ft_strncmp("zyxbcdefgh", "abcdwxyz", 0));
	printf("off: %d\n", strncmp("zyxbcdefgh", "abcdwxyz", 0));
	return (0);
}
*/
