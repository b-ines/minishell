/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:51:18 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/05 15:53:57 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

// a refaire proprement

char	*expand_line(t_terminal *term, char *line)
{
	int	i;
	int	j;
	char	key[5000];
	char	*new_line;
	char	*ret;
	char	*temp;

	i = 0;
	ret = ft_strdup("");
	while (line[i])
	{
		if (line[i] == '$')
		{
			i++;
			j = 0;
			while (line[i + j] && (ft_isalnum(line[i + j]) || line[i + j] == '_'))
				j++;
			ft_strlcpy(key, &line[i], j + 1);
			new_line = get_value_by_key(term, key); 
			if (!new_line)
				new_line = "";
			temp = ret;
			ret = ft_strjoin(ret, new_line);
			free(temp);
			i += j;
		}
		else
		{
			char c[2];
			c[0] = line[i];
			c[1] = '\0';
			temp = ret;
			ret = ft_strjoin(ret, c);
			free(temp);
			i++;
		}
	}
	return (ret);
}
