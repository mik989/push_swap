/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:46:01 by mgirardi          #+#    #+#             */
/*   Updated: 2023/03/10 11:46:03 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

int	ft_max(int mov_a, int mov_b)
{
	if (mov_a > mov_b)
		return (mov_a);
	return (mov_b);
}

int	ft_min(int mov_a, int mov_b)
{
	if (mov_a < mov_b)
		return (mov_a * -1);
	return (mov_b * -1);
}

int	ft_abs_b(int mov_a, int mov_b)
{
	mov_b *= -1;
	return (mov_a + mov_b);
}

int	ft_abs_a(int mov_a, int mov_b)
{
	mov_a *= -1;
	return (mov_a + mov_b);
}
