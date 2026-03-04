/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:00:36 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/02/26 17:38:54 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	printf_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab || !*tab)
		return ;
	printf("[ ");
	while (tab[i])
	{
		printf("%s, ", tab[i++]);
	}
	printf("0 ] ");
}

void	print_files(t_cmd *current)
{
	if (!current->infile)
		printf("infile=0 ");
	else
		printf("infile=%s ", current->infile);
	if (!current->outfile)
		printf("outfile=0 ");
	else
		printf("outfile=%s ", current->outfile);
}

void	printf_cmd(t_cmd *cmd)
{
	t_cmd	*current;
	int		i;

	i = 1;
	current = cmd;
	if (!cmd)
		return ;
	while (current)
	{
		printf("%d --> argv=", i);
		printf_tab(current->argv);
		print_files(current);
		printf("append=%d\n", current->append);
		current = current->next;
		i++;
	}
}
