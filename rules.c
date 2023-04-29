/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 07:06:36 by m-boukel          #+#    #+#             */
/*   Updated: 2023/04/12 07:06:37 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_1_2(t_lst **lst)
{
	t_lst	*first;
	t_lst	*second;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	first = *lst;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
}

void	push_top(t_lst **from, t_lst **to)
{
	t_lst	*tmp;

	if (*from)
	{
		tmp = (*from)->next;
		ft_lstadd_front(to, *from);
		*from = tmp;
	}
}

void	shift_up(t_lst **lst)
{
	t_lst	*tmp;

	tmp = *lst;
	if (!tmp || !lst)
		return ;
	if (!(*lst)->next)
		return ;
	// if (!(*lst)->next->next)
	// 	return ;
	ft_lstadd_back(lst, tmp);
	*lst = tmp->next;
	tmp->next = NULL;
}

void	shift_down(t_lst **lst)
{
	t_lst	*tmp;
	t_lst	*last;

	tmp = *lst;
	if (!tmp || !lst)
		return ;
	if (!(*lst)->next)
		return ;
	// if (!(*lst)->next->next)
	// 	return ;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(lst, last);
}
