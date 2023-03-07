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

t_list *lis(int *v, int len)
{
	int i;
	lis_list *p; 
    lis_list *n = calloc(sizeof(lis_list), len);
    t_list *k;
    t_list *t;

    
	for (i = 0; i < len; i++)
		n[i].val = v[i];

	for (i = len; i--; ) {
		for (p = n + i; p++ < n + len; ) {
			if (p->val > n[i].val && p->len >= n[i].len) {
				n[i].next = p;
				n[i].len = p->len + 1;
			}
		}
	}
	for (i = 0, p = n; i < len; i++)
		if (n[i].len > p->len) p = n + i;

	//do printf(" %d", p->val); while ((p = p->next));
	//putchar('\n');
    //exit(0);
    i = ft_lstlisize(p);
    //printf("i = %d\n", i);
    k = malloc(sizeof(t_list));
    t = k;
    while(p->next)
    {
        k->content = p->val;
        k->next = malloc(sizeof(t_list));
        //printf("k->content = %d\n", k->content);
        //printf("p->val = %d\n", p->val);
        k = k->next;  
        p = p->next;
    }
    k->content = p->val;
    k->next = NULL;
    /*printf("\n\n");
    printf("\nPRINT LIST t = ");
    ft_printlist(t);
    printf("\n\n");
    //exit(0);*/
    return(t);
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
    while(i < size)
    {        
        if(tmp_b->content == (*a)->content && tmp_b->next != NULL) 
        {
            ra(a);
            tmp_b = tmp_b->next; 
        }
        else if(tmp_b->content == (*a)->content && tmp_b->next == NULL)
            ra(a);
        else if(tmp_b->content != (*a)->content)
            pb(a,b);
        i++;
    }
    i = 0;
   
    //printf("\n***** DOPO IL PUSH *****");
    //printf("\nsize = %d\n", size);
    /*printf("\nLISTA A= ");
    ft_printlist(*a);
    printf("\nLISTA B= ");
    ft_printlist(*b);
    printf("\n\n");*/
    /*if(ft_list_size(*a) < ft_list_size(*b))
        size = ft_list_size(*a);
    else*/
    size = ft_list_size(*b);
    while(size > 0)
    {
       // printf("\n****** %d *****\n", size);
        ft_movement(a, b, size);
        size--;
    }
    /*tmp_a = *a;
    tmp_b = *b;
    printf("\nNUMERI STACK A = ");
    while(tmp_a)
    {
        printf(" %d", tmp_a->content);
        if(tmp_a->next == NULL)
            break;
         tmp_a = tmp_a->next;
        i++;
    }

    i = 0;
    printf("\nNUMERI STACK B = ");
    while(tmp_b)
    {
        printf(" %d", tmp_b->content);
        tmp_b = tmp_b->next;
        i++;
    }*/
    ft_ultimate_movement(a);
}