/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:57:50 by aberneli          #+#    #+#             */
/*   Updated: 2021/12/22 17:33:28 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *s)
{
	int	tmp;

	if (s->size < 2)
		return (0);
	tmp = s->top->n;
	s->top->n = s->top->next->n;
	s->top->next->n = tmp;
	return (1);
}

int	sa(t_stack *a)
{
	if (!swap(a))
		return (0);
	if (a->log)
		write(1, "sa\n", 3);
	return (1);
}

int	sb(t_stack *b)
{
	if (!swap(b))
		return (0);
	if (b->log)
		write(1, "sb\n", 3);
	return (1);
}

int	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	if (a->log)
		write(1, "ss\n", 3);
	return (1);
}
