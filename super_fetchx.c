/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_fetchx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:46:15 by aberneli          #+#    #+#             */
/*   Updated: 2021/12/22 13:40:40 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_x(t_stack *s, int x, int (*rot)(t_stack *))
{
	int	i;

	i = 0;
	while (i < x)
	{
		(*rot)(s);
		i++;
	}
}

int	find_index(t_data *d, int index)
{
	int	i;

	i = 0;
	while (d && i <= index)
	{
		if (i == index)
			return (d->n);
		d = d->next;
		i++;
	}
	return (-1);
}

int	find_x(t_data *d, int x)
{
	int	i;

	i = 0;
	while (d)
	{
		if (d->n == x)
			return (i);
		d = d->next;
		i++;
	}
	return (-1);
}

void	super_fetchx(t_prg *p, int x)
{
	int	pos;

	pos = find_x(p->a.top, x);
	if (pos < 0)
		return ;
	if (pos <= p->a.size / 2)
	{
		rotate_x(&p->a, pos, ra);
		pb(&p->a, &p->b);
	}
	else
	{
		rotate_x(&p->a, p->a.size - pos, rra);
		pb(&p->a, &p->b);
	}
}
