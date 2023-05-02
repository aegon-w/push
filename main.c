/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:52:50 by m-boukel          #+#    #+#             */
/*   Updated: 2023/05/02 13:38:05 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(1, "Error\n", 7);
	exit(EXIT_FAILURE);
}

void	sorting_2_3_5(t_lst **stack_a, t_lst **stack_b, int size)
{
	if (size == 2)
		two_nb_algo(stack_a);
	if (size == 3)
		t_nb_algo(stack_a);
	if (size == 5)
		f_nb_algo(stack_a, stack_b);
}

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

void	check_inp(int ac, char **av, t_lst **stack_a)
{
	int		i;
	int		j;
	char	**s;

	s = NULL;
	i = 1;
	while (i < ac)
	{
		if (!av[i])
			error();
		s = ft_split(av[i], ' ');
		if (!*s)
			error();
		j = -1;
		while (s[++j])
			ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(s[j])));
		i++;
		ft_free(s, j);
	}
	check_args(*stack_a);
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	t_lst	*stack_a;
	t_lst	*stack_b;

	i = 1;
	j = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (ac != 1)
	{
		check_inp(ac, av, &stack_a);
		re_index(stack_a);
		if (ft_lstsize(stack_a) == 2 || ft_lstsize(stack_a) == 3
			|| ft_lstsize(stack_a) == 5)
			sorting_2_3_5(&stack_a, &stack_b, ft_lstsize(stack_a));
		else
		{
			sorting_100_500(&stack_a, &stack_b);
			while (stack_b)
				best_move(&stack_a, &stack_b);
		}
		zero_location(&stack_a, &stack_b);
	}
	return (0);
}
