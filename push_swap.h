/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:33:52 by aberneli          #+#    #+#             */
/*   Updated: 2021/12/22 17:21:07 by aberneli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_data
{
	struct s_data	*next;
	int				n;
}					t_data;

typedef struct s_stack
{
	t_data		*top;
	int			size;
	int			log;
}				t_stack;

typedef struct s_prg
{
	t_stack		a;
	t_stack		b;
	int			size;
	int			sorted;
}				t_prg;

// stack.c
void	stack_destroy(t_stack *s);
t_data	*stack_pop(t_stack *s);
void	stack_push(t_stack *s, t_data *d);

// data.c
int		stack_fill(t_prg *p, int ac, char **av);

// swap.c
int		swap(t_stack *s);
int		sa(t_stack *a);
int		sb(t_stack *b);
int		ss(t_stack *a, t_stack *b);

// push.c
int		push(t_stack *s1, t_stack *s2);
int		pa(t_stack *a, t_stack *b);
int		pb(t_stack *a, t_stack *b);

// rotate.c
int		rotate(t_stack *s);
int		ra(t_stack *a);
int		rb(t_stack *b);
int		rr(t_stack *a, t_stack *b);

// rrotate.c
int		rrotate(t_stack *s);
int		rra(t_stack *a);
int		rrb(t_stack *b);
int		rrr(t_stack *a, t_stack *b);

// normalize_data.c
void	sort_int(int *tab, int size);
int		normalize_stack(t_stack *s, int len);

// super_*.c
void	rotate_x(t_stack *s, int x, int (*rot)(t_stack *));
int		find_index(t_data *d, int index);
int		find_x(t_data *d, int x);
int		super_small(t_prg *p);
void	super_fetchx(t_prg *p, int x);
int		super_fetchrange(t_prg *p, int low, int high);
int		super_sortb(t_prg *p, int low, int high);

// ft_strlen.c
size_t	ft_strlen(const char *s);

// ft_atoi.c
int64_t	ft_atoi(const char *str);

// split relqted
char	**ft_split(char const *str, char c);
void	ft_splclean(char **spl);

#endif
