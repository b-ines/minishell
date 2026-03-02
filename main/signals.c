/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:00:19 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/02/24 17:09:32 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	(void)sig;

	// if (sig == SIGINT)
	// {
		flag = 1;
	// 	return ;
	// }
	// else if (sig == SIGTSTP) // pas sur que besoin
	// {
	// 	write(1, "\n", 1);
	// 	rl_on_new_line();
	// 	rl_replace_line("", 0);
	// 	rl_redisplay();
	// 	return ;
	// }
}

void	signal_init(t_terminal *terminal)
{
	struct sigaction sa;
	(void)terminal;
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	flag = 0;
	// while (1)
	// {
	// 	if (flag)
	// 	{
	// 		write(1, "\n", 1);
	// 		rl_on_new_line();
	// 		rl_replace_line("", 0);
	// 		rl_redisplay();
	// 		terminal->exit_status = 130;
	// 		flag = 0;
	// 	}
	// }
}