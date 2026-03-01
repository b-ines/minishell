/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sorted_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:06:06 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/02/24 17:12:04 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../libft/libft.h"

char	**env_cpy(char	**src)
{
	char	**dest;
	int		i;

	i = 0;
	dest = 0;
	dest = ft_malloc(sizeof(char *) * (tab_size(src) + 1));
	if (!dest)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	**env_cpy_sorted(char **envp)
{
	int		i;
	int		j;
	char	**env;
	char	*key;
	char	*next_key;

	i = 0;
	env = 0;
	env = env_cpy(envp);
	while (env[i] && i < tab_size(envp) - 1)
	{
		j = 0;
		while (env[j] && j < tab_size(envp) - i - 1)
		{
			key = get_key(env[j]);
			next_key = get_key(env[j + 1]);
			if (ft_strcmp(key, next_key) > 0)
				ft_swap_str(&env[j], &env[j + 1]);
			ft_free_malloc(key);
			ft_free_malloc(next_key);
			j++;
		}
		i++;
	}
	return (env);
}

void	print_sorted_envp(char	**envp_export, int fd)
{
	char	**env_cpy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	env_cpy = env_cpy_sorted(envp_export);
	while (env_cpy[i])
	{
		j = 0;
		ft_putstr_fd("export ", fd);
		while (env_cpy[i][j] && env_cpy[i][j] != '=')
			ft_putchar_fd(env_cpy[i][j++], fd);
		if (env_cpy[i][j] && env_cpy[i][j] == '=')
		{
			ft_putchar_fd(env_cpy[i][j++], fd);
			ft_putchar_fd('\"', fd);
			while (env_cpy[i][j])
				ft_putchar_fd(env_cpy[i][j++], fd);
			ft_putchar_fd('\"', fd);
		}
		ft_putchar_fd('\n', fd);
		i++;
	}
	ft_free_malloc(env_cpy);
}
