/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:11:56 by m-boukel          #+#    #+#             */
/*   Updated: 2023/05/01 11:38:03 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	instraction_c_d(t_lst **stack_a, t_lst **stack_b, t_int sa, t_int sb)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = _max(sa.max, sb.max);
	b = _max(sa.min, sb.min);
	c = sa.max + sb.min;
	d = sa.min + sb.max;
	if (c <= a && c <= b && c <= d)
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
}

void	instraction_a(t_lst **stack_a, t_lst **stack_b, t_int sa, t_int sb)
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

void	instraction_b(t_lst **stack_a, t_lst **stack_b, t_int sa, t_int sb)
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
		instraction_a(stack_a, stack_b, sa, sb);
	else if (b <= a && b <= c && b <= d)
		instraction_b(stack_a, stack_b, sa, sb);
	else
		instraction_c_d(stack_a, stack_b, sa, sb);
	push(stack_a, stack_b, 'a');
}
