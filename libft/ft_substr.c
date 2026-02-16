/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:27:15 by inbeaumo          #+#    #+#             */
/*   Updated: 2025/11/23 14:11:31 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substring;

	i = 0;
	if (!s || len == 0 || s[0] == '\0' || start > ft_strlen(s))
	{	
		substring = malloc(1);
		if (!substring)
			return (0);
		substring[0] = 0;
		return (substring);
	}
	if (ft_strlen(s + start) < len)
		substring = malloc((ft_strlen(s + start) + 1) * sizeof(char));
	else
		substring = malloc((len + 1) * sizeof(char));
	if (!substring)
		return (0);
	while (i < len && s[start + i])
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
// int	main(void)
// {
// 	#include <stdio.h>
// 	char	str[] = "lorem ipsum dolor sit amet";
// 	printf("%s\n", ft_substr("hola", 2, 1));
// }
