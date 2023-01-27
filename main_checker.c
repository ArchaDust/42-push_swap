/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:35:32 by aberneli          #+#    #+#             */
/*   Updated: 2022/01/04 10:43:45 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

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

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n < 1)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if ((unsigned char)(s1[i]) != (unsigned char)(s2[i]))
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		i++;
	}
	if (i >= n)
		return (0);
	if (s1[i] == '\0' || s2[i] == '\0')
	{
		if ((unsigned char)(s1[i]) != (unsigned char)(s2[i]))
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
	}
	return (0);
}

static int	check_op(t_prg *p, char *line)
{
	if (ft_strncmp(line, "sa\n", 4) == 0)
		return (sa(&p->a) * 0 + 1);
	if (ft_strncmp(line, "sb\n", 4) == 0)
		return (sb(&p->b) * 0 + 1);
	if (ft_strncmp(line, "ss\n", 4) == 0)
		return (ss(&p->a, &p->b) * 0 + 1);
	if (ft_strncmp(line, "pa\n", 4) == 0)
		return (pa(&p->a, &p->b) * 0 + 1);
	if (ft_strncmp(line, "pb\n", 4) == 0)
		return (pb(&p->a, &p->b) * 0 + 1);
	if (ft_strncmp(line, "ra\n", 4) == 0)
		return (ra(&p->a) * 0 + 1);
	if (ft_strncmp(line, "rb\n", 4) == 0)
		return (rb(&p->b) * 0 + 1);
	if (ft_strncmp(line, "rr\n", 4) == 0)
		return (rr(&p->a, &p->b) * 0 + 1);
	if (ft_strncmp(line, "rra\n", 5) == 0)
		return (rra(&p->a) * 0 + 1);
	if (ft_strncmp(line, "rrb\n", 5) == 0)
		return (rrb(&p->b) * 0 + 1);
	if (ft_strncmp(line, "rrr\n", 5) == 0)
		return (rrr(&p->a, &p->b) * 0 + 1);
	return (0);
}

static int	read_input(t_prg *p)
{
	char	*line;
	int		status;

	status = 1;
	line = get_next_line(0);
	p->a.log = 0;
	p->b.log = 0;
	while (line)
	{
		status = check_op(p, line);
		free(line);
		if (!status)
			return (0);
		line = get_next_line(0);
	}
	free(line);
	return (1);
}

int	main(int argc, char **argv)
{
	t_prg	p;

	if (argc < 2)
		return (0);
	p.a.top = NULL;
	p.b.top = NULL;
	if (!stack_fill(&p, argc, argv))
	{
		stack_destroy(&p.a);
		write(1, "Error\n", 6);
		return (0);
	}
	if (read_input(&p))
	{
		if (check_sorted(&p.a, &p.b))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else
		write(1, "Error\n", 6);
	stack_destroy(&p.a);
	stack_destroy(&p.b);
	return (0);
}
