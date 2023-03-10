/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:46:11 by mgirardi          #+#    #+#             */
/*   Updated: 2023/03/10 11:46:13 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push.h"

void	ft_butta_su(t_list **a, int i)
{
	while (i >= 0)
	{
		ra(a);
		i--;
	}
	return ;
}

void	ft_butta_giu(t_list **a, int i)
{
	while (i >= 0)
	{
		rra(a);
		i--;
	}
	return ;
}

void	ft_push_min_a(t_list **a, t_list **b)
{
	int	j;

	j = ft_is_min_pos(a);
	if (j <= ft_list_size(*a) / 2)
		ft_butta_su(a, (j - 1));
	else
		ft_butta_giu(a, (ft_list_size(*a) - j));
	pb(a, b);
	return ;
}

void	ft_free_stack(t_list *start)
{
	t_list	*i;
	t_list	*next;

	i = start;
	next = NULL;
	while (i)
	{
		next = i->next;
		free(i);
		i = next;
	}
}
