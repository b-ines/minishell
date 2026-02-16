/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:14:54 by inbeaumo          #+#    #+#             */
/*   Updated: 2025/11/17 14:18:13 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int		size;
	long	nb;

	size = 1;
	nb = (long)n;
	if (nb < 0)
	{	
		size++;
		nb = -nb;
	}
	while (nb > 9)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	long	nb;

	nb = (long)n;
	size = ft_size(nb);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	if (nb < 0)
	{
		nb = -nb;
		str[0] = '-';
	}
	str[size] = '\0';
	while (size)
	{
		if (str[0] == '-' && size == 1)
			break ;
		size--;
		str[size] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
/*
int	main(void)
{
	#include <stdio.h>
	printf("%s", ft_itoa(-2147483648));
	return (0);
}
*/
