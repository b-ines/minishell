/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:00:36 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/06 18:34:59 by inbeaumo         ###   ########.fr       */
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

void	printf_heredoc(t_heredoc **hd_head)
{
	t_heredoc	*current;

	current = *hd_head;
	if (!hd_head)
		return ;
	printf("[");
	while (current)
	{
		printf("%s, ", current->here_doc_delim);
		current = current->next;
	}
	printf("] ");
}

void	printf_infile(t_infile **inf_head)
{
	t_infile	*current;

	current = *inf_head;
	if (!inf_head)
		return ;
	printf("[");
	while (current)
	{
		printf("%s, ", current->infile);
		current = current->next;
	}
	printf("] ");
}

void	printf_outfile(t_outfile **outf_head)
{
	t_outfile	*current;

	current = *outf_head;
	if (!outf_head)
		return ;
	printf("[");
	while (current)
	{
		printf("%s, ", current->outfile);
		current = current->next;
	}
	printf("] ");
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
		printf("heredoc=");
		printf_heredoc(&current->heredoc_list);
		printf("inf_list=");
		printf_infile(&current->infile_list);
		printf("outf_list=");
		printf_outfile(&current->outfile_list);
		print_files(current);
		printf("heredocfd=%d ", current->heredoc_fd);
		printf("append=%d\n", current->append);
		current = current->next;
		i++;
	}
}
