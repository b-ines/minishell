/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:39:40 by gchalmel          #+#    #+#             */
/*   Updated: 2026/02/20 15:30:25 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "../lexer/lexer.h"

typedef enum e_expand_type
{
	ENV,
	ONE_DOLLARS,
	EXIT_STATUS,
	ENV_PLUS_ONE_DOLLARS,
	NONE,
}	t_expand_type;

typedef struct s_expand_ctx
{
	int				index;
	t_expand_type	ex_type;
}	t_expand_ctx;

void	expand(t_token *token, t_terminal term);

#endif
