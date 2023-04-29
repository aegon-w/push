/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 07:05:30 by m-boukel          #+#    #+#             */
/*   Updated: 2023/04/12 07:05:32 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	*stack_to_arr(t_lst *lst)
{
	int	*arr;
	int	i;

	i = 0;
	arr = malloc(ft_lstsize(lst) * sizeof(int));
	while (lst)
	{
		arr[i] = lst->data;
		lst = lst->next;
		i++;
	}
	return (arr);
}

void	sort_int_tab(int *tab, int size)
{
	int	swap;
	int	count;

	count = 0;
	while (count < (size - 1))
	{
		if (tab[count] > tab[count + 1])
		{
			swap = tab[count];
			tab[count] = tab[count + 1];
			tab[count + 1] = swap;
			count = 0;
		}
		else
			count++;
	}
}

int	index_of(int *arr, int target, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1) && arr[i] != target)
		i++;
	return (i);
}

void	re_index(t_lst *stack)
{
	int		*stack_as_arr;
	t_lst	*i;

	stack_as_arr = stack_to_arr(stack);
	sort_int_tab(stack_as_arr, ft_lstsize(stack));
	i = stack;
	while (i)
	{
		i->index = index_of(stack_as_arr, i->data, ft_lstsize(stack));
		i = i->next;
	}
	free(stack_as_arr);
	i = stack;
	while (i)
	{
		i->data = i->index;
		i = i->next;
	}
}
