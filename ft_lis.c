#include "include/push.h"
t_list *lis(int *v, int len)
{
	int i;
	t_list *p;
    t_list *n; 

    n = calloc(len, sizeof *n);
    i = 0;
	while (i++ < len)
		n[i].content = v[i];
    i = len;
	while(i--) 
    {
        p = n + i; 
		while(p++ < n + len) 
        {
			if (p->content > n[i].content && p->len >= n[i].len)
            {
				n[i].next = p;
				n[i].len = p->len + 1;
			}
		}
	}

	i = 0;
    p = n;
	while (i++ < len)
		if (n[i].len > p->len) 
            p = n + i;
    return(p);
}

void    ft_sort_lis(t_list **a, t_list **b, int size)
{
    int i;
    int *tab_1;
    t_list *tmp_a;
    t_list *tmp_b;

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
    i = 0;
    /*tmp_a = tmp_b;
    do printf(" %d", tmp_a->content); while ((tmp_a = tmp_a->next));
	putchar('\n');
    printf("\nSIZE = %d", size);
    printf("\ncosa dovrei trovare nello stack A =");*/
    while(i < size)
    {
        printf(" %d", tmp_b->content);
        if(tmp_b->content == (*a)->content && tmp_b->next != NULL) 
        {
            ra(a);
            tmp_b = tmp_b->next;               
        }
        else
            pb(a, b);     
        i++;
    }
    i = 0;
    while(i < ft_list_size(b))
    {
        ft_movement(a, b, ft_list_size(b));
        i++;
    }
}