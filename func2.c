/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:17:35 by m-boukel          #+#    #+#             */
/*   Updated: 2023/04/28 13:57:53 by m-boukel         ###   ########.fr       */
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

void	check_int(long nb)
{
	if (nb > INT_MAX || nb < INT_MIN)
	{
		write(1, "Error\n", 7);
		exit(1);
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

int	ft_atoi(char *s)
{
	int		i;
	int		j;
	long	res;
	int		sign;

	i = 0;
	j = 0;
	res = 0;
	sign = 1;
	while (s[i] && s[i] <= 32)
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
		j++;
	}
	check_cara(s, j);
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	check_int(res * sign);
	return (res * sign);
}
