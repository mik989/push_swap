/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:39:01 by mgirardi          #+#    #+#             */
/*   Updated: 2023/03/12 15:39:05 by mgirardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_bonus.h"

void	ft_display_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

void	exec_check(t_list **a, t_list **b, char *str)
{
	if (ft_strncmp(str, "rr\n", 3) == 0)
	{
		ft_rotlst(a);
		ft_rotlst(b);
	}
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		ft_revlst(a);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		ft_revlst(b);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
	{
		ft_revlst(a);
		ft_revlst(b);
	}
	else
		ft_display_exit();
}

void	ft_exec_sort(t_list **a, t_list **b, char *str)
{
	while (str != NULL)
	{
		if (ft_strncmp(str, "sa\n", 3) == 0)
			swap(a);
		else if (ft_strncmp(str, "sb\n", 3) == 0)
			swap(b);
		else if (ft_strncmp(str, "ss\n", 3) == 0)
		{
			swap(a);
			swap(b);
		}
		else if (ft_strncmp(str, "pa\n", 3) == 0)
			push_a(a, b);
		else if (ft_strncmp(str, "pb\n", 3) == 0)
			push_b(a, b);
		else if (ft_strncmp(str, "ra\n", 3) == 0)
			ft_rotlst(a);
		else if (ft_strncmp(str, "rb\n", 3) == 0)
			ft_rotlst(b);
		else
			exec_check(a, b, str);
		free(str);
		str = get_next_line(0);
	}
}

void	ft_check_sort(t_list *stack_a, t_list *stack_b)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->content > (stack_a->next)->content)
		{
			write(1, "KO\n", 3);
			return ;
		}
		stack_a = stack_a->next;
	}
	if (stack_b != NULL)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	return ;
}

int	main(int ac, char **av)
{
	t_list	*check_a;
	t_list	*check_b;
	t_list	*new;
	int		j;
	char	*str;

	j = 1;
	check_a = NULL;
	check_b = NULL;
	if (ac < 2)
		return (0);
	while (j < ac)
	{
		ft_checkisnumber(av[j]);
		j++;
	}
	ft_checkdouble(ac, av);
	ft_buildstacka(ac, av, &check_a, &new);
	str = get_next_line(0);
	ft_exec_sort(&check_a, &check_b, str);
	ft_check_sort(check_a, check_b);
	free_stack(check_a);
	free_stack(check_b);
	return (0);
}
