/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:58:24 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/09 12:19:53 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../main/main.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <unistd.h>

//builtins.c
int		tab_size(char **argv);
int		is_builtins(t_cmd *cmd);
void	run_builtins(t_terminal *terminal, t_cmd *cmd, int fd, int piped);

//run_builtins.c
void	run_echo(t_terminal *terminal, t_cmd *cmd, int fd);
void	run_exit(t_terminal *terminal, t_cmd *cmd, int piped);
void	run_pwd(t_terminal *terminal, t_cmd *cmd, int fd);

//run_env_unset.c
void	run_env(t_terminal *terminal, t_cmd *cmd, int fd);
void	run_unset(t_terminal *terminal, t_cmd *cmd);

//env_utils.c
int		get_index_by_key(t_terminal *terminal, char *key);
char	*get_key_by_index(t_terminal *terminal, int index);
char	*get_value_by_key(t_terminal *terminal, char *key);
int		change_value_by_key(t_terminal *terminal, char *key, char *new_value);

//env_export_utils.c
int		get_index_by_key_e(t_terminal *terminal, char *key);
int		change_value_by_key_e(t_terminal *terminal, char *key, char *new_v);

//run_cd.c
int		get_arg_type(char *path);
void	change_dir(t_terminal *terminal, t_cmd *cmd);
void	run_cd(t_terminal *terminal, t_cmd *cmd);

//run_export.c
char	*get_key(char *str);
void	run_export(t_terminal *terminal, t_cmd *cmd, int fd);

//run_export_utils.c
int		valid_arg_export(char *str);
char	*get_key(char *str);
char	*get_value(char *str);
int		key_already_in_env(t_terminal *terminal, char *cmd);

//print_sorted_env.c
void	print_sorted_envp(char **envp_export, int fd);

#endif