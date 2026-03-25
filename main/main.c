/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:08:48 by gchalmel          #+#    #+#             */
/*   Updated: 2026/03/25 16:56:22 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "../parser/parser.h"
#include "../expand/expand.h"
#include "../heredoc/heredoc.h"
#include "../execve/exec.h"

//printf_cmd(terminal->cmd_blocks);

int	program(char *line, t_terminal *terminal)
{
	t_token	*token;
	int		cmdc;

	token = 0;
	if (empty_cmd(terminal, line))
		return (free(line), 0);
	token = lexer(terminal, line);
	free(line);
	if (!token)
		return (0);
	terminal->cmd_blocks = 0;
	expand(&token, *terminal);
	terminal->cmd_blocks = parser(terminal, token);
	if (!terminal->cmd_blocks)
		return (0);
	parse_heredoc(terminal);
	if (get_gmod() != HEREDOC_ABORTED && (get_gmod() != HEREDOC_QUIT))
	{	
		cmdc = lst_size(terminal);
		exec(terminal, cmdc);
	}
	return (1);
}

void	exitshell(t_terminal *terminal)
{
	int		exit_status_cpy;

	exit_status_cpy = terminal->exit_status;
	ft_free_all_malloc();
	if (isatty(0) == 1 && isatty(1) == 1)
	{	
		ft_putstr_fd("exit\n", 2);
		rl_clear_history();
	}
	exit(exit_status_cpy);
}

void	minishell_loop(t_terminal *terminal)
{
	char	*line;

	while (1)
	{
		set_gmod(PROMPT);
		line = 0;
		//if (isatty(0) == 1 && isatty(1) == 1)
			line = readline("minishell$ ");
		if (!line)
			exitshell(terminal);
		if (isatty(0) == 1 && isatty(1) == 1)
		{
			add_history(line);
			rl_on_new_line();
		}
		program(line, terminal);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_terminal			*terminal;

	(void)argv;
	if (argc != 1)
		return (0);
	terminal = 0;
	terminal = terminal_init(envp);
	signal_init();
	signal(SIGQUIT, SIG_IGN);
	minishell_loop(terminal);
	return (0);
}
