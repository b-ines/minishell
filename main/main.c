/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:08:48 by gchalmel          #+#    #+#             */
/*   Updated: 2026/02/20 16:47:59 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	program(char *line, t_terminal *terminal)
{
	t_token	*token;

	token = 0;
	if (empty_cmd(terminal, line))
		return (0);
	token = lexer(terminal, line);
	if (!token)
		return (0);
	terminal->cmd_blocks = 0;
	expand(token, *terminal);
	terminal->cmd_blocks = parser(terminal, token);
	if (!terminal->cmd_blocks)
		return (0);
	printf_cmd(terminal->cmd_blocks);
	/*en theoprie a partir de la on free token et on utilise que cmd_blocks*/
	//builtins(&token, terminal);
	exec(token,  terminal);
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
		if (!program(line, terminal))
		{
			free(line);
			continue ;
		}
		if (ft_strncmp(line, "exit", 4) == 0)
		{
			free(line);
			break ;
		}
		free(line);
	}
}

char	**envdup(char **envp)
{
	char	**dup;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	dup = malloc(sizeof(char *) * (i + 1));
	if (!dup)
		return (0);
	i = 0;
	while (envp[i])
	{
		dup[i] = envp[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

t_terminal	*terminal_init(char **envp)
{
	t_terminal *terminal;

	terminal = 0;
	terminal = malloc(sizeof(t_terminal));
	terminal->exit_status = 0;
	terminal->envp = envdup(envp);
	return (terminal);
}

int	main(int argc, char **argv, char **envp)
{
	struct sigaction	sa;
	t_terminal *terminal;

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
