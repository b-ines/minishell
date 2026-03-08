/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:23:54 by gchalmel          #+#    #+#             */
/*   Updated: 2026/03/06 13:34:55 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

// il faudrait ouvrir et check les infiles ici separe par pipe plutot que tout dun coup
// no such file or directory on check de droite a gauche et on cree on stop quand ca existe plus


int	lst_size(t_terminal *term)
{
	int		i;
	t_cmd	*tmp;

	i = 0;
	tmp = term->cmd_blocks;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	clear_fd(int *fd, int cmdc)
{
	int	j;

	j = 0;
	while (j < (cmdc - 1) * 2)
		close(fd[j++]);
}
//faut changer la logique juste check que yai une list infile ou outfile et selon le flag open et close, malheurement on peut pas check lordre
int	redir_error_msg(char *str)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	perror("");
	return (0);
}

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
		return (redir_error_msg(file_node->file));
	close(fd);
	return (1);
}

int	parse_files(t_terminal *term)
{
	t_files	*current;
	int		fd;

	current = term->cmd_blocks->files_list;
	fd = -1;
	while (current)
	{
		if (!valid_redir(current))
			return (0);
		current = current->next;
	}
	close(fd);
	return (1);
}

void	ft_execve(t_terminal *term, int *i, int cmdc, int *fd)
{
	char	*path;
	int		output_fd;
	int		exec_errno;

	if (!parse_files(term))
	{
		//clear_fd(fd, cmdc);
		exit(1);
	}
	if (!term->cmd_blocks->argv || !term->cmd_blocks->argv[0])
		exit(0);
	if (is_builtins(term->cmd_blocks))
	{
		output_fd = get_output_fd(term->cmd_blocks, i, cmdc, fd);
		if (output_fd < 0)
			exit(1);
		run_builtins(term, term->cmd_blocks, output_fd);
		exit(term->exit_status);
	}
	path = search_cmd(term, term->cmd_blocks->argv[0]);
	if (!path)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(term->cmd_blocks->argv[0], 2);
		ft_putendl_fd(": command not found", 2);
		exit(127);
	}
	if (get_arg_type(term->cmd_blocks->argv[0]) == 2)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(term->cmd_blocks->argv[0], 2);
		ft_putendl_fd(": Is a directory", 2);
		exit(126);
	}
	
	if (!redir_management(term, i, cmdc, fd))
	{
		clear_fd(fd, cmdc);
		exit(1);
	}
	clear_fd(fd, cmdc);
	execve(path, term->cmd_blocks->argv, term->envp);
	exec_errno = errno;
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(term->cmd_blocks->argv[0], 2);
	ft_putstr_fd(": ", 2);
	perror("");
	if (exec_errno == EACCES) // permission denied
		exit (126);
	if (exec_errno == ENOENT) // no such file or directory/ does not exist
		exit (127);
	exit(EXIT_FAILURE);
}

void	ft_create_pipe(t_cmd *cmd, int **fd, int cmdc)
{
	int		i;
	t_cmd	*current;

	i = 0;
	current = cmd;
	*fd = ft_malloc(sizeof(int) * ((cmdc - 1) * 2));
	while (current->next)
	{
		pipe(*fd + i * 2);
		current = current->next;
		i++;
	}
}

void	exec(t_terminal *term)
{
	int		pid1;
	int		last_pid;
	int		status;
	int		*fd;
	int		cmdc;
	int		i;
	int		output_fd;

	cmdc = lst_size(term);
	ft_create_pipe(term->cmd_blocks, &fd, cmdc);
	i = 0;
	if (cmdc == 1 && is_builtins(term->cmd_blocks))
	{
		if (!parse_files(term))
		{
			term->exit_status = 1;
			return ;
		}
		output_fd = get_output_fd(term->cmd_blocks, &i, cmdc, fd);
		if (output_fd < 0)
			return ;
		run_builtins(term, term->cmd_blocks, output_fd);
		return ;
	}
	last_pid = -1;
	while (term->cmd_blocks != NULL)
	{
		pid1 = fork();
		if (pid1 == 0)
			ft_execve(term, &i, cmdc, fd);
		last_pid = pid1;
		i++;
		term->cmd_blocks = term->cmd_blocks->next;
	}
	clear_fd(fd, cmdc);
	waitpid(last_pid, &status, 0);
	while (wait(NULL) > 0)
		;
	term->exit_status = WEXITSTATUS(status);
}
