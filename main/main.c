/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:08:48 by gchalmel          #+#    #+#             */
/*   Updated: 2026/02/28 16:09:11 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
	printf_list(&token);
	terminal->cmd_blocks = 0;
	expand(&token, *terminal);
	terminal->cmd_blocks = parser(terminal, token);
	if (!terminal->cmd_blocks)
		return (0);
	printf_cmd(terminal->cmd_blocks);
	/*en theoprie a partir de la on free token et on utilise que cmd_blocks*/
	//builtins(&token, terminal);
	exec(terminal);
	return (1);
}

void	minishell_loop(t_terminal *terminal)
{
	char	*line;

	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
			break ;
		add_history(line);
		rl_on_new_line();
		program(line, terminal);
	}
}

int	main(int argc, char **argv, char **envp)
{
	struct sigaction	sa;
	t_terminal			*terminal;

	(void)argv;
	if (argc != 1)
		return (0);
	terminal = 0;
	signal_init(&sa);
	signal(SIGQUIT, SIG_IGN);
	terminal = terminal_init(envp);
	minishell_loop(terminal);
	return (0);
}
