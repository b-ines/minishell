/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:42:33 by gchalmel          #+#    #+#             */
/*   Updated: 2026/03/06 13:29:14 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer/lexer.h"
#include "../libft/libft.h"
#include "expand.h"

t_token	*make_expand_env(t_token **token, t_token *curr, int index, char **envp)
{
	char	*var;
	char	*final_token;
	int		len_before_dollar;
	size_t	len_var;
	t_token	*ret_node;

    //printf("Expand detected on: %s\n", curr->token);
    var = ft_getenv(envp, &curr->token[index]);
    ret_node = NULL;
    if (index > 1)
    {
        if (var == NULL)
            len_var = 0;
        else
            len_var = ft_strlen(var);
        len_before_dollar = ft_strlen_sep(curr->token, '$');
        final_token = ft_malloc(sizeof(char) * len_before_dollar + len_var + 1);
        ft_strlcpy(final_token, curr->token, len_before_dollar + 1);
        if (var != NULL)
            ft_strlcat(final_token, var, len_before_dollar + len_var + 1);
    }
    else
        final_token = var;
    if (curr->quote_flag == 0)
        ret_node = retokenize(token, curr, final_token);
    else
    {
        ft_free_malloc(curr->token);
        curr->token = final_token;
        ret_node = (curr->next);
    }
    return (ret_node);
}

void make_exit_status(t_token *token, t_terminal term)
{
    ft_free_malloc(token->token);
    token->token = ft_itoa(term.exit_status);
}
