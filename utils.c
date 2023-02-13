#include "include/push.h"

void ft_butta_su(t_list **a, int i)
{
    while (i > 0)
    {
        ra(a);
        i--;
    }    
    return ;
}

void ft_butta_giu(t_list **a, int i)
{
    while (i > 0)
    {
        rra(a);
        i--;
    }
    return ;
}

int min_pos(t_list *tmp, int i)
{
    int j;

    j = 0;
    while(tmp != NULL)
    {
        if (i ==  tmp->content)
            break;
        j++;
        tmp = tmp->next;
    }
    return(j);
}

int     ft_is_min_pos(t_list **a)
{
    t_list *tmp;
    int result;
	int i; 
    
    if(!a)
        return 0;
    tmp = *a;
    i = 0;    
	result = tmp->content;
	while(tmp->next != NULL)
	{
		if (result >  tmp->next->content)
			result = tmp->next->content;
        tmp = tmp->next;
	}
    i = min_pos(*a, result);
    tmp = *a;
    return (i);
}

void    ft_push_min_a(t_list **a, t_list **b)
{
    int j;

    j = ft_is_min_pos(a);
    if (j <= ft_list_size(*a) / 2)
        ft_butta_su(a, (j - 1));
    else  
        ft_butta_giu(a, (ft_list_size(*a) - j));
    pb(a, b);
    return ;
}

void    ft_free_stack(t_list *start)
{
	t_list	*i;
	t_list	*next;

	i = start;
	next = NULL;
	while (i)
	{
		next = i->next;
		free(i);
		i = next;
	}
}