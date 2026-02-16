/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:15:08 by inbeaumo          #+#    #+#             */
/*   Updated: 2025/11/23 14:39:02 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		((char *)str)[i++] = '\0';
}
/*
int	main(void)
{
	#include <stdio.h>
	#include <string.h>
	char ft_str[] = "coucou ca va";
	char str[] = "coucou ca va";
	printf("pre ftstr : %s\n", ft_str);
	printf("pre str : %s\n", str);
	ft_bzero(ft_str + 3, 2);
	bzero(str + 3, 2);
	printf("post ft_bzero : %s\n", ft_str);
	printf("post bzero : %s\n", str);
	return (0);
}
*/
