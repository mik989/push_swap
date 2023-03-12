/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:46:33 by mgirardi          #+#    #+#             */
/*   Updated: 2023/03/10 11:46:34 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

int	ft_index(int size, int *mov_a, int *mov_b)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	k = ft_best_mov(size, mov_a, mov_b);
	while (k != ft_best_mov2(mov_a[i], mov_b[i]))
		i++;
	return (i);
}

void	ft_move_min(int mov_a, int mov_b, t_list **a, t_list **b)
{
	mov_a *= -1;
	mov_b *= -1;
	while (mov_a != 0 && mov_b != 0)
	{
		rrr(a, b);
		mov_a--;
		mov_b--;
	}
	while (mov_a != 0 || mov_b != 0)
	{
		if (mov_b != 0)
		{
			rrb(b);
			mov_b--;
		}
		if (mov_a != 0)
		{
			rra(a);
			mov_a--;
		}
	}
	pa(a, b);
	return ;
}

void	ft_move_max(int mov_a, int mov_b, t_list **a, t_list **b)
{
	while (mov_a != 0 && mov_b != 0)
	{
		rr(a, b);
		mov_a--;
		mov_b--;
	}
	while (mov_a != 0 || mov_b != 0)
	{
		if (mov_b != 0)
		{
			rb(b);
			mov_b--;
		}
		if (mov_a != 0)
		{
			ra(a);
			mov_a--;
		}
	}
	pa(a, b);
	return ;
}

void	ft_move_max_min(int mov_a, int mov_b, t_list **a, t_list **b)
{
	while (mov_a != 0)
	{
		ra(a);
		mov_a--;
	}
	while (mov_b != 0)
	{
		rrb(b);
		mov_b++;
	}
	pa(a, b);
	return ;
}

void	ft_move_min_max(int mov_a, int mov_b, t_list **a, t_list **b)
{
	while (mov_a != 0)
	{
		rra(a);
		mov_a++;
	}
	while (mov_b != 0)
	{
		rb(b);
		mov_b--;
	}
	pa(a, b);
	return ;
}
