/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:50:47 by inbeaumo          #+#    #+#             */
/*   Updated: 2025/11/19 18:22:26 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
/*
int	main(void)
{
	#include <stdio.h>
	#include <ctype.h>
	char	c = 'a';
	while (c <= 'z')	
	{	
		printf("moi %c : %d\n", c, ft_isalpha(c));
		printf("off %c : %d\n", c, isalpha(c));
		printf("\n");
		c++;
	}
	return (0);
}
*/
