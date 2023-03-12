/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:47:13 by mgirardi          #+#    #+#             */
/*   Updated: 2023/03/10 11:47:14 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

void	ft_checkisnumber(char *av, char **str, int free)
{
	int	i;
	int	flag;
	int	isnum;

	isnum = 1;
	flag = 0;
	i = 0;
	check_long_int(av, str, free);
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
		if (free == 1)
			ft_free_mat(str);
		exit (0);
	}		
}

void	ft_checkdouble(int ac, char **av, int free)
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
				if (free == 1)
					ft_free_mat(av);
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

int	ft_sorting(int ac, t_list **a, t_list **b)
{
	if (ft_is_ordered(*a))
		return (0);
	if (ac == 2)
		return (0);
	if (ac > 2 && ac <= 6)
		ft_sort(a, b, (ac - 1));
	if (ac > 6)
		ft_sort_lis(a, b, (ac - 1));
	return (0);
}

char	**ft_strcheck(char **av)
{
	return (ft_split(av[1], ' '));
}
