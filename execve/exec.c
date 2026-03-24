/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:23:54 by gchalmel          #+#    #+#             */
/*   Updated: 2026/03/24 16:34:39 by gabch            ###   ########.fr       */
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

void	post_execve_error_msg(t_terminal *term, char *path, int exec_errno)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(term->cmd_blocks->argv[0], 2);
	if (get_arg_type(path) == 2)
	{	
		ft_putendl_fd(": Is a directory", 2);
		exit (126);
	}
	if (exec_errno == EACCES)
	{	
		ft_putendl_fd(": Permission denied", 2);
		exit (126);
	}
	if (exec_errno == ENOENT)
	{	
		ft_putendl_fd(": No such file or directory", 2);
		exit (127);
	}
	exit(EXIT_FAILURE);
}

void	ft_execve(t_terminal *term, int *i, int cmdc, int *fd)
{
	char	*path;
	int		exec_errno;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	check_exec_args(term, cmdc, fd);
	exec_piped_builtin(term, cmdc, fd, i);
	path = term->cmd_blocks->argv[0];
	if (!ft_strchr(term->cmd_blocks->argv[0], '/'))
	{
		path = search_cmd(term, term->cmd_blocks->argv[0]);
		if (!path)
			pre_exec_error_msg(term, ": command not found", 127);
	}
	if (!redir_management(term, i, cmdc, fd))
	{
		clear_fd(fd, cmdc);
		exit(1);
	}
	clear_fd(fd, cmdc);
	execve(path, term->cmd_blocks->argv, term->envp);
	exec_errno = errno;
	post_execve_error_msg(term, path, exec_errno);
}

static int	fork_loop(t_terminal *term, int cmdc, int *fd, int *i)
{
	int	pid;

	pid = -1;
	while (term->cmd_blocks != NULL)
	{
		pid = fork();
		if (pid < 0)
			perror("minishell: fork: ");
		else if (pid == 0)
			ft_execve(term, i, cmdc, fd);
		if (term->cmd_blocks->heredoc_fd != -1)
		{
			close(term->cmd_blocks->heredoc_fd);
			term->cmd_blocks->heredoc_fd = -1;
		}
		(*i)++;
		term->cmd_blocks = term->cmd_blocks->next;
	}
	return (pid);
}

void	exec(t_terminal *term)
{
	int		pid;
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
	pid = fork_loop(term, cmdc, fd, &i);
	clear_fd(fd, cmdc);
	waitpid(pid, &status, 0);
	while (wait(NULL) > 0)
		;
	term->exit_status = WEXITSTATUS(status);
}
