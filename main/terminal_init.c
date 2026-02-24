/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:25:34 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/02/24 17:09:24 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	**empty_env(void)
{
	char	**env;
	char	buffer[10000];

	env = malloc(sizeof(char *) * (4));
	env[0] = ft_strdup("_=usr/bin/env");
	env[1] = ft_strjoin("PWD=", getcwd(buffer, 10000));
	env[2] = ft_strjoin("OLDPWD=", getcwd(buffer, 10000));
	env[3] = 0;
	return (env);
}

char	**envdup(char **envp)
{
	char	**dup;
	int		i;

	i = 0;
	if (!envp)
		return (empty_env());
	while (envp[i])
		i++;
	dup = malloc(sizeof(char *) * (i + 1));
	if (!dup)
		return (0);
	i = 0;
	while (envp[i])
	{
		if (!ft_strchr(envp[i], '='))
			continue;
		dup[i] = ft_strdup(envp[i]);
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	**envdup_export(char **envp)
{
	char	**dup;
	int		i;

	i = 0;
	if (!envp)
		return (empty_env());
	while (envp[i])
		i++;
	dup = malloc(sizeof(char *) * (i + 1));
	if (!dup)
		return (0);
	i = 0;
	while (envp[i])
	{
		dup[i] = ft_strdup(envp[i]);
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
	terminal->envp_export = envdup_export(envp);
	return (terminal);
}
