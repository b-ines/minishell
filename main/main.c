/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:08:48 by gchalmel          #+#    #+#             */
/*   Updated: 2026/02/27 14:49:18 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

//HO$?LA on a plus acces au la donc ca fait pas HO0LA ca stoppe la chaine

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
	expand(token, *terminal);
	printf_list(&token);
	terminal->cmd_blocks = parser(terminal, token);
	if (!terminal->cmd_blocks)
		return (0);
	printf_cmd(terminal->cmd_blocks);
	parse_heredoc(terminal);
	/*en theoprie a partir de la on free token et on utilise que cmd_blocks*/
	//builtins(terminal);
	//exec(terminal);
	return (1);
}

void	minishell_loop(t_terminal *terminal)
{
	char	*line;

	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
		{
			ft_putstr_fd("exit\n", 1);
			exit(terminal->exit_status);	
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
	signal(SIGQUIT, SIG_IGN);
	minishell_loop(terminal);
	return (0);
}
