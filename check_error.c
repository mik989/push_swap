#include "include/push.h"

void	ft_checkisnumber(char *av)
{
	int	i;
	int	flag;
	int	isnum;

	isnum = 0;
	flag = 0;
	i = 0;
	while (av[i])
	{
		if (av[i] == '+' || av[i] == '-')
			flag += 1;
		else if (ft_isdigit(av[i]))
			isnum = ft_isdigit(av[i]);
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
			if (atoi(av[j]) == atoi(av[i++]))
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
		pippo = atoi(av[i]);
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
char **ft_strcheck(int ac, char **av)
{
	if (ac == 1)
		return (NULL);
	if (ac == 2)
		return(ft_split(av[1], ' '));
	return (av);
}
