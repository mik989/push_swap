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

int	*fill_array(int len)
{
	int		*dp;
	int		i;

	i = 0;
	dp = (int *)malloc(sizeof(int) * len);
	if (!dp)
		return (NULL);
	while (i < len)
		dp[i++] = 1;
	return (dp);
}

int	*refill_array(int *v, int *dp, int len)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (i < len)
	{
		j = 0;
		while (j < i)
		{
			if (v[j] < v[i] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
			j++;
		}
		i++;
	}
	return (dp);
}

int	ft_max_len(int *dp, int len)
{
	int	i;
	int	max_len;

	max_len = 0;
	i = 0;
	while (i < len)
	{
		if (dp[i] > max_len)
			max_len = dp[i];
		i++;
	}
	return (max_len);
}
