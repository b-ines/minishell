/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:37:03 by inbeaumo          #+#    #+#             */
/*   Updated: 2025/12/05 15:38:52 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc_gnl(size_t num, size_t size)
{
	void	*ptr;

	if (num != 0 && (size * num) / num != size)
		return (0);
	ptr = malloc(num * size);
	if (!ptr)
		return ((void *)0);
	ft_bzero(ptr, size * num);
	return (ptr);
}

char	*ft_newline(char *stash, int n_index)
{
	int		i;
	char	*new_line;

	i = 0;
	if (n_index == 0)
	{
		new_line = ft_calloc_gnl(2, sizeof(char));
		new_line[0] = '\n';
		return (new_line);
	}
	if (n_index == -1)
	{	
		new_line = ft_calloc_gnl(ft_strlen(stash) + 1, sizeof(char));
		n_index = ft_strlen(stash) - 1;
	}
	else
		new_line = ft_calloc_gnl(n_index + 2, sizeof(char));
	if (!new_line)
		return (0);
	while (stash && i <= n_index && stash[i])
	{	
		new_line[i] = stash[i];
		i++;
	}
	return (new_line);
}

void	*ft_trimmed_stash(char *stash, int n_index)
{
	char	*new_stash;
	int		i;
	int		stash_len;

	i = 0;
	if (n_index == -1)
		return (ft_free(&stash, 0));
	stash_len = ft_strlen(stash);
	if (stash_len - n_index == 1)
	{
		new_stash = ft_calloc_gnl(1, sizeof(char));
		return (ft_free(&stash, new_stash));
	}
	if (n_index == 0)
		new_stash = ft_calloc_gnl(stash_len, sizeof(char));
	else
		new_stash = ft_calloc_gnl(stash_len - n_index + 2, sizeof(char));
	if (!new_stash)
		return (0);
	while (stash && i + 1 + n_index < stash_len && stash[n_index + 1 + i])
	{	
		new_stash[i] = stash[n_index + 1 + i];
		i++;
	}
	return (ft_free(&stash, new_stash));
}

char	*ft_fill_stash(int fd, char *stash)
{
	char	*buffer;
	ssize_t	count;
	int		n_index;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_free(&stash, 0));
	n_index = ft_n_index(stash);
	while (n_index == -1)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count < 0)
		{
			free(buffer);
			return (ft_free(&stash, 0));
		}
		if (count == 0)
			break ;
		buffer[count] = 0;
		stash = ft_strjoin_gnl(stash, buffer);
		n_index = ft_n_index(stash);
	}
	if (buffer)
		free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*new_line;
	int			n_index;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = ft_fill_stash(fd, stash);
	if (!stash)
		return (0);
	n_index = ft_n_index(stash);
	if (!stash[0])
		return (ft_free(&stash, 0));
	new_line = ft_newline(stash, n_index);
	stash = ft_trimmed_stash(stash, n_index);
	return (new_line);
}

// #include <stdio.h>
// int main(void)
// {
// 	char    *new_line;

// 	int fd = open("bible.txt", O_RDONLY);
// 	while ((new_line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", new_line);
// 		free(new_line);
// 	}
// 	return (0);
// }
