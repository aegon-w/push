/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:03:00 by m-boukel          #+#    #+#             */
/*   Updated: 2023/05/01 18:24:29 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

void	error(void)
{
	write(1, "Error\n", 7);
	exit(1);
}

void	imp(t_lst **stack_a, t_lst **stack_b, char *s)
{
	if (!ft_strcmp(s, "sa\n"))
		swap_ch(stack_a, stack_b, 'a');
	else if (!ft_strcmp(s, "sb\n"))
		swap_ch(stack_a, stack_b, 'b');
	else if (!ft_strcmp(s, "ss\n"))
		swap_ch(stack_a, stack_b, '2');
	else if (!ft_strcmp(s, "pa\n"))
		push_ch(stack_a, stack_b, 'a');
	else if (!ft_strcmp(s, "pb\n"))
		push_ch(stack_a, stack_b, 'b');
	else if (!ft_strcmp(s, "ra\n"))
		rotate_ch(stack_a, stack_b, 'a');
	else if (!ft_strcmp(s, "rb\n"))
		rotate_ch(stack_a, stack_b, 'b');
	else if (!ft_strcmp(s, "rr\n"))
		rotate_ch(stack_a, stack_b, '2');
	else if (!ft_strcmp(s, "rra\n"))
		rrotate_ch(stack_a, stack_b, 'a');
	else if (!ft_strcmp(s, "rrb\n"))
		rrotate_ch(stack_a, stack_b, 'b');
	else if (!ft_strcmp(s, "rrr\n"))
		rrotate_ch(stack_a, stack_b, '2');
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
		free(line);
		line = get_next_line(0);
	}
	if (!is_stack_sorted(stack_a) && !ft_lstsize(*stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
		s = ft_split(av[i], ' ');
		if (s == NULL)
			exit(1);
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
		check(&stack_a, &stack_b);
	}
	return (0);
}
