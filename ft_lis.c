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

t_list	*fill_node(int *v, int *dp, int max_len)
{
	t_list	*result;
	t_list	*new_node;
	int		i;

	i = 0;
	result = NULL;
	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
	{
		while (result)
		{
			new_node = result->next;
			free(result);
			result = new_node;
		}
		free(dp);
		return (NULL);
	}
	new_node->val = v[i];
	new_node->next = result;
	result = new_node;
	max_len--;
	return (result);
}

t_list	*lis(int *v, int len)
{
	int		*dp;
	t_list	*result;
	int		i;
	int		max_len;

	dp = fill_array(len);
	dp = refill_array(v, dp, len);
	max_len = ft_max_len(dp, len);
	i = len - 1;
	while (i >= 0 && max_len > 0)
	{
		if (dp[i] == max_len)
			result = fill_node(v, dp, max_len);
		i--;
	}
	free(dp);
	return (result);
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

void	ft_fill_stack_b(t_list **a, t_list **b, t_list *tmp, int size)
{
	int		i;
	t_list	*tmp_b;

	tmp_b = tmp;
	i = 0;
	while (i < size)
	{
		if (tmp_b->val == (*a)->content && tmp_b->next != NULL)
		{
			ra(a);
			tmp_b = tmp_b->next;
		}
		else if (tmp_b->val == (*a)->content && tmp_b->next == NULL)
			ra(a);
		else if (tmp_b->val != (*a)->content)
			pb(a, b);
		i++;
	}
}

void	ft_sort_lis(t_list **a, t_list **b, int size)
{
	int		*tab_1;
	t_list	*tmp_b;
	t_list	*tmp_c;

	tab_1 = ft_cpstacktoarray(a, size);
	tmp_b = lis(tab_1, size);
	tmp_c = tmp_b;
	ft_fill_stack_b(a, b, tmp_b, size);
	tmp_b = tmp_c;
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
