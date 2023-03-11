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

void	ft_push_min_5(t_list **a, t_list **b)
{
	int	j;

	j = ft_is_min_pos(a);
	if (j <= ft_list_size(*a) / 2)
		ft_butta_su(a, (j - 1));
	else
		ft_butta_giu(a, j);
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

int	is_min(t_list *a)
{
	int		min;
	t_list	*node;
	t_list	*temp;

	node = a;
	temp = node->next;
	while (temp)
	{
		while ((temp) && (node->content < temp->content))
			temp = temp->next;
		if (temp != NULL)
		{
			node = temp;
			temp = temp->next;
		}
	}
	min = node->content;
	return (min);
}


int	find_min_pos(t_list *a)
{
	int		i;
	t_list	*last;

	last = ft_lstlast(a);
	i = 0;
	if (last == NULL)
		return (0);
	if (last->content == is_min(a))
		return (ft_list_size(a));
	while ((a->content != is_min(a)) && (a != NULL))
	{
		a = a->next;
		i++;
	}
	i++;
	return (i);
}

void	push_min(t_list **a, t_list **b)
{
	int	pos_min;
	int	list_size;
	int	i;

	i = 1;
	pos_min = find_min_pos(*a);
	list_size = ft_list_size(*a);
	if ((float)pos_min <= (float)(list_size / 2 + 1))
	{
		while (i != pos_min)
		{
			ra(a);
			i++;
		}
	}
	else if ((float)pos_min > (float)(list_size / 2))
	{
		while ((float)pos_min <= (float)(list_size))
		{
			rra(a);
			pos_min++;
		}
	}
	pb(a, b);
}