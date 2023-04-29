/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:03:00 by m-boukel          #+#    #+#             */
/*   Updated: 2023/04/27 09:22:53 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

void	error(void)
{
	write(1, "Error\n", 7);
	exit(1);
}

void	is_sorted(t_lst **stack_a)
{
	t_lst	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->data > tmp->next->data)
			error();
		tmp = tmp->next;
	}
}

void	imp(t_lst **stack_a, t_lst **stack_b, char *s)
{
	if (!ft_strcmp(s, "sa\n"))
		swap(stack_a, stack_b, 'a');
	else if (!ft_strcmp(s, "sb\n"))
		swap(stack_a, stack_b, 'b');
	else if (!ft_strcmp(s, "ss\n"))
		swap(stack_a, stack_b, '2');
	else if (!ft_strcmp(s, "pa\n"))
		push(stack_a, stack_b, 'a');
	else if (!ft_strcmp(s, "pb\n"))
		push(stack_a, stack_b, 'b');
	else if (!ft_strcmp(s, "ra\n"))
		rotate(stack_a, stack_b, 'a');
	else if (!ft_strcmp(s, "rb\n"))
		rotate(stack_a, stack_b, 'b');
	else if (!ft_strcmp(s, "rr\n"))
		rotate(stack_a, stack_b, '2');
	else if (!ft_strcmp(s, "rra\n"))
		rrotate(stack_a, stack_b, 'a');
	else if (!ft_strcmp(s, "rrb\n"))
		rrotate(stack_a, stack_b, 'b');
	else if (!ft_strcmp(s, "rrr\n"))
		rrotate(stack_a, stack_b, '2');
	else
		error();
}

void	check(t_lst **stack_a, t_lst **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		imp(stack_a, stack_b, line);
		line = get_next_line(0);
	}
	if (is_sorted(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
			ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(s[j])));
			j++;
		}
		i++;
	}
	check_args(stack_a);
	re_index(stack_a);
	check(&stack_a, &stack_b);
	while (stack_a)
		printf("%d ", stack_a->data), stack_a = stack_a->next;
	// system("leaks push_swap");
	return (0);
}