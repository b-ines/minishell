/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:03:55 by inbeaumo          #+#    #+#             */
/*   Updated: 2025/11/11 16:06:50 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>
int	main(void)
{
	printf("ft_tolower(%c) = %c\n", 'C', ft_tolower('C'));
	printf("tolower(%c) = %c\n", 'C', tolower('C'));
	return (0);
}
*/
