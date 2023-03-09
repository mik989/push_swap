#include "include/push.h"
void ft_printlist(t_list *o)
{
    t_list *p;

    p = o;
    
    while(p != NULL)
    {
        printf(" %d", p->content);
        p = p->next;
        if (!p)
            break;  
    }
}
void ft_printval(t_list *o)
{
    t_list *p;

    p = o;
    
    while(p != NULL)
    {
        printf(" %d", p->val);
        p = p->next;
        if (!p)
            break;  
    }
}

void free_list(t_list *head) {
    while (head != NULL) {
        t_list *tmp = head;
        head = head->next;
        free(tmp);
    }
}

t_list	*lis(int *v, int len)
{
	int		*dp;
	t_list	*new_node;
	t_list	*result;
	int		i;
	int		j;
	int		max_len;

	dp = (int *)malloc(sizeof(int) * len);
	if (!dp)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dp[i] = 1;
		i++;
	}
	i = 1;
	while (i < len)
	{
		j = 0;
		while (j < i)
		{
			if (v[j] < v[i] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
			j++;
		}
		i++;
	}
	max_len = 0;
	i = 0;
	while (i < len)
	{
		if (dp[i] > max_len)
			max_len = dp[i];
		i++;
	}
	result = NULL;
	i = len - 1;
	while (i >= 0 && max_len > 0)
	{
		if (dp[i] == max_len) 
		{
			new_node = (t_list *)malloc(sizeof(t_list));
			if (!new_node)
			{
				while (result)
				{
					new_node = result->next;
					free(result);
					result = new_node;
				}
				free(dp);
				return (NULL);
			}
			new_node->val = v[i];
			new_node->next = result;
			result = new_node;
			max_len--;
		}
		i--;
	}
	free(dp);
	return (result);
}


void    ft_sort_lis(t_list **a, t_list **b, int size)
{
    int i;
    int *tab_1;
    t_list *tmp_a;
    t_list *tmp_b;
    t_list *tmp_c;

    tmp_a = *a;
    i = 0;
    tab_1 = malloc(sizeof(int) * size);
    while(tmp_a != NULL)
    {
        tab_1[i] = tmp_a->content;
        i++;
        tmp_a = tmp_a->next;
    }

    tmp_b = lis(tab_1, size);
    tmp_c = tmp_b;
    i = 0;
    while(i < size)
    {        
        if(tmp_b->val == (*a)->content && tmp_b->next != NULL) 
        {
            ra(a);
            tmp_b = tmp_b->next; 
        }
        else if(tmp_b->val == (*a)->content && tmp_b->next == NULL)
            ra(a);
        else if(tmp_b->val != (*a)->content)
            pb(a,b);
        i++;
    } 
    tmp_b = tmp_c;
    free(tab_1);
    free_list(tmp_b);
    i = 0;
    size = ft_list_size(*b);
    while(size > 0)
    {
        ft_movement(a, b, size);
        size--;
    }

    ft_ultimate_movement(a);
}