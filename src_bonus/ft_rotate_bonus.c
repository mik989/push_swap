/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:44:26 by mgirardi          #+#    #+#             */
/*   Updated: 2023/03/10 11:44:29 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_bonus.h"

void	ft_rotlst(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	*lst = ft_lstlast(*lst);
	(*lst)->next = tmp;
	*lst = tmp->next;
	tmp->next = NULL;
}

void	ra(t_list **a)
{
	ft_rotlst(a);
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	ft_rotlst(b);
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	ft_rotlst(a);
	ft_rotlst(b);
	write(1, "rr\n", 3);
}
