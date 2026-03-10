/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:50:36 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/10 17:18:38 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;
	int		size;

	if (src == NULL)
		return (NULL);
	size = ft_strlen(src);
	i = 0;
	dest = (char *)ft_malloc(sizeof(char) * (size + 1));
	//printf("malloc_list = %p\n", get_malloc_list());
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	src[] = "lorem ipsum dolor sit amet";
	char	*ft_str_dup;
	char	*str_dup;
	ft_str_dup = ft_strdup(src);
	str_dup = strdup(src);
	printf("ft_strdup : %s\n", ft_strdup(src));
	printf("strdup : %s\n", strdup(src));
	return (0);
}
*/