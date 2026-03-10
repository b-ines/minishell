/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitz <kitz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 23:54:24 by kitz              #+#    #+#             */
/*   Updated: 2026/03/10 23:55:09 by kitz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	valid_redir(t_files *file_node)
{
	int		fd;

	fd = -1;
	if (file_node->type == 0)
		fd = open(file_node->file, O_RDONLY);
	else if (file_node->type == 1 && file_node->append == 0)
		fd = open(file_node->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (file_node->type == 1 && file_node->append == 1)
		fd = open(file_node->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(file_node->file, 2);
		ft_putstr_fd(": ", 2);
		perror("");
		return (0);
	}
	if (fd != -1)
		close(fd);
	return (1);
}

int	check_ambiguous_redirect(t_files *file_node)
{
	if (file_node->file && !ft_strncmp(file_node->file, "|", 1))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(file_node->file + 1, 2);
		ft_putendl_fd(": ambiguous redirect", 2);
		return (0);
	}
	return (1);
}

int	parse_files(t_terminal *term)
{
	t_files	*current;

	current = term->cmd_blocks->files_list;
	while (current)
	{
		if (!check_ambiguous_redirect(current))
			return (0);
		if (!valid_redir(current))
			return (0);
		current = current->next;
	}
	return (1);
}
