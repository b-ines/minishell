/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:42:33 by gchalmel          #+#    #+#             */
/*   Updated: 2026/02/24 17:48:16 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
#include "../libft/libft.h"
#include "../lexer/lexer.h"

t_token	*make_expand_env(t_token **token, t_token *curr, int index, char **envp)
{
	char	*var;
	char	*final_token;
	int		len_before_dollar;
	size_t	len_var;
	t_token	*ret_node;

	printf("Expand detected on: %s\n", curr->token);
	var = ft_getenv(envp, &curr->token[index]);
	if (index > 1)
	{
		if (var == NULL)
			len_var = 0;
		else
			len_var = ft_strlen(var);
		len_before_dollar = ft_strlen_sep(curr->token, '$');
		final_token = malloc(sizeof(char) * len_before_dollar
				+ len_var + 1);
		ft_strlcpy(final_token, curr->token, len_before_dollar + 1);
		if (var != NULL)
			ft_strlcat(final_token, var, len_before_dollar + len_var + 1);
	}
	else
		final_token = var;
	if (curr->quote_flag == 0)
	{
		char	**split_token;
		t_token	*token_new;
		t_token	*token_cpy;
		int		i;

		token_new = NULL;
		split_token = ft_split(final_token, ' ');
		i = 1;
		ft_addback(&token_new, split_token[0], 0);
		while (split_token[i] != NULL)
		{
			ft_addback(&token_new, " ", 0);
			ft_addback(&token_new, split_token[i++], 0);
		}
		set_type(&token_new);
		token_cpy = curr->next;
		if (curr->prev != NULL)
		{
			curr = curr->prev;
			// free((*token)->next->token);
			// free((*token)->next);
			curr->next = NULL;
			curr->next = token_new;
			token_new->prev = curr;
			ret_node = NULL;
		}
		else
		{
			(*token) = token_new;
			ret_node = NULL;
		}
		if (token_cpy != NULL)
		{
			t_token	*head;

			head = *token;
			while (head->next != NULL)
				head = head->next;
			head->next = token_cpy;
			token_cpy->prev = head;
			ret_node = token_cpy;
		}
	}
	else
	{
		free(curr->token);
		curr->token = final_token;
		ret_node = (curr->next);
	}
	return (ret_node);
}

void	make_exit_status(t_token *token, t_terminal term)
{
	free(token->token);
	token->token = ft_itoa(term.exit_status);
}

