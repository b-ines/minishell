/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:08:48 by gchalmel          #+#    #+#             */
/*   Updated: 2026/02/17 15:20:37 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

<<<<<<< HEAD
#include "../lexer/lexer.h"
#include "../parser/parser.h"
#include "../expand/expand.h"
#include <signal.h>
=======
#include "main.h"
>>>>>>> 6b0944f (sauvegarde branche)

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
<<<<<<< HEAD
	parser(&token);
	printf_list(&token);
	expand(token);
	printf("Expand finish:\n");
	printf_list(&token);
=======
	if (parser(&token) != 0)
		printf_list(&token);
}

int	str_is_only_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int newline_cmd(char *line)
{
	if (!ft_strncmp(line, "", ft_strlen(line)))
		return (0);
	else if (!ft_strncmp(line, ":", ft_strlen(line)))
		return (0);
	else if (!ft_strncmp(line, "!", ft_strlen(line)))
		return (1);
	else if (str_is_only_space(line))
		return (0);
	return (-1);
}
void	terminal_loop(void)
{
	char	*line;

	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
			break ;
		rl_on_new_line();
		add_history(line);
		if (newline_cmd(line) != -1)
		{
			free(line);
			continue ;
		}
		if (ft_strncmp(line, "exit", ft_strlen(line)) == 0)
		{	
			free(line);
			break ;
		}
		program(line);
		free(line);
	}
>>>>>>> 6b0944f (sauvegarde branche)
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
		return (0);

	signal_init(&sa);
	signal(SIGQUIT, SIG_IGN);
	terminal_loop();
	return (0);
}
