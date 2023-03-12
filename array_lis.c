/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_lis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:45:01 by mgirardi          #+#    #+#             */
/*   Updated: 2023/03/10 11:45:03 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push.h"

t_list	*lis_old(int *v, int len)
{
	t_list	*start;
	t_list	*tmp;
	t_list	*next;
	int		i;

	start = NULL;
	tmp = NULL;
	next = NULL;
	i = 0;
	while (len--)
	{
		next = (t_list *)malloc(sizeof(t_list));
		next->val = v[i++];
		next->next = NULL;
		if (start == NULL)
			start = next;
		if (tmp != NULL)
			tmp->next = next;
		tmp = next;
	}
	return (start);
}

t_node	*fill_chain(int len, int *v)
{
	int		i;
	t_node	*n;

	n = calloc(sizeof(*n), len + 1);
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
