/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:43:57 by gchalmel          #+#    #+#             */
/*   Updated: 2026/03/13 17:39:10 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
#include <stdlib.h>
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
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], var, ft_strlen(var)) == 0
			&& envp[i][ft_strlen(var)] == '=')
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

char	*ft_clear_expand(char *str)
{
	char	*ret;
	int		i;
	int		size_str;

	i = 0;
	size_str = ft_strlen(str);
	ret = malloc(size_str * sizeof(char) + 1);
	while (str[i] != '\0')
	{
		if (!ft_isalpha(str[i]) || (str[i] != '_'))
			break ;
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

t_token	*m_u_exp(t_token *curr, char *final_token)
{
	ft_free_malloc(curr->token);
	curr->token = final_token;
	if (ft_strchr(final_token, '$'))
		return (curr);
	return (curr->next);
}
