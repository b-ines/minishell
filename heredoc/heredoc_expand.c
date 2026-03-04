/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:51:18 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/04 12:33:05 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

//

char	*expand_line(t_terminal *term, char *line)
{
	int	i;
	int	j;
	char	key[5000];

	i = 0;
	while (line[i])
	{
		if (line[i] == '$')
		{
			i++;
			j = 0;
			if (line[i + j] && (ft_isalpha(line[i + j]) || line[i + j] == '_'))
				j++;
			else
				break ;
			while (ft_isalnum(line[i + j]) || line[i + j] == '_')
				j++;
			ft_strlcpy(key, &line[i], j);
			char *temp = ft_strjoin("$", key);
			if (!get_value_by_key(term, key))
				printf("trimmed %s\n", ft_strtrim(line, temp - 1));
			i += j;
		}
		i++;
	}
	return (line);
}