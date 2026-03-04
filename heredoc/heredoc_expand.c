/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:51:18 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/04 16:15:14 by inbeaumo         ###   ########.fr       */
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
			while (line[i + j] && (ft_isalnum(line[i + j]) || line[i + j] == '_'))
				j++;
			ft_strlcpy(key, &line[i], j);
			printf("found value %s\n", get_value_by_key(term, key));
			// if (!get_value_by_key(term, key))
			// 	printf("trimmed %s\n", ft_strtrim(line, key));
			i += j;
		}
		i++;
	}
	return (line);
}