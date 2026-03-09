/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:39:40 by gchalmel          #+#    #+#             */
/*   Updated: 2026/03/09 18:30:40 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
#define EXPAND_H

#include "../lexer/lexer.h"

typedef enum e_expand_type
{
    ENV,
    //ONE_DOLLARS,
    EXIT_STATUS,
    NONE,
} t_expand_type;

typedef struct s_expand_ctx
{
    int index;
    int end;
    t_expand_type ex_type;
} t_expand_ctx;

void expand(t_token **token, t_terminal term);
void make_expand_env(t_token **token, t_token *curr, int index, int end, 
                         char **envp);
int ft_strlen_sep(char *s, char fin);
void make_exit_status(t_token *token, t_terminal term, int index);
char *ft_getenv(char **envp, char *var);
int	get_var_name_len(char *str);
t_token	*del_token(t_token **token, t_token *curr);
t_token	*retokenize(t_token **token, t_token *curr, char *final_token);
char	*ft_clear_expand(char *str);

#endif
