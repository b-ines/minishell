/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:31:59 by inbeaumo          #+#    #+#             */
/*   Updated: 2025/11/19 18:21:32 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	return (0);
}
/*
int	main(void)
{
	#include <stdio.h>
	#include <ctype.h>
	int	c = 0;
	while (c <= 179)
	{
		printf("ft(%c) = %d\n", c, ft_isprint(c));
		printf("off(%c) = %d\n", c, isprint(c));
		printf("\n");
		c++;
	}
	return (0);
}
*/
