#include "include/push.h"

void	ft_display_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

void	exec_check(t_list **a, t_list **b, char *str)
{
	if (ft_strncmp(str, "rr\n", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		rr_a(a);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		rr_b(b);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		rrr(a, b);
	else
		ft_display_exit();
}

void	ft_exec_sort(t_list **a, t_list **b, char *str)
{
	while (str != NULL)
	{
		if (ft_strncmp(str, "sa\n", 3) == 0)
			sw_a(a);
		else if (ft_strncmp(str, "sb\n", 3) == 0)
			sw_b(b);
		else if (ft_strncmp(str, "ss\n", 3) == 0)
			ss(a, b);
		else if (ft_strncmp(str, "pa\n", 3) == 0)
			push_a(a, b);
		else if (ft_strncmp(str, "pb\n", 3) == 0)
			push_b(a, b);
		else if (ft_strncmp(str, "ra\n", 3) == 0)
			rot_a(a);
		else if (ft_strncmp(str, "rb\n", 3) == 0)
			rot_b(b);
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
	char	*str;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	else
	{
		if (check_args(ac, av))
			ft_display_exit();
	}
	ft_buildstacka(ac, av, &check_a, &new);
	str = get_next_line(0);
	ft_exec_sort(&check_a, &check_b, str);
	ft_check_sort(check_a, check_b);
	ft_free_stack(check_a);
	ft_free_stack(check_b);
	return (0);
}