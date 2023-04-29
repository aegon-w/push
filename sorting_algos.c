/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 07:06:51 by m-boukel          #+#    #+#             */
/*   Updated: 2023/04/27 11:24:07 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_nb_algo(t_lst **stack_a)
{
	t_lst	*tmp;

	tmp = *stack_a;
	if (!tmp || !tmp->next)
		return ;
	if (tmp->data == 0 && tmp->next->data == 1)
		exit(0);
	else
		swap(stack_a, stack_a, 'a');
}

void	t_nb_algo(t_lst **stack_a)
{
	t_lst	*tmp;

	tmp = *stack_a;
	if (!stack_a || !tmp)
		return ;
	if (tmp->data == 0 && tmp->next->data == 1 && tmp->next->next->data == 2)
		exit(0);
	while (tmp && tmp->next)
	{
		if (tmp->data == 0 && tmp->next->data == 2)
			swap(stack_a, stack_a, 'a');
		else if (tmp->data == 1 && tmp->next->data == 0)
			swap(stack_a, stack_a, 'a');
		else if (tmp->data == 2 && tmp->next->data == 1)
			swap(stack_a, stack_a, 'a');
		tmp = tmp->next;
	}
}

void	help_f_algo(t_lst **stack_a)
{
	t_lst	*tmp;

	tmp = *stack_a;
	if (!stack_a || !tmp)
		return ;
	while (tmp && tmp->next)
	{
		if (tmp->data == 4 && tmp->next->data == 3)
			swap(stack_a, stack_a, 'a');
		else if (tmp->data == 3 && tmp->next->data == 2)
			swap(stack_a, stack_a, 'a');
		else if (tmp->data == 2 && tmp->next->data == 4)
			swap(stack_a, stack_a, 'a');
		tmp = tmp->next;
	}
}

void	two_location(t_lst **stack_a)
{
	int		i;
	int		pos;
	int		size_a;
	t_lst	*tmp;

	i = 0;
	size_a = ft_lstsize(*stack_a);
	tmp = *stack_a;
	while (i < size_a)
	{
		if (tmp->data == 2)
			pos = i;
		tmp = tmp->next;
		i++;
	}
	if (pos <= size_a / 2)
		while (pos--)
			rotate(stack_a, stack_a, 'a');
	else
		while (pos++ < size_a)
			rrotate(stack_a, stack_a, 'a');
}

void	f_nb_algo(t_lst **stack_a, t_lst **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	while (size-- > 0)
	{
		if ((*stack_a)->data < 2)
			push(stack_a, stack_b, 'b');
		else
			rotate(stack_a, stack_b, 'a');
	}
	help_f_algo(stack_a);
	two_location(stack_a);
	if ((*stack_b)->data > (*stack_b)->next->data)
	{
		push(stack_a, stack_b, 'a');
		push(stack_a, stack_b, 'a');
	}
	else
	{
		swap(stack_a, stack_b, 'b');
		push(stack_a, stack_b, 'a');
		push(stack_a, stack_b, 'a');
	}
}
