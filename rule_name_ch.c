/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_name_ch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:29:51 by m-boukel          #+#    #+#             */
/*   Updated: 2023/05/01 16:32:20 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ch(t_lst **stack_a, t_lst **stack_b, char c)
{
	if (c == 'a')
		swap_1_2(stack_a);
	else if (c == 'b')
		swap_1_2(stack_b);
	else if (c == '2')
	{
		swap_1_2(stack_a);
		swap_1_2(stack_b);
	}
}

void	push_ch(t_lst **stack_a, t_lst **stack_b, char c)
{
	if (c == 'a')
		push_top(stack_b, stack_a);
	else if (c == 'b')
		push_top(stack_a, stack_b);
}

void	rotate_ch(t_lst **stack_a, t_lst **stack_b, char c)
{
	if (c == 'a')
		shift_up(stack_a);
	else if (c == 'b')
		shift_up(stack_b);
	else if (c == '2')
	{
		shift_up(stack_a);
		shift_up(stack_b);
	}
}

void	rrotate_ch(t_lst **stack_a, t_lst **stack_b, char c)
{
	if (c == 'a')
		shift_down(stack_a);
	else if (c == 'b')
		shift_down(stack_b);
	else if (c == '2')
	{
		shift_down(stack_a);
		shift_down(stack_b);
	}
}
