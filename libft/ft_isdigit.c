/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:08:58 by inbeaumo          #+#    #+#             */
/*   Updated: 2025/11/19 18:21:37 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}
/*
int	main(void)
{
	#include <stdio.h>
	#include <ctype.h>
	int	c = '1';
	while (c <= '9')
	{
		printf("ft %c : %d\n", c, ft_isdigit(c));
		printf("off %c : %d\n", c, isdigit(c));
		printf("\n");
		c++;
	}
	return (0);
}
*/
