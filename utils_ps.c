/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:17:35 by m-boukel          #+#    #+#             */
/*   Updated: 2023/05/01 18:37:47 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	check_args(t_lst *lst)
{
	t_lst	*cur;
	t_lst	*tmp;

	cur = lst;
	while (cur != NULL)
	{
		tmp = cur->next;
		while (tmp != NULL)
		{
			if (cur->data == tmp->data)
			{
				write(1, "Error\n", 7);
				exit(1);
			}
			tmp = tmp->next;
		}
		cur = cur->next;
	}
}

void	check_cara(char *s, int j)
{
	while (s[j])
	{
		if (!(s[j] >= '0' && s[j] <= '9'))
		{
			write(1, "Error\n", 7);
			exit(1);
		}
		j++;
	}
}

int	ft_atoi(char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] && str[i] <= 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	check_cara(str, i);
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - 48;
	if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
	{
		write(2, "Error\n", 7);
		exit(1);
	}
	return (result * sign);
}
