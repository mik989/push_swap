/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:47:06 by mgirardi          #+#    #+#             */
/*   Updated: 2023/03/10 11:47:07 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push.h"

int	min_pos(t_list *tmp, int i)
{
	int	j;

	j = 0;
	while (tmp != NULL)
	{
		if (i == tmp->content)
			break ;
		j++;
		tmp = tmp->next;
	}
	return (j);
}

int	ft_is_min_pos(t_list **a)
{
	t_list	*tmp;
	int		result;
	int		i;

	if (!a)
		return (0);
	tmp = *a;
	i = 0;
	result = tmp->content;
	while (tmp->next != NULL)
	{
		if (result > tmp->next->content)
			result = tmp->next->content;
		tmp = tmp->next;
	}
	i = min_pos(*a, result);
	tmp = *a;
	return (i);
}

int	ft_is_max_pos(t_list **a)
{
	t_list	*tmp;
	int		result;
	int		i;

	if (!a)
		return (0);
	tmp = *a;
	i = 0;
	result = tmp->content;
	while (tmp->next != NULL)
	{
		if (result < tmp->next->content)
			result = tmp->next->content;
		tmp = tmp->next;
	}
	i = min_pos(*a, result);
	tmp = *a;
	return (i);
}
