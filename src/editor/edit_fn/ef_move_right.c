/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ef_move_right.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 20:31:56 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 13:59:09 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** Move current position of the cursor to the right if it is possible
*/

void	ef_move_right(t_editor *l)
{
	if (l->pos != l->len)
		l->pos++;
}
