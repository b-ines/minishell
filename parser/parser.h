/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:00:41 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/06 17:39:03 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../lexer/lexer.h"
# include "../heredoc/heredoc.h"

//syntax_check_utils.c
int		word_at_right(t_token *token);
int		word_at_left(t_token *token);
int		pipe_check(t_token *token);
int		redir_check(t_token *token);
int		make_redir(t_token *token);

//syntax_check.c
int		is_redir(t_token *token);
int		valid_syntax(t_terminal *terminal, t_token **token_head);
int 	valid_redir(t_terminal *terminal, t_token *token);

//termp_cmds_utils.c
void	add_argv(t_token **current, t_cmd *new_node);
void	add_append(t_token **current, t_cmd *new_node);
void	add_heredoc(t_token **current, t_cmd *new_node);
void	add_redir_input(t_token **current, t_cmd *new_node);
void	add_redir_output(t_token **current, t_cmd *new_node);

//parser.c
char	**make_argv(t_token *token, int size);
t_cmd	*parser(t_terminal *terminal, t_token *token);

//cmd_lists.c
t_cmd	*create_node_cmd(void);
void	ft_addback_cmd(t_cmd **cmd_head, t_cmd *new_node);
void	addback_heredoc(t_cmd *cmd, t_token **token);

//debug
void	printf_tab(char **tab);
void	printf_cmd(t_cmd *cmd);

//inf_outf_list.c
void	addback_infile(t_cmd *cmd, t_token **token);
void	addback_outfile(t_cmd *cmd, t_token **token, int append_flag);

#endif