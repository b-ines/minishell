/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:20:44 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/02/27 15:29:17 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

char	*str_append()
{
}

void	here_doc(t_terminal *term, t_cmd *cmd)
{
	char	*line;
	int		fd;
	char 	*heredoc;

	fd = open(".heredoc", O_RDWR | O_CREAT);
	if (fd < 0)
	{
		ft_putendl_fd("minishell: fd error", 2);
		term->exit_status = 1;
	}
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			ft_putstr_fd("minishell: warning: here-document delimited ", 2);
			ft_putstr_fd("by end-of-file (wanted `", 2);
			ft_putstr_fd(cmd->here_doc_delim, 2);
			ft_putendl("')", 2);
			// ca fait quand meme 0 comme code et ca fait la commande
		}
		add_history(line);
		rl_on_new_line();
		heredoc = str_append();
		
	}
}