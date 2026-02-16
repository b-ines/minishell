/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:38:52 by inbeaumo          #+#    #+#             */
/*   Updated: 2025/11/23 14:12:10 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	*join;

	i = 0;
	j = 0;
	if (!s1 || ! s2)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2);
	join = malloc((size + 1) * sizeof(char));
	if (!join)
		return (0);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{	
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}
/*
int	main(void)
{
	char *s1 = "lorem ipsum";
	char	*s2 = "dolor sin amet";
	#include <stdio.h>
	printf("%s\n", ft_strjoin(s1, s2));
	return 0;
}
*/
