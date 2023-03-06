#include "include/push.h"
/*t_list	*create_node(int val)
{
	t_list	*i;

	i = (t_list *)malloc(sizeof(t_list));
	i->content = val;
	i->len = 0;
	i->next = NULL;
	return (i);
}
t_list	*create_list(int ac, int *av)
{
	int		i;
	t_list	*start;
	t_list	*tmp;
	t_list	*next;

	i = 1;
	start = NULL;
	tmp = NULL;
	next = NULL;
	while (i < ac)
	{
		next = create_node(atoi(av[i]));
		if (start == NULL)
			start = next;
		if (tmp != NULL)
			tmp->next = next;
		tmp = next;
		i++;
	}
	return (start);
}*/
void ft_butta_su(t_list **a, int i)
{
    while (i >= 0)
    {
        ra(a);
        i--;
    }    
    return ;
}

void ft_butta_giu(t_list **a, int i)
{
    while (i >= 0)
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

int max_pos(t_list *tmp, int i)
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

int     ft_is_max_pos(t_list **a)
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
		if (result <  tmp->next->content)
			result = tmp->next->content;
        tmp = tmp->next;
	}
    i = max_pos(*a, result);
    tmp = *a;
    return (i);
}

int     ft_is_max(t_list **a)
{
    t_list *tmp;
    int result;
    
    if(!a)
        return 0;
    tmp = *a;
	result = tmp->content;
	while(tmp->next != NULL)
	{
		if (result <  tmp->next->content)
			result = tmp->next->content;
        tmp = tmp->next;
	}
    tmp = *a;
    return (result);
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