/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 07:06:02 by m-boukel          #+#    #+#             */
/*   Updated: 2023/04/27 11:21:06 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_lst **stack_a, t_lst **stack_b, char c)
{
	if (c == 'a')
	{
		swap_1_2(stack_a);
		write(1, "sa\n", 3);
	}
	else if (c == 'b')
	{
		swap_1_2(stack_b);
		write(1, "sb\n", 3);
	}
	else if (c == '2')
	{
		swap_1_2(stack_a);
		swap_1_2(stack_b);
		write(1, "ss\n", 3);
	}
}

void	push(t_lst **stack_a, t_lst **stack_b, char c)
{
	if (c == 'a')
	{
		push_top(stack_b, stack_a);
		write(1, "pa\n", 3);
	}
	else if (c == 'b')
	{
		push_top(stack_a, stack_b);
		write(1, "pb\n", 3);
	}
}

void	rotate(t_lst **stack_a, t_lst **stack_b, char c)
{
	if (c == 'a')
	{
		shift_up(stack_a);
		write(1, "ra\n", 3);
	}
	else if (c == 'b')
	{
		shift_up(stack_b);
		write(1, "rb\n", 3);
	}
	else if (c == '2')
	{
		shift_up(stack_a);
		shift_up(stack_b);
		write(1, "rr\n", 3);
	}
}

void	rrotate(t_lst **stack_a, t_lst **stack_b, char c)
{
	if (c == 'a')
	{
		shift_down(stack_a);
		write(1, "rra\n", 4);
	}
	else if (c == 'b')
	{
		shift_down(stack_b);
		write(1, "rrb\n", 4);
	}
	else if (c == '2')
	{
		shift_down(stack_a);
		shift_down(stack_b);
		write(1, "rrr\n", 4);
	}
}
