/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:20:44 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/05 11:54:41 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

// //aucune idee de comment gerer le ctrl c :FKSJFE:LKJFELSKJ
// extern volatile sig_atomic_t gsignal = 0;

// void	heredoc_handler(int sig, siginfo_t *info, void *context)
// {
// 	(void)info;
// 	(void)context;

// 	if (sig == SIGINT)
// 	{
// 		write(1, "\n", 1);
// 		return ;
// 	}
// }

// int	here_doc_signal_init(void)
// {
// 	struct sigaction sa;

// 	if (gsignal == SIGINT)
// 	{}
// 	sa.sa_sigaction = heredoc_handler;
// 	sa.sa_flags = SA_SIGINFO;
// 	sigemptyset(&sa.sa_mask);
// 	sigaction(SIGINT, &sa, NULL);
// }

int	heredoc_eof(char *line, char *heredoc_delim)
{
	if (!line)
	{
		ft_putstr_fd("minishell: warning: here-document delimited ", 2);
		ft_putstr_fd("by end-of-file (wanted `", 2);
		ft_putstr_fd(heredoc_delim, 2);
		ft_putendl_fd("')", 2);
		free(line);
		return (1) ; // ca fait quand meme 0 comme code et ca fait la commande
	}
	if (ft_strcmp(line, heredoc_delim) == 0)
	{
		free(line);
		return (1) ;
	}
	return (0);
}

int	here_doc(t_terminal *term, t_heredoc *current_hd)
{
	char	*line;
	int		pipefds[2];

	if (pipe(pipefds) == -1)
	{
		ft_putendl_fd("minishell: pipe error", 2);
		return (-1);
	}
	while (1)
	{
		write(1, "> ", 2);
		line = get_next_line(0);
		if (heredoc_eof(line, current_hd->here_doc_delim) == 1)
			break ;
		if (!current_hd->heredoc_quoted)
		{
			char *expanded_line = expand_line(term, line);
			free(line);
			line = expanded_line;
		}
		ft_putstr_fd(line, pipefds[1]);
		free(line); 
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
			//here_doc_signal_init();
			here_doc(term, current_hd);
			if (current_cmd->heredoc_fd != -1)
				close(current_cmd->heredoc_fd);
			current_cmd->heredoc_fd = current_hd->heredoc_fd;
			current_hd = current_hd->next;
			//signal_init(term);
		}
		current_cmd = current_cmd->next;
	}
	return (1);
}
