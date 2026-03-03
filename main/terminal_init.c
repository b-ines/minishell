/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:25:34 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/03 17:24:21 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "../libft/libft.h"

char	**empty_env(void)
{
	char	**env;
	char	buffer[10000];

	env = ft_malloc(sizeof(char *) * (4));
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
	if (!envp || !envp[0])
		return (empty_env());
	while (envp[i])
		i++;
	dup = ft_malloc(sizeof(char *) * (i + 1));
	if (!dup)
		return (0);
	i = 0;
	while (envp[i])
	{
		if (!ft_strchr(envp[i], '='))
		{
			i++;
			continue;
		}
		dup[i] = ft_strdup(envp[i]);
		if (!dup[i])
			return (NULL);
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
	dup = ft_malloc(sizeof(char *) * (i + 1));
	if (!dup)
		return (0);
	i = 0;
	while (envp[i])
	{
		dup[i] = ft_strdup(envp[i]);
		if (dup[i] == NULL)
			return (NULL);
		i++;
	}
	dup[i] = 0;
	return (dup);
}

t_terminal	*terminal_init(char **envp)
{
	t_terminal *terminal;

	terminal = 0;
	terminal = ft_malloc(sizeof(t_terminal));
	if (!terminal)
	{
		ft_free_all_malloc();
		exit(EXIT_FAILURE);
	}
	terminal->exit_status = 0;
	terminal->envp = envdup(envp);
	terminal->envp_export = envdup_export(envp);
	return (terminal);
}
