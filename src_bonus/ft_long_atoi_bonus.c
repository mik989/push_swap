/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:39:53 by mgirardi          #+#    #+#             */
/*   Updated: 2023/03/12 15:39:55 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_bonus.h"

void	ft_long_logic(long i, long *sign, long *result, const char *str)
{
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		*sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		*result *= 10;
		*result += str[i] - '0';
		i++;
	}
}

long	ft_long_atoi(const char *str)
{	
	long	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	ft_long_logic(i, &sign, &result, str);
	return (result * sign);
}

int	is_int(char *str)
{
	long	check;

	check = ft_long_atoi(str);
	if (check > 2147483647 || check < -2147483648)
		return (0);
	return (1);
}

void	check_long_int(char	*av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!is_int(av))
		{
			write (2, "Error\n", 6);
			exit (0);
		}
		i++;
	}
}
