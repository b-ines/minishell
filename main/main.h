/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:00:16 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/06 17:44:17 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

typedef struct s_outfile
{
	char				*outfile;
	int					append;
	struct s_outfile	*next;
} t_outfile;

typedef struct s_infile
{
	char			*infile;
	struct s_infile	*next;
} t_infile;

typedef struct s_heredoc
{
	char				*here_doc_delim;
	int					heredoc_quoted;
	int					heredoc_fd;
	struct s_heredoc	*next;
} t_heredoc;

typedef struct s_cmd
{
	char			**argv;
	char		 	*infile;
	char			*outfile;
	t_infile	 	*infile_list; // il faut garder le dernier quand meme poru lexec et la liste sert que a tout ouvrir et check au debut
	t_outfile	 	*outfile_list;
	t_heredoc		*heredoc_list;
	int				heredoc_fd;
	int				append;
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

typedef enum e_gmod 
{
	PROMPT,
	HEREDOC,
	HEREDOC_ABORTED,
	HEREDOC_QUIT,
	EXEC,
}	t_gmod;

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

t_terminal *get_term();

//signals.c
void		handler(int sig, siginfo_t *info, void *context);
void		signal_init(t_terminal *terminal);

//early_parser.c
int 		empty_cmd(t_terminal *terminal, char *line);

//terminal_init.c
t_terminal	*terminal_init(char **envp);

// g_mod_access.c
void	init_gmod();
void	set_gmod(t_gmod new_mode);
t_gmod	get_gmod();

#endif
