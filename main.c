/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:48:02 by aberneli          #+#    #+#             */
/*   Updated: 2022/01/04 10:42:40 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	check_sorted(t_stack *a, t_stack *b)
{
	t_data	*d;
	int		last;

	if (b->top || !a->top)
		return (0);
	d = a->top;
	last = d->n;
	d = d->next;
	while (d)
	{
		if (last > d->n)
			return (0);
		last = d->n;
		d = d->next;
	}
	return (1);
}

static int	consider_div(int size)
{
	if (size <= 40)
		return (3);
	if (size <= 100)
		return (4);
	if (size <= 500)
		return (10);
	return (size / 50);
}

static void	push_swap(t_prg *p)
{
	int		i;
	int		div;
	float	step;

	i = 0;
	div = consider_div(p->size);
	step = (float)p->size / (float)div;
	while (i < div)
	{
		super_fetchrange(p, i * step, (i + 1) * step);
		super_sortb(p, i * step, (i + 1) * step);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_prg	p;

	if (argc < 2)
		return (0);
	p.a.top = NULL;
	p.b.top = NULL;
	p.a.log = 1;
	p.b.log = 1;
	if (!stack_fill(&p, argc, argv))
	{
		stack_destroy(&p.a);
		write(1, "Error\n", 6);
		return (0);
	}
	if (p.a.size < 2)
	{
		stack_destroy(&p.a);
		return (0);
	}
	if (!check_sorted(&p.a, &p.b))
		if (!super_small(&p))
			push_swap(&p);
	stack_destroy(&p.a);
	stack_destroy(&p.b);
	return (0);
}
