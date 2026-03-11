/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:20:44 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/05 19:13:37 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

int	heredoc_eof(char *line, char *heredoc_delim)
{
	if (!line && (get_gmod() != HEREDOC_ABORTED))
	{
		ft_putstr_fd("minishell: warning: here-document delimited ", 2);
		ft_putstr_fd("by end-of-file (wanted `", 2);
		write(2, heredoc_delim, ft_strlen(heredoc_delim) - 1);
		ft_putendl_fd("')", 2);
		return (1);
	}
	if (ft_strcmp(line, heredoc_delim) == 0)
		return (1);
	return (0);
}

int	here_doc(t_terminal *term, t_heredoc *current_hd)
{
	char	*line;
	int		pipefds[2];
	char	*expanded_line;

	if (pipe(pipefds) == -1)
		return (ft_putendl_fd("minishell: pipe error", 2), -1);
	while (1)
	{
		write(1, "> ", 2);
		line = get_next_line(0);
		if (heredoc_eof(line, current_hd->here_doc_delim) == 1)
			break ;
		if (!current_hd->heredoc_quoted)
		{
			expanded_line = expand_line(term, line);
			line = expanded_line;
		}
		ft_putstr_fd(line, pipefds[1]);
	}
	close(pipefds[1]);
	current_hd->heredoc_fd = pipefds[0];
	return (0);
}

int	parse_heredoc(t_terminal *term)
{
	t_cmd		*current_cmd;
	t_heredoc	*current_hd;

	current_cmd = term->cmd_blocks;
	while (current_cmd)
	{
		current_hd = current_cmd->heredoc_list;
		while (current_hd)
		{
			set_gmod(HEREDOC);
			here_doc(term, current_hd);
			if (current_cmd->heredoc_fd != -1)
				close(current_cmd->heredoc_fd);
			current_cmd->heredoc_fd = current_hd->heredoc_fd;
			current_hd = current_hd->next;
		}
		current_cmd = current_cmd->next;
	}
	return (1);
}
