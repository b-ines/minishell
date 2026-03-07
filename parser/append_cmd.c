/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:50:26 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/06 19:11:53 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//cest pas jsute les echo et argv quil faut retokeniser en ignorant les "" cest tout

//commandes ok

// > KO - >> KO - << KO - < KO - recheck comment jai fais avec word ca amrche niquel 
// | KO si entre guillemets il est pris comme un arg de commande FIXED

//fixed pour exterieur au mot - il faut concatener le mot mtn uen seule fonction concat pour tous ca passe jpense (tant que pas espace jignore les strvide et jappend)

//expand : on expand pas quand ya plusieurs expand dans un quote "$USER $USER" segault

// cat <dontextist | cat nous on a $? a 1 pcq check avant alors que bash $? 0 pcq valeur du cat 

//le heredoc le faire a part dans le addheredoc si un des char est quote ca compte comme tout quote e"o"f cest quoted plus facile que de faire passer une str condition darret cest espace

//EN COURS
//append marche apres pas avant

//il faut faire les redir APRES le parser pas avant !! la il dans valid syntax mais en gros faut en refaire un juste pour les redir genre valid_redir 
// les append aussi ils ecrivent que sur le dernier cest considere comme un outfile

//argv pb aussi si je fais cat > outfile b - ou echo >outf b le b ecrase le echo

void	add_append(t_token **current, t_cmd *new_node)
{
	(*current) = (*current)->next;
	if ((*current) && (*current)->type == SSPACE)
		(*current) = (*current)->next;
	if (*current && (*current)->type == WORD)
		addback_outfile(new_node, current, 1);
	if ((*current) && (*current)->next)
		(*current) = (*current)->next;
	if ((*current) && (*current)->type == SSPACE)
		(*current) = (*current)->next;
}

void	add_heredoc(t_token **current, t_cmd *new_node)
{
	(*current) = (*current)->next;
	if ((*current) && (*current)->type == SSPACE)
		(*current) = (*current)->next;
	if (*current && (*current)->type == WORD)
		addback_heredoc(new_node, current);
	if ((*current) && (*current)->next)
		(*current) = (*current)->next;
	if ((*current) && (*current)->type == SSPACE)
		(*current) = (*current)->next;
}

void	add_redir_input(t_token **current, t_cmd *new_node)
{
	(*current) = (*current)->next;
	if ((*current) && (*current)->type == SSPACE)
		(*current) = (*current)->next;
	if (*current && (*current)->type == WORD)
		addback_infile(new_node, current);
	if (*current && (*current)->next)
		(*current) = (*current)->next;
	if ((*current) && (*current)->type == SSPACE)
		(*current) = (*current)->next;
}

void	add_redir_output(t_token **current, t_cmd *new_node)
{
	(*current) = (*current)->next;
	if ((*current) && (*current)->type == SSPACE)
		(*current) = (*current)->next;
	if (*current && (*current)->type == WORD)
		addback_outfile(new_node, current, 0);
	if (*current && (*current)->next)
		(*current) = (*current)->next;
	if ((*current) && (*current)->type == SSPACE)
		(*current) = (*current)->next;
}
