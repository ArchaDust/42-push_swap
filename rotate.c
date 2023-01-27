/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:24:11 by aberneli          #+#    #+#             */
/*   Updated: 2021/12/22 17:32:26 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_stack *s)
{
	t_data	*d;

	if (s->size < 2)
		return (0);
	d = s->top;
	while (d->next)
		d = d->next;
	d->next = s->top;
	s->top = s->top->next;
	d->next->next = NULL;
	return (1);
}

int	ra(t_stack *a)
{
	if (!rotate(a))
		return (0);
	if (a->log)
		write(1, "ra\n", 3);
	return (1);
}

int	rb(t_stack *b)
{
	if (!rotate(b))
		return (0);
	if (b->log)
		write(1, "rb\n", 3);
	return (1);
}

int	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	if (a->log)
		write(1, "rr\n", 3);
	return (1);
}
