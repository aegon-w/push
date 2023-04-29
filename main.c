/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:52:50 by m-boukel          #+#    #+#             */
/*   Updated: 2023/04/29 14:08:40 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	zero_location(t_lst **stack_a, t_lst **stack_b)
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
		if (tmp->data == 0)
			pos = i;
		tmp = tmp->next;
		i++;
	}
	if (pos <= size_a / 2)
		while (pos--)
			rotate(stack_a, stack_b, 'a');
	else
		while (pos++ < size_a)
			rrotate(stack_a, stack_b, 'a');
}

int	main(int ac, char **av)
{
	int i;
	int j;
	t_lst *stack_a;
	t_lst *stack_b;
	t_lst *tmp;
	char **s;
	int *arr;
	int *new;
	int size_a;

	i = 1;
	j = 0;
	stack_a = NULL;
	stack_b = NULL;
	tmp = NULL;
	while (i < ac)
	{
		j = 0;
		s = ft_split(av[i], ' ');
		while (s[j])
		{
			//printf("[%d]\n", ft_atoi(s[j]));
			ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(s[j])));
			//check_int(ft_atoi(s[j]));
			j++;
		}
		// check_int(ft_atoi(av[i]));
		i++;
	}
	check_args(stack_a);
	re_index(stack_a);
	if (ft_lstsize(stack_a) == 2)
		two_nb_algo(&stack_a);
	else if (ft_lstsize(stack_a) == 3)
		t_nb_algo(&stack_a);
	else if (ft_lstsize(stack_a) == 5)
		f_nb_algo(&stack_a, &stack_b);
	else
	{
		arr = stack_to_arr(stack_a);
		new = lis(arr, ft_lstsize(stack_a));
		size_a = ft_lstsize(stack_a);
		while (size_a--)
		{
			if (new[stack_a->data] == 0)
				push(&stack_a, &stack_b, 'b');
			else
				rotate(&stack_a, &stack_b, 'a');
		}
		while (stack_b)
			best_move(&stack_a, &stack_b);
	}
	zero_location(&stack_a, &stack_b);
	while (stack_a)
		printf("%d ", stack_a->data), stack_a = stack_a->next;
	// system("leaks push_swap");
	return (0);
}