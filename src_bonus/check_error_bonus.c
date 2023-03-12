/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:47:13 by mgirardi          #+#    #+#             */
/*   Updated: 2023/03/12 16:58:26 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_bonus.h"

void	ft_checkisnumber(char *av)
{
	int	i;
	int	flag;
	int	isnum;

	isnum = 1;
	flag = 0;
	i = 0;
	check_long_int(av);
	while (av[i])
	{
		if (av[i] == '+' || av[i] == '-')
			flag += 1;
		else if (!ft_isdigit(av[i]))
			isnum *= ft_isdigit(av[i]);
		i++;
	}
	if (flag > 1 || !isnum)
	{
		write (2, "Error\n", 6);
		exit (0);
	}		
}

void	ft_checkdouble(int ac, char **av)
{
	int	j;
	int	i;

	j = 1;
	i = j + 1;
	while (j < ac)
	{
		while (av[j] && (i < ac))
		{
			if (ft_atoi(av[j]) == ft_atoi(av[i++]))
			{
				write (2, "Error\n", 6);
				exit (0);
			}
		}
		j++;
		i = j + 1;
	}
}

void	ft_buildstacka(int ac, char **av, t_list **a, t_list **new)
{
	int	i;
	int	pippo;

	i = 1;
	while (i < ac)
	{
		pippo = ft_atoi(av[i]);
		*new = ft_lstnew(pippo);
		ft_lstadd_back(a, *new);
		i++;
	}
}

