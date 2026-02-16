/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:00:03 by inbeaumo          #+#    #+#             */
/*   Updated: 2025/11/23 14:15:21 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (1);
}

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i + 1] == c && s[i] != c)
			|| (s[i + 1] == '\0' && s[i] != c))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_strndup_split(char const *str, size_t len)
{
	char	*copy;
	size_t	i;

	i = 0;
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (0);
	while (i < len)
	{	
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static int	fill_split(char **split, char const *s, char c, int words)
{
	int	i_split;
	int	i;
	int	len;

	i_split = 0;
	i = 0;
	while (i_split < words)
	{
		len = 0;
		while (s[i] == c)
			i++;
		while (s[i + len] != c && s[i + len])
			len++;
		split[i_split] = ft_strndup_split(&s[i], len);
		if (!split[i_split])
			return (0);
		i_split++;
		i += len;
	}
	split[i_split] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		count_words;

	if (!s)
		return (0);
	count_words = ft_count_words(s, c);
	split = malloc(sizeof(char *) * (count_words + 1));
	if (!split)
		return (0);
	if (fill_split(split, s, c, count_words) == 0)
	{	
		ft_free_split(split);
		return (0);
	}
	return (split);
}
/*
// int	main(void)
// {
// 	#include <stdio.h>
// 	char	*str = "Tripouille";
// 	char	sep = ' ';
// 	char	**split = ft_split("hello!", ' ');
// 	// printf("count words %d\n", ft_count_words(str, sep));
// 	for(int i = 0; i < ft_count_words(str, sep) + 1; i++)
// 	{
// 		printf("split[%d] = %s\n", i, split[i]);
// 	}
// 	return (0);
// }
*/
