/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:40:10 by gchalmel          #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2026/02/24 17:36:07 by inbeaumo         ###   ########.fr       */
=======
/*   Updated: 2026/02/24 16:28:38 by gchalmel         ###   ########.fr       */
>>>>>>> 9e7ac20 (first commit for retokenisation)
=======
/*   Updated: 2026/02/24 17:48:38 by gchalmel         ###   ########.fr       */
>>>>>>> ba39bd7 (add first implementation for retokenise Warining : need more test and norm)
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
#include "../execve/exec.h"
#include "../libft/libft.h"
#include "../main/main.h"
#include <stdio.h>
#include <stdlib.h>

static t_expand_ctx is_expand(t_token token) {
  int i;

<<<<<<< HEAD
	i = 0;
	if (token.quote_flag == 1)
		return ((t_expand_ctx){i, NONE});
	while (token.token[i] != '\0')
	{
		if (token.type == WORD)
		{
			if (token.token[i] == '$' && ft_isalpha(token.token[i + 1]))
				return ((t_expand_ctx){i + 1, ENV});
			else if (token.token[i] == '$' && token.token[i + 1] == '$')
				return ((t_expand_ctx){i + 1, ENV});
			else if (token.token[i] == '$' && token.token[i + 1] == '?')
				return ((t_expand_ctx){i + 1, EXIT_STATUS});
		}
		i++;
	}
	//printf("expand inconn\n");
	return ((t_expand_ctx){i, NONE});
=======
  i = 0;
  if (token.quote_flag == 1)
    return ((t_expand_ctx){i, NONE});
  while (token.token[i] != '\0') {
    if (token.type == WORD) {
      if (token.token[i] == '$' && ft_isalpha(token.token[i + 1]))
        return ((t_expand_ctx){i + 1, ENV});
      else if (token.token[i] == '$' && token.token[i + 1] == '$')
        return ((t_expand_ctx){i + 1, ENV});
      else if (token.token[i] == '$' && token.token[i + 1] == '?')
        return ((t_expand_ctx){i + 1, EXIT_STATUS});
    }
    i++;
  }
  printf("expand inconn\n");
  return ((t_expand_ctx){i, NONE});
>>>>>>> 5a75caf (norminette)
}

void expand(t_token **token, t_terminal term) {
  t_expand_ctx ctx;
  t_token *curr;

<<<<<<< HEAD
<<<<<<< HEAD
	//printf("Step to expand\n");
	while (token != NULL)
=======
	printf("Step to expand\n");
	curr = *token;
	while (curr != NULL)
>>>>>>> ba39bd7 (add first implementation for retokenise Warining : need more test and norm)
	{
		ctx = is_expand(*curr);
		if (ctx.ex_type == ENV)
			curr = make_expand_env(token, curr, ctx.index, term.envp);
		else if (ctx.ex_type == EXIT_STATUS)
			make_exit_status(curr, term);
		else
			curr = curr->next;
	}
=======
  printf("Step to expand\n");
  curr = *token;
  while (curr != NULL) {
    ctx = is_expand(*curr);
    if (ctx.ex_type == ENV)
      curr = make_expand_env(token, curr, ctx.index, term.envp);
    else if (ctx.ex_type == EXIT_STATUS)
      make_exit_status(curr, term);
    else
      curr = curr->next;
  }
>>>>>>> 5a75caf (norminette)
}
