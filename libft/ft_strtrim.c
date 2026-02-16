/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:54:52 by inbeaumo          #+#    #+#             */
/*   Updated: 2025/11/23 14:19:55 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_sep(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_start(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (s1[start] && ft_is_sep(s1[start], set))
		start++;
	return (start);
}

static size_t	ft_end(char const *s1, char const *set)
{
	size_t	end;

	end = ft_strlen(s1);
	while (s1[end - 1] && ft_is_sep(s1[end - 1], set))
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	i;
	size_t	end;
	char	*trimmed;

	i = 0;
	if (!s1 || !set)
		return (0);
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (start > end)
		return (trimmed = ft_strdup(""));
	trimmed = malloc(sizeof(char) * (end - start + 1));
	if (!trimmed)
		return (0);
	while (i < end - start)
	{
		trimmed[i] = s1[start + i];
		i++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}
/*
int	main(void)
{
	#include <stdio.h>
	char *str = ft_strtrim(" .  . . . ", " . ");
	printf("%s\n", str);
	return (0);
}
*/
