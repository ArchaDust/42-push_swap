/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:52:17 by aberneli          #+#    #+#             */
/*   Updated: 2021/12/18 11:26:11 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_destroy(t_stack *s)
{
	t_data	*tmp;
	t_data	*d;

	d = s->top;
	while (d)
	{
		tmp = d->next;
		free(d);
		d = tmp;
	}
	s->top = NULL;
}

t_data	*stack_pop(t_stack *s)
{
	t_data	*tmp;

	tmp = s->top;
	s->top = tmp->next;
	tmp->next = NULL;
	s->size--;
	return (tmp);
}

void	stack_push(t_stack *s, t_data *d)
{
	if (!s->top)
	{
		s->top = d;
		s->size++;
		return ;
	}
	d->next = s->top;
	s->top = d;
	s->size++;
}
