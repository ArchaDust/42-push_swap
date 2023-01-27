/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 08:19:30 by aberneli          #+#    #+#             */
/*   Updated: 2021/12/18 10:58:48 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_wspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r')
		return (1);
	return (0);
}

int64_t	ft_atoi(const char *str)
{
	int64_t	result;
	int		i;
	int		negative;

	if (!str)
		return (0);
	i = 0;
	while (ft_is_wspace(str[i]))
		i++;
	negative = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	result = 0;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * negative);
}
