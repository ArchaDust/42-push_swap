/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_sortb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:54:14 by aberneli          #+#    #+#             */
/*   Updated: 2021/12/22 12:05:16 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	super_sortb(t_prg *p, int low, int high)
{
	int	pos;
	int	i;

	if (p->b.size < 1)
		return (0);
	i = low;
	while (i < high)
	{
		pos = find_x(p->b.top, i++);
		if (pos < 0)
			continue ;
		if (pos <= p->b.size / 2)
			rotate_x(&p->b, pos, rb);
		else
			rotate_x(&p->b, p->b.size - pos, rrb);
		pa(&p->a, &p->b);
		ra(&p->a);
	}
	return (1);
}
