/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:51:12 by mgirardi          #+#    #+#             */
/*   Updated: 2022/12/06 16:56:47 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "lib/libft.h"

void swap(t_list **lst)
{
	t_list *tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = (*lst)->next;
	(*lst)->next = tmp->next;
	tmp->next = (*lst); 
	lst = &tmp;
}

void sa(t_list **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void sb(t_list **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);	
	write(1, "ss\n", 3);
}