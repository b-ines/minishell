/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:58:15 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/02/23 19:05:22 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

//export tout seul ca print trie par ascii ET AVEC GUILLEMETS
//export Hola ca fait une var hola sans =
//export "" ca fait not a valid indentifier
//juste 0 c invalid jsp ourquoi
//si yen a un invalid ca continue quand meme un message pour toutes les erreurs
//dans la value il peut y avoir des =
//je peux faire une copie qui malloc le nombre de str mais pas les str plus leger
//si strchr est null ya pas de egal donc jexport juste

int	valid_arg_export(char *str, int sep)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);		
	if (!(ft_isalpha(str[0]) || str[0] == '_'))
		return (0);
	while (str[i])
	{
		if (str[i] == sep)
			break ;
		if (!(ft_isalnum(str[i]) || str[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

char	**env_cpy_light(t_terminal *terminal)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char *) * (tab_size(terminal->envp[i]) + 1));
	if (!copy)
		return (0);
	while (terminal->envp[i])
	{
		copy[i] = terminal->envp[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}

void	sort_env_cpy(char **env_cpy)
{
	int		i;
	int		j;
	char	*key;
	int		env_size;

	i = 0;
	env_size = tab_size(env_cpy);
	while (i < env_size - 1)
	{
		j = 0;
		while (j < env_size - i - 1)
		{
			key = get_key_by_index(env_cpy[j])
			if (ft_strncmp())
		}
	}
}

//    int i, j;
//     bool swapped;
//     for (i = 0; i < n - 1; i++) {
//         swapped = false;
//         for (j = 0; j < n - i - 1; j++) {
//             if (arr[j] > arr[j + 1]) {
//                 swap(&arr[j], &arr[j + 1]);
//                 swapped = true;
//             }
//         }

//         // If no two elements were swapped by inner loop,
//         // then break
//         if (swapped == false)
//             break;


void	run_export(t_terminal *terminal, t_cmd *cmd)
{
	// int	size;
	// int	i = 0;
	(void)terminal;
	(void)cmd;
	char *buffer;

	buffer = 0;
	// size = ft_strchr(cmd->argv[1], '=');
	if (!valid_arg_export(cmd->argv[1], '=') && ft_isprint(cmd->argv[1]))
	{
		//machin not a valid argument
	}
		printf("VALIDE\n");
	else
		printf("INVALIDE\n");
	// while (cmd->argv[1][i] && i < size)
	// 	printf("%c", cmd->argv[1][i]);
	// printf("\n");


	// if (!cmd->argv[1])
	// {
	// 	print export trie par ascii
	// }
}