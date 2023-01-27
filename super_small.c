/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:31:27 by aberneli          #+#    #+#             */
/*   Updated: 2021/12/22 14:43:15 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	compare_indexes(t_stack *s, int i1, int i2)
{
	int	val1;
	int	val2;

	val1 = find_index(s->top, i1);
	val2 = find_index(s->top, i2);
	if (val1 < 0 || val2 < 0)
		return (0);
	return (val1 - val2);
}

static void	sort_short_a_ex(t_stack *s)
{
	if (compare_indexes(s, 0, 1) <= 0 && compare_indexes(s, 1, 2) <= 0)
		return ;
	if (compare_indexes(s, 0, 1) > 0 && compare_indexes(s, 1, 2) > 0)
		sa(s);
	else if (compare_indexes(s, 0, 1) < 0 && compare_indexes(s, 1, 2) > 0 \
			&& compare_indexes(s, 0, 2) < 0)
		rra(s);
	if (compare_indexes(s, 0, 1) > 0 && compare_indexes(s, 1, 2) < 0 \
			&& compare_indexes(s, 0, 2) < 0)
		sa(s);
	else if (compare_indexes(s, 0, 1) < 0 && compare_indexes(s, 1, 2) > 0 \
			&& compare_indexes(s, 0, 2) > 0)
		rra(s);
	else
		ra(s);
}

static void	sort_short_a(t_stack *s)
{
	if (s->size <= 1)
		return ;
	if (s->size == 2)
	{
		if (compare_indexes(s, 0, 1) > 0)
			sa(s);
		return ;
	}
	sort_short_a_ex(s);
}

int	super_small(t_prg *p)
{
	int	i;

	if (p->size > 6)
		return (0);
	i = 0;
	while (i < p->size - 3)
		super_fetchx(p, i++);
	sort_short_a(&p->a);
	while (p->b.size > 0)
		pa(&p->a, &p->b);
	return (1);
}
