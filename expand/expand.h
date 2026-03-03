/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:39:40 by gchalmel          #+#    #+#             */
/*   Updated: 2026/02/24 17:48:58 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
#define EXPAND_H

#include "../lexer/lexer.h"

typedef enum e_expand_type
{
    ENV,
    ONE_DOLLARS,
    EXIT_STATUS,
    NONE,
} t_expand_type;

typedef struct s_expand_ctx
{
    int index;
    t_expand_type ex_type;
} t_expand_ctx;

void expand(t_token **token, t_terminal term);
t_token *make_expand_env(t_token **token, t_token *curr, int index,
                         char **envp);
int ft_strlen_sep(char *s, char fin);
void make_exit_status(t_token *token, t_terminal term);
char *ft_getenv(char **envp, char *var);
t_token	*retokenize(t_token **token, t_token *curr, char *final_token);

#endif
