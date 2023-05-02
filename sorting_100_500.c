/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_100_500.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:27:40 by m-boukel          #+#    #+#             */
/*   Updated: 2023/05/01 19:15:57 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_100_500(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*tmp;
	int		*arr;
	int		*new;
	int		size_a;

	tmp = *stack_a;
	if (is_stack_sorted(stack_a) == 0)
		exit(1);
	arr = stack_to_arr(*stack_a);
	new = lis(arr, ft_lstsize(*stack_a));
	size_a = ft_lstsize(*stack_a);
	while (size_a--)
	{
		if (new[(*stack_a)->data] == 0)
			push(stack_a, stack_b, 'b');
		else
			rotate(stack_a, stack_b, 'a');
	}
	free(arr);
	free(new);
}
