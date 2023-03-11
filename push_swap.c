/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:44:38 by mgirardi          #+#    #+#             */
/*   Updated: 2023/03/10 11:44:40 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push.h"

int	ft_count_args(char **str)
{
	int	j;

	j = 0;
	while (str[j])
		j++;
	return (j);
}

void	ft_free_mat(char **str)
{
	int	j;

	j = 1;
	while (str[j])
		free(str[j++]);
	free(str);
}

void	ft_start_1(char **av, t_list *a, t_list	*b)
{
	int		j;
	int		ac;
	t_list	*new;
	char	**str;

	new = NULL;
	j = 1;
	str = ft_strcheck(av);
	ac = ft_count_args(str);
	while (j < ac)
	{
		ft_checkisnumber(str[j], str, 1);
		j++;
	}
	ft_checkdouble(ac, str, 1);
	ft_buildstacka(ac, str, &a, &new);
	ft_sorting(ac, &a, &b);
	ft_free_mat(str);
	// ft_printlist(a);
	ft_free_stack(a);
	ft_free_stack(b);
	return ;
}

void	ft_start_2(int ac, char **av, t_list *a, t_list	*b)
{
	int		j;
	t_list	*new;

	new = NULL;
	j = 1;
	while (j < ac)
	{
		ft_checkisnumber(av[j], av, 0);
		j++;
	}
	ft_checkdouble(ac, av, 0);
	ft_buildstacka(ac, av, &a, &new);
	ft_sorting(ac, &a, &b);
	// ft_printlist(a);
	ft_free_stack(a);
	ft_free_stack(b);
	return ;
}

int	main(int ac, char **av)
{
	t_list	*b;
	t_list	*a;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (ac == 2)
		ft_start_1(av, a, b);
	else
		ft_start_2(ac, av, a, b);
}
