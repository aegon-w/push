/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:02:05 by m-boukel          #+#    #+#             */
/*   Updated: 2023/05/02 13:36:33 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct ints
{
	t_int	sa;
	t_int	sb;
}			t_ints;

int	comb_b(t_updo *t, int min_instraction)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = _max(t->down1, t->down);
	b = _max(t->up1, t->up);
	c = t->down1 + t->up;
	d = t->up1 + t->down;
	if (a <= b && a <= c && a <= d)
		return (a);
	if (b <= a && b <= c && b <= d)
		return (b);
	if (c <= a && c <= b && c <= d)
		return (c);
	if (d <= a && d <= b && d <= c)
		return (d);
	return (min_instraction);
}

t_pos	*get_pos(t_lst **stack_a)
{
	t_pos	*p;

	p = malloc(sizeof(t_pos));
	p->up_pos = (*stack_a)->data;
	p->upper = 0;
	p->up = 0;
	p->val = INT_MAX;
	return (p);
}

int	min_pos_location(t_lst **stack_a, int target)
{
	t_pos	*p;
	t_lst	*tmp;
	int		ret;

	p = get_pos(stack_a);
	tmp = *stack_a;
	while (tmp)
	{
		if (target < tmp->data && tmp->data < p->val)
		{
			p->val = tmp->data;
			p->up1 = p->up;
		}
		if (p->up_pos > tmp->data)
		{
			p->up_pos = tmp->data;
			p->upper = p->up;
		}
		tmp = tmp->next;
		p->up++;
	}
	ret = p->up1;
	if (p->val == INT_MAX)
		ret = p->upper;
	return (free(p), ret);
}

t_ints	find_best_move(t_lst **stack_a, t_lst **stack_b, t_updo *t, int size_b)
{
	int		min_instraction;
	t_lst	*tmp;
	t_ints	s;

	min_instraction = INT_MAX;
	tmp = *stack_b;
	while (t->up < size_b)
	{
		t->up1 = min_pos_location(stack_a, tmp->data);
		t->down1 = ft_lstsize(*stack_a) - t->up1;
		if (comb_b(t, min_instraction) < min_instraction)
		{
			min_instraction = comb_b(t, min_instraction);
			s.sa.min = t->up1;
			s.sa.max = t->down1;
			s.sb.min = t->up;
			s.sb.max = t->down;
		}
		tmp = tmp->next;
		t->up++;
		t->down--;
	}
	return (s);
}

void	best_move(t_lst **stack_a, t_lst **stack_b)
{
	int		size_b;
	t_updo	*t;
	t_ints	s;

	size_b = ft_lstsize(*stack_b);
	t = malloc(sizeof(t_updo));
	t->up = 0;
	t->down = size_b;
	s = find_best_move(stack_a, stack_b, t, size_b);
	free(t);
	instraction(stack_a, stack_b, s.sa, s.sb);
}
