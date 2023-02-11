#include "include/push.h"

void	ft_sort_2(t_list **a)
{
	t_list	*beholder;
	t_list	*beholder2;

	beholder = *a;
	beholder2 = beholder->next;
	if (beholder->content > beholder2->content)
		sa(a);
}

void	first_sort_3_if(t_list *tmp, t_list *tmp2, t_list *tmp3, t_list **a)
{
	if (tmp2->content < tmp3->content)
		return ;
	else if (tmp3->content < tmp->content)
		rra(a);
	else
	{
		rra(a);
		sa(a);
	}
}

void	ft_sort_3(t_list **a)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*tmp3;

	tmp = *a;
	tmp2 = tmp->next;
	tmp3 = tmp2->next;
	if (tmp->content < tmp2->content)
		first_sort_3_if(tmp, tmp2, tmp3, a);
	else if (tmp2->content < tmp3->content)
	{
		if (tmp3->content < tmp->content)
			ra(a);
		else
			sa(a);
	}
	else
	{
		sa(a);
		rra(a);
	}
}

void	ft_sort_5(t_list **a, t_list **b, int size)
{
	//if (is_ordered(*a))
	//	return ;
	if (size == 2)
		ft_sort_2(a);
	if (size == 3)
		ft_sort_3(a);
	if (size == 4)
	{
	//	push_min(a, b);
		ft_sort_3(a);
		pa(a, b);
	}
	if (size == 5)
	{
	//	push_min(a, b);
	//	push_min(a, b);
		ft_sort_3(a);
		pa(a, b);
		pa(a, b);
	}
}