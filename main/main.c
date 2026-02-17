/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:08:48 by gchalmel          #+#    #+#             */
/*   Updated: 2026/02/16 18:16:58 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer/lexer.h"
#include "../parser/parser.h"
#include <signal.h>

/*

Tkt on dirait que y a des erreurs mais cest vscode qui trouve pas les modules mais ca compile correctement normalement

*/

void	handler(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;

	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		return ;
	}
}

void	signal_init(struct sigaction *sa)
{
	sa->sa_sigaction = handler;
	sa->sa_flags = SA_SIGINFO;
	sigemptyset(&sa->sa_mask);
	sigaction(SIGINT, sa, NULL);
}

void	program(char *line)
{
	t_token	*token;

	token = 0;
	token = lexer(line);
	if (!token)
		return ;
	parser(&token);
	printf_list(&token);
}

int	main(int argc, char **argv)
{
	char				*line;
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
		return (0);

	signal_init(&sa);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
			break ;
		rl_on_new_line();
		add_history(line);
		if (!ft_strncmp(line, "", 1))
			continue ;
		program(line);
		if (ft_strncmp(line, "exit", ft_strlen(line)) == 0)
			break ;
		free(line);
	}
	return (0);
}
