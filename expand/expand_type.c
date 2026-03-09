/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:42:33 by gchalmel          #+#    #+#             */
/*   Updated: 2026/03/09 17:17:07 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lexer/lexer.h"
#include "../libft/libft.h"
#include "expand.h"

//il faut prendre la longueur de la chaine a expand pour le compare et pour la changer ensuite
//garder lenoeud ou remplacer par "" quand ya que ca ?? jsp c vrmt un detail

t_token	*del_token(t_token **token, t_token *curr)
{
	t_token	*next;

	next = curr->next;
	if (curr->prev)
		curr->prev->next = curr->next;
	else
		*token = curr->next;
	if (curr->next)
		curr->next->prev = curr->prev;
	return (next);
}

t_token	*make_expand_env(t_token **token, t_token *curr, int index, int end, char **envp)
{
	char	*var;
	char	*final_token;
	int		len_before_dollar;
	size_t	len_var;
    int		len_after_dollar;
	t_token	*ret_node;

    char *to_expand = ft_strndup(&curr->token[index], end);
    int expand_size = ft_strlen(to_expand);
    var = ft_getenv(envp, to_expand);
    ret_node = NULL;
    // if (index > 1)
    // {
        if (var == NULL)
            len_var = 0;
        else
            len_var = ft_strlen(var);
        len_before_dollar = ft_strlen_sep(curr->token, '$');
        printf("leb before = %d\n", len_before_dollar);
        len_after_dollar = ft_strlen(curr->token) - (len_before_dollar + expand_size + 1);
        final_token = ft_malloc(sizeof(char) * (len_before_dollar + len_var + len_after_dollar + 1));
        ft_strlcpy(final_token, curr->token, len_before_dollar + 1);
        if (var != NULL)
            ft_strlcat(final_token, var, len_before_dollar + len_var + 1);
        //ft_strcat(final_token, &curr->token[len_before_dollar + expand_size + 1]);
        final_token = ft_strjoin(final_token, &curr->token[len_before_dollar + expand_size + 1]);
        printf("final token = %s\n", final_token);
    //}
    // else
    //     final_token = var;
    if (final_token == NULL)
        return (del_token(token, curr));
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

void make_exit_status(t_token *token, t_terminal term, int index)
{
	char	*var;
	char	*final_token;
	int		len_before_dollar;
	size_t	len_var;

    var = ft_itoa(term.exit_status);
    if (token->token[index + 1] != '\0')
		var = ft_strjoin(var, &token->token[index + 1]);
    if (index > 1)
    {
        if (var == NULL)
            len_var = 0;
        else
            len_var = ft_strlen(var);
        len_before_dollar = ft_strlen_sep(token->token, '$');
        final_token = ft_malloc(sizeof(char) * len_before_dollar + len_var + 1);
        ft_strlcpy(final_token, token->token, len_before_dollar + 1);
        if (var != NULL)
            ft_strlcat(final_token, var, len_before_dollar + len_var + 1);
    }
    else
        final_token = var;
    ft_free_malloc(token->token);
    token->token = final_token;
}
