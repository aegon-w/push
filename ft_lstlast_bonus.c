/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:05:41 by m-boukel          #+#    #+#             */
/*   Updated: 2023/03/05 20:27:31 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_lstlast(t_lst *lst)
{
	t_lst	*temp;

	if (lst == NULL)
		return (NULL);
	temp = lst;
	while ((temp->next) != NULL)
	{
		temp = temp->next;
	}
	return (temp);
}
