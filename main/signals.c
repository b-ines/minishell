/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:00:19 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/04 13:57:56 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static t_terminal *signal_terminal;
//interdit dutiliser une structure en variable globale

void	handler(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;

	if (sig == SIGINT)
	{
		if (get_gmod() == PROMPT)
		{
			write(1, "\n", 1);
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
			signal_terminal->exit_status = 130;
			return ;
		}
		else if (get_gmod() == HEREDOC)
		{
			write(1 , "\n", 1);
			set_gmod(HEREDOC_ABORTED);
		}
	}

}

void	signal_init(t_terminal *terminal)
{
	struct sigaction sa;

	signal_terminal = terminal;
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	init_gmod();
}
