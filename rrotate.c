/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:30:28 by aberneli          #+#    #+#             */
/*   Updated: 2021/12/22 17:32:40 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rrotate(t_stack *s)
{
	t_data	*d;

	if (s->size < 2)
		return (0);
	d = s->top;
	while (d->next->next)
		d = d->next;
	d->next->next = s->top;
	s->top = d->next;
	d->next = NULL;
	return (1);
}

int	rra(t_stack *a)
{
	if (!rrotate(a))
		return (0);
	if (a->log)
		write(1, "rra\n", 4);
	return (1);
}

int	rrb(t_stack *b)
{
	if (!rrotate(b))
		return (0);
	if (b->log)
		write(1, "rrb\n", 4);
	return (1);
}

int	rrr(t_stack *a, t_stack *b)
{
	rrotate(a);
	rrotate(b);
	if (a->log)
		write(1, "rrr\n", 4);
	return (1);
}
