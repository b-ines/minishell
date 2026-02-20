/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:42:33 by gchalmel          #+#    #+#             */
/*   Updated: 2026/02/20 16:43:11 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
#include "../libft/libft.h"

void	make_expand_env(t_token *token, int index, char **envp)
{
	char	*var;
	char	*final_token;
	int		len_before_dollar;
	size_t	len_var;

	printf("Expand detected on: %s\n", token->token);
	var = ft_getenv(envp, &token->token[index]);
	if (index > 1)
	{
		if (var == NULL)
			len_var = 0;
		else
			len_var = ft_strlen(var);
		len_before_dollar = ft_strlen_sep(token->token, '$');
		final_token = malloc(sizeof(char) * len_before_dollar
				+ len_var + 1);
		ft_strlcpy(final_token, token->token, len_before_dollar + 1);
		if (var != NULL)
			ft_strlcat(final_token, var, len_before_dollar + len_var + 1);
	}
	else
		final_token = var;
	free(token->token);
	token->token = final_token;
}
