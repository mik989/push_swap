/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:46:48 by mgirardi          #+#    #+#             */
/*   Updated: 2023/03/10 11:46:50 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

void	ft_revlst(t_list **lst)
{
	t_list	*tmp;
	int		i;

	if (!*lst || !(*lst)->next)
		return ;
	i = 0;
	tmp = *lst;
	while ((*lst)->next)
	{
		*lst = (*lst)->next;
		i++;
	}
	(*lst)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
}

void	rra(t_list **a)
{
	ft_revlst(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	ft_revlst(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	ft_revlst(a);
	ft_revlst(b);
	write(1, "rrr\n", 4);
}
