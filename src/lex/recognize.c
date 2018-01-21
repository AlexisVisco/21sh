/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   recognize.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/20 17:07:59 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/21 12:32:42 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

char			*ft_removeq(char *s)
{
	char	quote;
	char	*new;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	new = ft_strnew(ft_strlen(s) - 2);
	if (s[0] == '\'' || s[0] == '\"')
	{
		quote = s[0];
		while (s[i])
		{
			if (s[i] == quote && s[i - 1] != '\\')
				i++;
			else
				new[j++] = s[i++];
		}
	}
	else
		ft_strdel(&new);
	return (new ? new : NULL);
}

static void		ft_minirecognize(t_token ***tokens)
{
	int		i;

	i = 0;
	while ((*tokens)[i])
	{
		if (ft_strchr(FT_SEP, (*tokens)[i]->value[0]))
			(*tokens)[i++]->type = SEP_OP;
		else if (ft_strchr(FT_REDIR, (*tokens)[i]->value[0]) || 
		(ft_isdigit((*tokens)[i]->value[0]) && 
		ft_strchr(FT_REDIR, (*tokens)[i]->value[1])))
			(*tokens)[i++]->type = SEP_OP;
		else if (i == 0 || ((*tokens)[i - 1]->type == SEP_OP))
			(*tokens)[i++]->type = COMMAND;
		else if ((*tokens)[i - 1]->type == IO_REDIR)
			(*tokens)[i++]->type = FD_FILE;
		else
			(*tokens)[i++]->type = ARG;
	}
}

void		ft_lexall(t_token ***tokens, char *s)
{
	int		i;
	int		nbtokens;
	
	i = 1;
	if ((nbtokens = ft_counttoken(s)) == -2)
	{
		ft_printf("Error, review your quotes!\n");
		return ;
	}
	else if (nbtokens == 0)
		return ;
	*tokens = ft_splittokens(s, nbtokens);
	ft_minirecognize(tokens);
//	while ()
/*	while (tokens[i])
		ft_printf("tokens %i : %s\n", i, tokens[i++]->value);*/
}