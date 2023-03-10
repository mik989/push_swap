#include "include/push.h"

int	main(int ac, char **av)
{
	t_list	*b;
	t_list	*a;
	t_list	*new;
	int		j;
	char **str;
	j = 1;
	a = NULL;
	new = NULL;
	b = NULL;
	
	str = ft_strcheck(ac, av);
	while (j < ac)
	{
		ft_checkisnumber(str[j]);
		j++;
	}
	ft_checkdouble(ac, str);
	ft_buildstacka(ac, str, &a, &new);
	ft_sorting(ac, &a, &b);
	ft_printlist(a);
	ft_free_stack(a);
	ft_free_stack(b);
}
