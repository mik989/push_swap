/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:43:54 by mgirardi          #+#    #+#             */
/*   Updated: 2023/03/10 11:43:57 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

int	*ft_move_b(int k)
{
	int	i;
	int	*mov_b;

	mov_b = calloc(sizeof(int), k);
	if (!mov_b)
	{
		return (NULL);
	}
	i = 0;
	while (i < k)
	{
		if (k == 1)
			mov_b[0] = 0;
		else if (i < k / 2)
			mov_b[i] = i;
		else
			mov_b[i] = i - k;
		i++;
	}
	return (mov_b);
}

int	*ft_move_a(int k, t_list **a, t_list **b)
{
	int		*mov_a;
	t_list	*tmp_b;
	t_list	*op;

	op = calloc(sizeof(t_list), 1);
	ft_init_flag(op);
	mov_a = calloc(sizeof(int), k);
	tmp_b = *b;
	while (tmp_b)
	{
		nextgreaterelement(a, op, tmp_b->content);
		if (op->c == 0)
			op->c = ft_is_min_pos(a);
		if (op->flag == 0)
			op->c -= 1;
		if (op->c < (ft_list_size(*a) / 2))
			mov_a[op->j] = op->c;
		else
			mov_a[op->j] = op->c - ft_list_size(*a);
		ft_init_flag(op);
		op->j++;
		tmp_b = tmp_b->next;
	}
	free(op);
	return (mov_a);
}

int	ft_best_mov(int size, int *mov_a, int *mov_b)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	j = -1;
	k = 0;
	while (i < size)
	{
		if (mov_a[i] >= 0 && mov_b[i] >= 0)
			k = ft_max(mov_a[i], mov_b[i]);
		else if (mov_a[i] < 0 && mov_b[i] < 0)
			k = ft_min(mov_a[i], mov_b[i]);
		else if (mov_a[i] >= 0 && mov_b[i] < 0)
			k = ft_abs_b(mov_a[i], mov_b[i]);
		else if (mov_a[i] < 0 && mov_b[i] >= 0)
			k = ft_abs_a(mov_a[i], mov_b[i]);
		if (j == -1)
			j = k;
		if (k < j)
			j = k;
		i++;
	}
	return (j);
}

int	ft_best_mov2(int mov_a, int mov_b)
{
	int	k;

	k = 0;
	if (mov_a >= 0 && mov_b >= 0)
		k = ft_max(mov_a, mov_b);
	else if (mov_a < 0 && mov_b < 0)
		k = ft_min(mov_a, mov_b);
	else if (mov_a >= 0 && mov_b < 0)
		k = ft_abs_b(mov_a, mov_b);
	else if (mov_a < 0 && mov_b >= 0)
		k = ft_abs_a(mov_a, mov_b);
	return (k);
}

void	ft_movement(t_list **a, t_list **b, int k)
{
	int	*mov_b;
	int	*mov_a;
	int	i;

	mov_b = ft_move_b(k);
	mov_a = ft_move_a(k, a, b);
	i = 0;
	i = ft_index(k, mov_a, mov_b);
	if (mov_a[i] >= 0 && mov_b[i] >= 0)
		ft_move_max(mov_a[i], mov_b[i], a, b);
	else if (mov_a[i] < 0 && mov_b[i] < 0)
		ft_move_min(mov_a[i], mov_b[i], a, b);
	else if (mov_a[i] >= 0 && mov_b[i] < 0)
		ft_move_max_min(mov_a[i], mov_b[i], a, b);
	else if (mov_a[i] < 0 && mov_b[i] >= 0)
		ft_move_min_max(mov_a[i], mov_b[i], a, b);
	free(mov_a);
	free(mov_b);
	return ;
}
