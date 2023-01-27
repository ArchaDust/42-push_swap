/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:58:46 by aberneli          #+#    #+#             */
/*   Updated: 2021/12/18 12:17:23 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	replace_by_index(t_data *d, int *arr, int size)
{
	int	i;

	while (d)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == d->n)
			{
				d->n = i;
				break ;
			}
			i++;
		}
		d = d->next;
	}
}

static void	sort_int_ex(int *tab, int size, int *status)
{
	int	i;
	int	high;

	if (!tab || size < 1)
		return ;
	high = size - 1;
	while (high > 0)
	{
		i = 0;
		while (i < high)
		{
			if (tab[i] == tab[i + 1])
				*status = 0;
			if (tab[i] > tab[i + 1])
				ft_swap(&tab[i], &tab[i + 1]);
			i++;
		}
		high--;
	}
}

void	sort_int(int *tab, int size)
{
	int	i;
	int	high;

	if (!tab || size < 1)
		return ;
	high = size - 1;
	while (high > 0)
	{
		i = 0;
		while (i < high)
		{
			if (tab[i] > tab[i + 1])
				ft_swap(&tab[i], &tab[i + 1]);
			i++;
		}
		high--;
	}
}

int	normalize_stack(t_stack *s, int len)
{
	int		*arr;
	t_data	*tmp;
	int		i;
	int		status;

	arr = malloc(len * sizeof(int));
	if (!arr)
		return (0);
	tmp = s->top;
	i = 0;
	status = 1;
	while (tmp)
	{
		arr[i] = tmp->n;
		tmp = tmp->next;
		i++;
	}
	sort_int_ex(arr, len, &status);
	replace_by_index(s->top, arr, len);
	free(arr);
	return (status);
}
