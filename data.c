/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:57:19 by aberneli          #+#    #+#             */
/*   Updated: 2021/12/22 14:42:51 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_data	*new_data(int64_t n)
{
	t_data	*d;

	if (n == INT64_MAX)
		return (NULL);
	d = malloc(sizeof(t_data));
	if (!d)
		return (NULL);
	d->next = NULL;
	d->n = (int)n;
	return (d);
}

static int	check_nbr_integrity(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[0] == '-')
		i++;
	while (nbr[i])
	{
		if (nbr[i] < '0' || nbr[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int64_t	check_nbr(char *nbr)
{
	int64_t	n;

	if (ft_strlen(nbr) > 11)
		return (INT64_MAX);
	if (!check_nbr_integrity(nbr))
		return (INT64_MAX);
	n = ft_atoi(nbr);
	if (n > INT32_MAX || n < INT32_MIN)
		return (INT64_MAX);
	return (n);
}

int	parse_split(t_prg *p, char **spl)
{
	t_data	*d;
	int		i;

	i = 0;
	while (spl[i])
		i++;
	while (i > 0)
	{
		d = new_data(check_nbr(spl[i - 1]));
		if (!d)
		{
			ft_splclean(spl);
			return (0);
		}
		stack_push(&p->a, d);
		i--;
	}
	ft_splclean(spl);
	return (1);
}

int	stack_fill(t_prg *p, int ac, char **av)
{
	char	**spl;
	int		i;

	i = ac - 1;
	p->b.size = 0;
	while (i > 0)
	{
		spl = ft_split(av[i], ' ');
		if (!spl)
			return (0);
		if (!parse_split(p, spl))
			return (0);
		i--;
	}
	if (!normalize_stack(&p->a, p->a.size))
		return (0);
	p->size = p->a.size;
	return (1);
}
