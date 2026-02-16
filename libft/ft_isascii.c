/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:21:11 by inbeaumo          #+#    #+#             */
/*   Updated: 2025/11/19 18:22:28 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
int	main(void)
{
	#include <ctype.h>
	#include <stdio.h>
	int	c = 0;
	while (c <= 130)
	{
		printf("ft_isascii(%c) = %d \n", c, ft_isascii(c));
		printf("isascii(%c) = %d \n", c, isascii(c));
		printf("\n");
		c++;
	}
	return (0);
}
*/
