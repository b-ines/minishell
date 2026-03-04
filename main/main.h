/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:00:16 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/04 14:59:44 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

typedef struct s_heredoc
{
	char			*here_doc_delim;
	int				heredoc_quoted;
	int				heredoc_fd;
	struct s_heredoc	*next;
} t_heredoc;

typedef struct s_cmd
{
	char			**argv;
	char		 	*infile;
	char			*outfile;
	t_heredoc		*heredoc_list;
	int				append;
	int				heredoc_fd;
	struct s_cmd	*next;
	struct s_cmd	*prev;
} t_cmd;

typedef struct s_terminal
{
	int				exit_status;
	char			**envp;
	char			**envp_export;
	struct s_cmd    *cmd_blocks;
}   t_terminal;

typedef struct s_token t_token;

# include "../lexer/lexer.h"
# include "../libft/libft.h"
# include "../parser/parser.h"
# include "../expand/expand.h"
# include "../heredoc/heredoc.h"
# include "../builtins/builtins.h"
# include "../execve/exec.h"
# include <signal.h>
//readline
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

//signals.c
void		handler(int sig, siginfo_t *info, void *context);
void		signal_init(t_terminal *terminal);

//early_parser.c
int 		empty_cmd(t_terminal *terminal, char *line);

//terminal_init.c
t_terminal	*terminal_init(char **envp);

#endif