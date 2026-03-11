/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitz <kitz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:23:54 by gchalmel          #+#    #+#             */
/*   Updated: 2026/03/11 00:06:05 by kitz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	pre_exec_error_msg(t_terminal *term, char *str, int exit_code)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(term->cmd_blocks->argv[0], 2);
	ft_putendl_fd(str, 2);
	exit(exit_code);
}

void	post_execve_error_msg(t_terminal *term, int exec_errno)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(term->cmd_blocks->argv[0], 2);
	ft_putstr_fd(": ", 2);
	perror("");
	if (exec_errno == EACCES)
		exit (126);
	if (exec_errno == ENOENT)
		exit (127);
	exit(EXIT_FAILURE);
}

void	ft_execve(t_terminal *term, int *i, int cmdc, int *fd)
{
	char	*path;
	int		exec_errno;

	if (!parse_files(term))
	{
		clear_fd(fd, cmdc);
		exit(1);
	}
	if (!term->cmd_blocks->argv || !term->cmd_blocks->argv[0])
		exit(0);
	exec_piped_builtin(term, cmdc, fd, i);
	path = search_cmd(term, term->cmd_blocks->argv[0]);
	if (!path)
		pre_exec_error_msg(term, ": command not found", 127);
	if (get_arg_type(term->cmd_blocks->argv[0]) == 2)
		pre_exec_error_msg(term, ": Is a directory", 126);
	if (!redir_management(term, i, cmdc, fd))
	{
		clear_fd(fd, cmdc);
		exit(1);
	}
	clear_fd(fd, cmdc);
	execve(path, term->cmd_blocks->argv, term->envp);
	exec_errno = errno;
	post_execve_error_msg(term, exec_errno);
}

void	exec(t_terminal *term)
{
	int		pid1;
	int		status;
	int		*fd;
	int		cmdc;
	int		i;

	cmdc = lst_size(term);
	i = 0;
	if (ft_create_pipe(term->cmd_blocks, &fd, cmdc) == -1)
		return ;
	if (exec_single_builtin(term, cmdc, fd, &i))
		return ;
	while (term->cmd_blocks != NULL)
	{
		pid1 = fork();
		if (pid1 < 0)
			perror("minishell: fork: ");
		else if (pid1 == 0)
			ft_execve(term, &i, cmdc, fd);
		i++;
		term->cmd_blocks = term->cmd_blocks->next;
	}
	clear_fd(fd, cmdc);
	waitpid(pid1, &status, 0);
	while (wait(NULL) > 0)
		;
	term->exit_status = WEXITSTATUS(status);
}
