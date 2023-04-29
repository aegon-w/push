/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:02:05 by m-boukel          #+#    #+#             */
/*   Updated: 2023/04/29 13:55:40 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args(t_lst *lst)
{
	t_lst	*cur;
	t_lst	*tmp;

	cur = lst;
	while (cur != NULL)
	{
		tmp = cur->next;
		while (tmp != NULL)
		{
			if (cur->data == tmp->data)
			{
				write(1, "error\n", 19);
				exit(1);
			}
			tmp = tmp->next;
		}
		cur = cur->next;
	}
}

int	comb_b(int min_a, int max_a, int min_b, int max_b, int min_instraction)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = _max(max_a, max_b);
	b = _max(min_a, min_b);
	c = max_a + min_b;
	d = min_a + max_b;
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

void	instraction(t_lst **stack_a, t_lst **stack_b, t_int sa, t_int sb)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = _max(sa.max, sb.max);
	b = _max(sa.min, sb.min);
	c = sa.max + sb.min;
	d = sa.min + sb.max;
	if (a <= b && a <= c && a <= d)
	{
		while (sa.max && sb.max)
		{
			rrotate(stack_a, stack_b, '2');
			sa.max--;
			sb.max--;
		}
		while (sa.max-- > 0)
			rrotate(stack_a, stack_b, 'a');
		while (sb.max-- > 0)
			rrotate(stack_b, stack_b, 'b');
	}
	else if (b <= a && b <= c && b <= d)
	{
		while (sa.min && sb.min)
		{
			rotate(stack_a, stack_b, '2');
			sa.min--;
			sb.min--;
		}
		while (sa.min-- > 0)
			rotate(stack_a, stack_b, 'a');
		while (sb.min-- > 0)
			rotate(stack_b, stack_b, 'b');
	}
	else if (c <= a && c <= b && c <= d)
	{
		while (sa.max-- > 0)
			rrotate(stack_a, stack_b, 'a');
		while (sb.min-- > 0)
			rotate(stack_b, stack_b, 'b');
	}
	else
	{
		while (sa.min-- > 0)
			rotate(stack_a, stack_b, 'a');
		while (sb.max-- > 0)
			rrotate(stack_b, stack_b, 'b');
	}
	push(stack_a, stack_b, 'a');
}

int	min_pos_location(t_lst **stack_a, int target)
{
	int		min;
	int		min1;
	int		val;
	int		min_pos;
	int		_min;
	t_lst	*tmp;

	min_pos = (*stack_a)->data;
	_min = 0;
	tmp = *stack_a;
	min = 0;
	val = INT_MAX;
	while (tmp)
	{
		if (target < tmp->data && tmp->data < val)
		{
			val = tmp->data;
			min1 = min;
		}
		if (min_pos > tmp->data)
		{
			min_pos = tmp->data;
			_min = min;
		}
		tmp = tmp->next;
		min++;
	}
	if (val == INT_MAX)
		return (_min);
	return (min1);
}

void	best_move(t_lst **stack_a, t_lst **stack_b)
{
	int size_b;
	int min;
	int max;
	int min1;
	int max1;
	int min_instraction;
	t_lst *tmp;

	size_b = ft_lstsize(*stack_b);
	min = 0;
	max = size_b;
	tmp = *stack_b;
	t_int sa, sb;
	min_instraction = INT_MAX;
	while (min < size_b)
	{
		min1 = min_pos_location(stack_a, tmp->data);
		max1 = ft_lstsize(*stack_a) - min1;
		// printf("%d     %d\n", min1, max1);
		if (comb_b(min, max, min1, max1, min_instraction) < min_instraction)
		{
			min_instraction = comb_b(min, max, min1, max1, min_instraction);
			sa.min = min1;
			sa.max = max1;
			sb.min = min;
			sb.max = max;
		}
		tmp = tmp->next;
		min++;
		max--;
	}
	instraction(stack_a, stack_b, sa, sb);
	// do instarction to detect best move
}