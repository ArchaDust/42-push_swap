/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_fetchrange.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 08:56:11 by aberneli          #+#    #+#             */
/*   Updated: 2021/12/22 13:09:09 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	distance_from_top(int pos, int size)
{
	int	distance;

	distance = pos;
	if (pos >= size / 2)
		distance = size - pos + 1;
	return (distance);
}

static int	find_closest(t_prg *p, int low, int high)
{
	int	distance;
	int	closest;
	int	i;
	int	tmp;

	distance = p->a.size;
	closest = -1;
	i = 0;
	while (i < high - low)
	{
		tmp = find_x(p->a.top, low + i);
		if (tmp >= 0)
		{
			if (distance_from_top(tmp, p->a.size) < distance)
			{
				distance = distance_from_top(tmp, p->a.size);
				closest = low + i;
			}
		}
		i++;
	}
	return (closest);
}

static void	rewind_a(t_prg *p, int n)
{
	int	pos;

	pos = find_x(p->a.top, n);
	if (pos < 0)
		return ;
	if (pos == p->a.size - 1)
		return ;
	if (pos < p->a.size / 2)
		rotate_x(&p->a, pos + 1, ra);
	else
		rotate_x(&p->a, p->a.size - pos - 1, rra);
}

int	super_fetchrange(t_prg *p, int low, int high)
{
	int		i;
	int		len;

	len = high - low;
	i = 0;
	while (i < len)
	{
		super_fetchx(p, find_closest(p, low, high));
		i++;
	}
	if (low > 0)
		rewind_a(p, low - 1);
	return (1);
}
