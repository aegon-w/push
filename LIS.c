/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:17:29 by m-boukel          #+#    #+#             */
/*   Updated: 2023/04/29 13:12:45 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct lis
{
	int	max;
	int	im;
}		t_lis;

void	allocation(int ***tab, int size)
{
	int	i;

	i = 0;
	*tab = malloc(sizeof(int *) * 4);
	while (i < 4)
	{
		(*tab)[i] = malloc(sizeof(int) * size);
		i++;
	}
}

int	*fill_arr(int *arr, int i, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		arr[j] = i;
		j++;
	}
	return (arr);
}

void	largest_inc_sub(int *arr, int *lent, int *sub, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (arr[j] < arr[i] && lent[j] + 1 > lent[i])
			{
				lent[i] = lent[j] + 1;
				sub[i] = j;
			}
			j++;
		}
		i++;
	}
}

int	*lis(int *arr, int size)
{
	int		**tab;
	t_lis	*t;
	int		k;

	k = -1;
	allocation(&tab, size);
	fill_arr(tab[1], 1, size);
	largest_inc_sub(arr, tab[1], tab[3], size);
	t = malloc(sizeof(t_lis));
	t->max = 1;
	while (++k < size)
	{
		if (tab[1][k] >= t->max)
		{
			t->max = tab[1][k];
			t->im = k;
		}
	}
	fill_arr(tab[2], 0, size);
	while (--t->max >= 0)
	{
		tab[2][arr[t->im]] = 1;
		t->im = tab[3][t->im];
	}
	// for (int j = 0; j < size; j++)
	// 	printf("%d\n", tab[2][j]);
	// exit(1);
	free(t);
	free(tab[0]);
	free(tab[1]);
	free(tab[3]);
	return (tab[2]);
}
