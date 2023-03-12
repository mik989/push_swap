/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:43:42 by mgirardi          #+#    #+#             */
/*   Updated: 2023/03/10 11:43:45 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

void	ft_init_flag(t_list *op)
{
	op->flag = 1;
	op->i = 1;
	op->c = 0;
	return ;
}

void	nextgreaterelement(t_list **a, t_list *op, int n)
{
	t_list	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->content > n && op->flag)
		{
			op->c = op->i;
			op->prev = tmp_a->content;
			op->flag = 0;
		}
		else if (tmp_a->content > n && !op->flag)
		{
			if (tmp_a->content < op->prev)
			{
				op->c = op->i;
				op->prev = tmp_a->content;
			}
		}
		tmp_a = tmp_a->next;
		op->i++;
	}
}

void	ft_printlist(t_list *o)
{
	t_list	*p;

	p = o;
	while (p != NULL)
	{
		printf(" %d", p->content);
		p = p->next;
		if (!p)
			break ;
	}
}

void	free_list(t_list *head)
{
	t_list	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

int	ft_is_ordered(t_list *a)
{
	while (a != NULL && a->next != NULL)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}
