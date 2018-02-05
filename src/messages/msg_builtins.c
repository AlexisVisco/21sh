/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   msg_builtins.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 20:56:27 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 21:01:47 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <shell.h>


static char *g_msg_builtins[] = {
		"The command pwd did not work for an unknown reason.",
		"To set env use: setenv key=value [key=value...]",
		"Env variable %s set to %s.",
		"To unset env user: unsetenv key [key...].",
		"Env variable %s is unknown.",
		"Env variable %s was unset (the value was %s).",
};

void   err_builtins(t_msg_builtins m, ...)
{
	va_list	ap;

	ft_printf("%s » ", SHELL_NAME);
	va_start(ap, m);
	core_pf(STDERR_FILENO, g_msg_builtins[m], ap);
	va_end(ap);
	ft_putchar('\n');
}

void   msg_builtins(t_msg_builtins m, ...)
{
	va_list	ap;

	ft_printf("%s » ", SHELL_NAME);
	va_start(ap, m);
	core_pf(STDOUT_FILENO, g_msg_builtins[m], ap);
	va_end(ap);
	ft_putchar('\n');
}
