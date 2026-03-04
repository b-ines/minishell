/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:58:24 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/03 16:17:33 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../main/main.h"
# include <fcntl.h>
# include <sys/stat.h> // lstat
# include <unistd.h> //opendir

//builtins.c
int 	is_builtins(t_cmd *cmd);
void 	run_builtins(t_terminal *terminal, t_cmd *cmd, int fd);

//run_builtins.c
void    run_echo(t_terminal *terminal, t_cmd *cmd, int fd);
void    run_exit(t_terminal *terminal, t_cmd *cmd);
void    run_pwd(t_terminal *terminal, t_cmd *cmd, int fd);

//utils.c
int	    get_fd(t_cmd *cmd);
int	    tab_size(char **argv);

//runenv
void    run_env(t_terminal *terminal, t_cmd *cmd, int fd);
void    run_unset(t_terminal *terminal, t_cmd *cmd);

//env_management.c
int		get_index_by_key(t_terminal *terminal, char *key);
char	*get_key_by_index(t_terminal *terminal, int index);
char	*get_value_by_key(t_terminal *terminal, char *key);
int		change_value_by_key(t_terminal *terminal, char *key, char *new_value);

//run_cd.c
void    run_cd(t_terminal *terminal, t_cmd *cmd);

//run_export.c
char	*get_key(char *str);
void	run_export(t_terminal *terminal, t_cmd *cmd, int fd);

//print_sorted_env.c
void	print_sorted_envp(char **envp_export, int fd);


#endif