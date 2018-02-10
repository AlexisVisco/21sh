/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   open_file.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/03 18:41:11 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/10 13:54:37 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int	open_right_redir(char **str, int flag, int i)
{
	int	file;

	if (str[i + 1] == NULL)
		return (-1);
	file = open(str[i + 1], O_WRONLY | O_CREAT | flag, 0644);
	if (file < 0)
	{
		if (errno == EISDIR)
			message_err(ERR_IS_DIR, str[i + 1]);
		else if (access(str[i + 1], X_OK) == -1)
			message_err(ERR_ACCES, str[i + 1]);
		else
			message_err(ERR_EXIST, str[i + 1]);
	}
	return (file);
}

int			call_right_redir(char **cmds)
{
	int	k;
	int	fd;

	k = 0;
	while (cmds[k])
	{
		if (ft_strequ(cmds[k], ">>"))
		{
			fd = open_right_redir(cmds, O_APPEND, k);
			break ;
		}
		else if (ft_strequ(cmds[k], ">"))
		{
			fd = open_right_redir(cmds, O_TRUNC, k);
			break ;
		}
		k++;
	}
	if (cmds[k] == NULL)
		return (1);
	free(cmds[k]);
	free(cmds[k + 1]);
	cmds[k] = NULL;
	return (fd);
}

static void	error_left_redir(int fd, int k, char **cmds)
{
	if (fd < 0)
	{
		if (errno == EISDIR)
			message_err(ERR_IS_DIR, cmds[k + 1]);
		else if (access(cmds[k + 1], X_OK) == -1)
			message_err(ERR_ACCES, cmds[k + 1]);
		else
			message_err(ERR_EXIST, cmds[k + 1]);
	}
}

int			call_left_redir(char **cmds)
{
	int	k;
	int	fd;

	k = 0;
	fd = 0;
	while (cmds[k])
	{
		if (ft_strequ(cmds[k], "<"))
		{
			fd = open(cmds[k + 1], O_RDONLY, 0644);
			break ;
		}
		k++;
	}
	error_left_redir(fd, k, cmds);
	if (cmds[k] == NULL)
		return (0);
	free(cmds[k]);
	free(cmds[k + 1]);
	cmds[k] = NULL;
	return (fd);
}
