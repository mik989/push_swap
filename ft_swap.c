/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:51:12 by mgirardi          #+#    #+#             */
/*   Updated: 2022/12/06 16:56:47 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_swap_a(t_list **a)
{
	t_list *tmp;

	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = (*a);
	a = &tmp;

}