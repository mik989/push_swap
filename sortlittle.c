/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortlittle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:44:52 by mgirardi          #+#    #+#             */
/*   Updated: 2023/03/10 11:44:53 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push.h"

int	ft_list_size(t_list *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		++size;
		lst = lst->next;
	}
	return (size);
}

void	ft_sort_2(t_list **a)
{
	t_list	*beholder;
	t_list	*beholder2;

	beholder = *a;
	beholder2 = beholder->next;
	if (beholder->content > beholder2->content)
		sa(a);
}

void	first_sort(int temp_1, int temp_2, int temp_3, t_list **a)
{
	if (temp_2 < temp_3)
		return ;
	else if (temp_3 < temp_1)
		rra(a);
	else
	{
		rra(a);
		sa(a);
	}
}

void	ft_sort_3(t_list **a)
{
	int	temp_1;
	int	temp_2;
	int	temp_3;

	temp_1 = (*a)->content;
	temp_2 = (*a)->next->content;
	temp_3 = (*a)->next->next->content;
	if (temp_1 < temp_2)
		first_sort(temp_1, temp_2, temp_3, a);
	else if (temp_2 < temp_3)
	{
		if (temp_3 < temp_1)
			ra(a);
		else
			sa(a);
	}
	else
	{
		sa(a);
		rra(a);
	}
}

void	ft_sort(t_list **a, t_list **b, int size)
{
	int	i;

	if (size == 2)
		ft_sort_2(a);
	if (size == 3)
		ft_sort_3(a);
	if (size == 4)
	{
		push_min(a, b);
		ft_sort_3(a);
		pa(a, b);
	}
	if (size == 5)
	{
		i = 2;
		while (i--)
			push_min(a, b);
		ft_sort_3(a);
		pa(a, b);
		pa(a, b);
	}
	return ;
}
