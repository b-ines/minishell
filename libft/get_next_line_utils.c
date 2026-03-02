/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:02:16 by inbeaumo          #+#    #+#             */
/*   Updated: 2025/12/03 16:57:48 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_n_index(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	*ft_free(char **to_free, void *to_return)
{
	free(*to_free);
	*to_free = 0;
	return (to_return);
}

char	*ft_strjoin_gnl(char *stash, char *buffer)
{
	int		i_stash;
	int		i_buffer;
	char	*new_stash;

	i_stash = 0;
	i_buffer = 0;
	if (stash)
		new_stash = malloc(ft_strlen(stash) + ft_strlen(buffer) + 1);
	else
		new_stash = malloc(ft_strlen(buffer) + 1 * sizeof(char));
	if (!new_stash)
		return (0);
	while (stash && stash[i_stash])
	{
		new_stash[i_stash] = stash[i_stash];
		i_stash++;
	}
	while (buffer && buffer[i_buffer])
	{	
		new_stash[i_stash + i_buffer] = buffer[i_buffer];
		i_buffer++;
	}
	new_stash[i_stash + i_buffer] = '\0';
	ft_free(&stash, 0);
	return (new_stash);
}
