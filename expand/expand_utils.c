/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:43:57 by gchalmel          #+#    #+#             */
/*   Updated: 2026/02/20 16:51:50 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
#include "../libft/libft.h"

int	ft_strlen_sep(char *s, char fin)
{
	int	i;

	i = 0;
	while (s[i] != fin)
		i++;
	return (i);
}

char	*ft_getenv(char **envp, char *var)
{
	int	i;
	int	j;

	i = 0;
	printf("%s\n", var);
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], var, ft_strlen(var)) == 0)
			break ;
		i++;
	}
	j = 0;
	while (envp[i] != NULL && envp[i][j])
	{
		if (envp[i][j] == '=')
			return (&envp[i][j + 1]);
		j++;
	}
	return (NULL);
}
