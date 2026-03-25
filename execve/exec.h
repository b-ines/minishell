/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:24:18 by gchalmel          #+#    #+#             */
/*   Updated: 2026/03/25 16:45:45 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "../main/main.h"
# include "../builtins/builtins.h"
# include <sys/wait.h>
# include <errno.h>

//check_redir.c
int		valid_redir(t_files *file_node);
int		parse_files(t_terminal *term);

//create_pipe.c
int		lst_size(t_terminal *term);
void	clear_fd(int *fd, int cmdc);
int		ft_create_pipe(t_cmd *cmd, int **fd, int cmdc);

//exec_builtins.c
int		get_builtin_fd(t_cmd *cmd, int *i, int cmdc, int *fd);
int		exec_single_builtin(t_terminal *term, int cmdc, int *fd, int *i);
void	exec_piped_builtin(t_terminal *term, int cmdc, int *fd, int *i);

//exec.c
void	pre_exec_error_msg(t_terminal *term, char *str, int exit_code);
void	ft_execve(t_terminal *term, int *i, int cmdc, int *fd);
void	exec(t_terminal *term, int cmdc);

//make_redir.c
int		check_fds(t_cmd *cmd, int io_flag);
int		get_fd_exec(t_cmd *cmd, int io_flag);
int		fd_error(char *str);
int		redir_management(t_terminal *term, int *i, int cmdc, int *fd);

//path.c
char	*search_cmd(t_terminal *term, char *cmd, int *fd, int cmdc);
void	check_exec_args(t_terminal *term, int cmdc, int *fd);

#endif
