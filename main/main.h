/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:00:16 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/16 17:29:20 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../libft/libft.h"
# include "../lexer/lexer.h"
# include <signal.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_files
{
	char			*file;
	int				type;
	int				append;
	struct s_files	*next;
}	t_files;

typedef struct s_heredoc
{
	char				*here_doc_delim;
	int					heredoc_quoted;
	int					heredoc_fd;
	struct s_heredoc	*next;
}	t_heredoc;

typedef struct s_cmd
{
	char			**argv;
	char			*infile;
	char			*outfile;
	t_files			*files_list;
	t_heredoc		*heredoc_list;
	int				heredoc_fd;
	int				append;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

typedef struct s_terminal
{
	int				exit_status;
	char			**envp;
	char			**envp_export;
	struct s_cmd	*cmd_blocks;
}	t_terminal;

typedef enum e_gmod
{
	PROMPT,
	HEREDOC,
	HEREDOC_ABORTED,
	HEREDOC_QUIT,
	EXEC,
}	t_gmod;

t_terminal	*get_term(void);

//signals.c
void		handler(int sig, siginfo_t *info, void *context);
void		signal_init(void);

//early_parser.c
int			empty_cmd(t_terminal *terminal, char *line);

//terminal_init.c
t_terminal	*terminal_init(char **envp);

// g_mod_access.c
void		init_gmod(void);
void		set_gmod(t_gmod new_mode);
t_gmod		get_gmod(void);

#endif
