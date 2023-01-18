#include <unistd.h>
#include "lib/libft.h"

void	ft_rotlst(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	*lst = ft_lstlast(*lst);
	(*lst)->next = tmp;
	*lst = tmp->next;
	tmp->next = NULL;
}

void ft_ra(t_list **a)
{
    ft_rotlst(a);
    write(1, "ra\n", 3);
}

void ft_ra(t_list **b)
{
    ft_rotlst(b);
    write(1, "rb\n", 3);
}

void ft_rr(t_list **a, t_list **b)
{
    ft_rotlst(a);
    ft_rotlst(b);
    write(1, "rr\n", 3);
}