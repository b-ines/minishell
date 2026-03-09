/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:08:48 by gchalmel          #+#    #+#             */
/*   Updated: 2026/03/09 17:09:30 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

//HO$?LA on a plus acces au la donc ca fait pas HO0LA ca stoppe la chaine
//le heredoc leak

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
	printf_list(&token);
	expand(&token, *terminal);
	terminal->cmd_blocks = parser(terminal, token);
	if (!terminal->cmd_blocks)
		return (0);
	printf_cmd(terminal->cmd_blocks);
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
	signal_init(terminal);
	// signal(SIGQUIT, SIG_IGN);
	minishell_loop(terminal);
	return (0);
}
