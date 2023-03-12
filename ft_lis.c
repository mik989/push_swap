/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:46:58 by mgirardi          #+#    #+#             */
/*   Updated: 2023/03/10 11:46:59 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push.h"

t_node *fill_chain(int len, int *v)
{
	int	i;
	t_node *n;

	n = calloc(sizeof *n, len + 1);
	i = 0;
	while (i < len)
	{
		n[i].val = v[i];
		i++;
	}
	return (n);
}

t_node	*find_long_chain(int len, t_node *n, t_node *p)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (n[i].len > p->len) 
			p = n + i;
		i++;
	}
	return (p);
}

t_node *lis(int *v, int len)
{
	int i;
	t_node *p;
	t_node *n;
	
	n = fill_chain(len, v);
	i = len; 
	while (i--)
	{
		p = n + i;
		while (p++ < n + len)
		{
			if (p->val > n[i].val && p->len >= n[i].len)
			{
				n[i].next = p;
				n[i].len = p->len + 1;
			}
		}
	}
	i = 0;
	p = n;
	p = find_long_chain(len, n, p);
	return(n);
}

int	*ft_cpstacktoarray(t_list **a, int size)
{
	int		*tab_1;
	t_list	*tmp_a;
	int		i;

	i = 0;
	tmp_a = *a;
	tab_1 = malloc(sizeof(int) * size + 1);
	while (tmp_a != NULL)
	{
		tab_1[i] = tmp_a->content;
		i++;
		tmp_a = tmp_a->next;
	}
	return (tab_1);
}

void	ft_fill_stack_b(t_list **a, t_list **b, t_node *tmp, int size)
{
	int		i;
	t_node	*tmp_b;

	tmp_b = tmp;
	i = 0;
	while (i < size)
	{
		if (tmp->val == (*a)->content && tmp->next != NULL)
		{
			ra(a);
			tmp = tmp->next;
		}
		else if (tmp->val == (*a)->content && tmp->next == NULL)
			ra(a);
		else if (tmp->val != (*a)->content)
			pb(a, b);
		i++;
	}
	tmp = tmp_b;
}

void	ft_sort_lis(t_list **a, t_list **b, int size)
{
	int		*tab_1;
	t_node	*tmp_b;

	tab_1 = ft_cpstacktoarray(a, size);
	tmp_b = lis(tab_1, size);
	ft_fill_stack_b(a, b, tmp_b, size);
	free(tmp_b);
	free(tab_1);
	size = ft_list_size(*b);
	while (size > 0)
	{
		ft_movement(a, b, size);
		size--;
	}
	ft_ultimate_movement(a);
}
