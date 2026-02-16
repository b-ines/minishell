/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:14:05 by inbeaumo          #+#    #+#             */
/*   Updated: 2025/11/10 14:19:47 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) > 0 || ft_isdigit(c) > 0)
		return (8);
	return (0);
}
/*
int	main(void)
{
        #include <stdio.h>
        #include <ctype.h>
        int    c = '1';
        while (c <= '9')        
        {       
                printf("moi %c : %d\n", c, ft_isalnum(c));
                printf("off %c : %d\n", c, isalnum(c));
                printf("\n");
                c++;
        }
        return (0);
}
*/
