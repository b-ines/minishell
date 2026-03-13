/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:08:48 by gchalmel          #+#    #+#             */
/*   Updated: 2026/03/13 16:09:24 by inbeaumo         ###   ########.fr       */
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
		exec(terminal);
	return (1);
}

void	minishell_loop(t_terminal *terminal)
{
	char	*line;
	int		exit_status_cpy;

	while (1)
	{
		set_gmod(PROMPT);
		line = 0;
		line = readline("minishell$ ");
		if (!line)
		{
			exit_status_cpy = terminal->exit_status;
			ft_free_all_malloc();
			ft_putstr_fd("exit\n", 1);
			rl_clear_history();
			exit(exit_status_cpy);
		}
		add_history(line);
		rl_on_new_line();
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
	minishell_loop(terminal);
	return (0);
}
