/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:12:45 by aberneli          #+#    #+#             */
/*   Updated: 2021/12/22 17:32:04 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack *s1, t_stack *s2)
{
	t_data	*tmp;

	if (!s2->size)
		return (0);
	tmp = stack_pop(s2);
	stack_push(s1, tmp);
	return (1);
}

int	pa(t_stack *a, t_stack *b)
{
	if (!push(a, b))
		return (0);
	if (a->log)
		write(1, "pa\n", 3);
	return (1);
}

int	pb(t_stack *a, t_stack *b)
{
	if (!push(b, a))
		return (0);
	if (b->log)
		write(1, "pb\n", 3);
	return (1);
}
