/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:51:18 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/05 19:14:28 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

static char	*exit_status(t_terminal *term, int *i, char *ret)
{
	char	*new_line;

	new_line = ft_itoa(term->exit_status);
	ret = ft_strjoin(ret, new_line);
	(*i)++;
	return (ret);
}

static char	*variable(t_terminal *term, char *line, int *i, char *ret)
{
	char	*new_line;
	char	key[5000];
	int		j;

	j = 0;
	while (line[(*i) + j] && (ft_isalnum(line[(*i) + j])
			|| line[(*i) + j] == '_'))
		j++;
	ft_strlcpy(key, &line[(*i)], j + 1);
	new_line = get_value_by_key(term, key);
	if (!new_line)
		new_line = "";
	ret = ft_strjoin(ret, new_line);
	(*i) += j;
	return (ret);
}

static char	*make_expand(t_terminal *term, char *line, int *i, char *ret)
{
	char	*ret_tmp;

	if (line[(*i)] == '?')
		ret_tmp = exit_status(term, i, ret);
	else if (ft_isalpha(line[(*i)]) || line[(*i)] == '_')
		ret_tmp = variable(term, line, i, ret);
	else
		ret_tmp = ft_strjoin(ret, "$");
	return (ret_tmp);
}

char	*expand_line(t_terminal *term, char *line)
{
	int		i;
	char	*ret;
	char	c[2];

	i = 0;
	c[1] = '\0';
	ret = ft_strdup("");
	while (line[i])
	{
		if (line[i] == '$')
		{
			i++;
			ret = make_expand(term, line, &i, ret);
		}
		else
		{
			c[0] = line[i];
			ret = ft_strjoin(ret, c);
			i++;
		}
	}
	return (ret);
}
