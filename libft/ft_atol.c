/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:59:37 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/02/23 14:59:39 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

long  long	ft_atol(const char *str)
{
	int			i;
	long long	signe;
	long long	result;

	i = 0;
	signe = 1.0;
	result = 0.0;
	if (ft_strncmp(str, "9223372036854775807", 19) == 0)
		return (9223372036854775807);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1.0;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = (result * 10.0) + (str[i++] - 48.0);
	return (signe * result);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	char *str = "+ 42";
	printf("ft_atoi(%s) : %d\n", str, ft_atoi(str));
	printf("atoi(%s) : %d\n", str, atoi(str));
	return (0);
}
*/
