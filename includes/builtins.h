/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtins.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 18:45:07 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/06 12:23:29 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "shell.h"

typedef int(t_builtins_fun)(char **, t_shell *);

t_builtins_fun	*builtins(char *cmd);
t_hashtable		*get_builtins();
int				b_pwd(char **args, t_shell *shell);
int				b_env(char **args, t_shell *shell);
int				b_env_set(char **args, t_shell *shell);
int				b_env_unset(char **args, t_shell *shell);
int				b_clear(char **args, t_shell *shell);
int				b_exit(char **args, t_shell *shell);
int				b_binary_search(char **args, t_shell *shell);

#endif
