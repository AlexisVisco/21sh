/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 18:51:30 by alexis       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 11:46:33 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int mod;
	int res;

	mod = 1;
	res = 0;
	while (*str == ' ' || (*str >= '\a' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
		mod = *str++ == '-' ? -1 : 1;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + (*str++ - '0');
	return (res * mod);
}
