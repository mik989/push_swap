#include "include/push.h"
/*
void ft_index_res_fill(int *array, t_lis_algo *v)
{
     while(v->j >= 0)
        {
            if(v->j == (v->length[v->len-1] - 1))
            {
                v->res[v->j] = v->len - 1;
                v->j--;
            }
            v->res[v->j] = v->k;   
            v->k = v->sub_s[v->k];      
            v->j--;
        }
    v->j = 0;
    while(v->j < v->length[v->i-1])
    {  
        v->k = v->res[v->j];
        v->c = array[v->k];
        v->res[v->j] = v->c;    
        v->j++;
    }  
}

void ft_lis_sub_s_fill(int *array, t_lis_algo *v)
{
	while(v->i < v->len)
    {
        while(v->j < v->i)
        {
            if(array[v->j] < array[v->i])
            {
                v->k = v->length[v->j] + 1;
                if(v->k >= v->length[v->i])
                { 
                    v->length[v->i] = v->k;
                    v->sub_s[v->i] = v->j;
                }
            }                      
            v->j++;      
        }                
        v->j = 0;
        v->i++;
    }
    v->res = malloc(sizeof(int) * v->sub_s[v->len-1]);
    v->j = v->length[v->len-1] - 1;
    v->k = v->sub_s[v->len-1];
}

void    ft_lis_init(t_lis_algo *v, int size)
{
    v->len = size;
    v->length = malloc(sizeof(int) * v->len);
    v->sub_s = malloc(sizeof(int) * v->len);
    v->i = 0;
    v->k = 0;
    v->c = 0;
    v->j = 0;
    while(v->i < v->len)
    {
        v->length[v->i] = 1;
        v->sub_s[v->i] = 0;
        v->i++;
    }
    v->i = 1;
    return ;
}

int *ft_lis_algo(int *array, int size)
{
    t_lis_algo *v;

    v = malloc(sizeof(t_lis_algo));

    ft_lis_init(v, size);
    ft_lis_sub_s_fill(array, v);
    ft_index_res_fill(array, v);   

    printf("\nv.res = ");
    v->j = 0;
    while(v->j < v->length[v->i-1])
    {
        printf("%d ", v->res[v->j]);
        v->j++;
    }
    free(v->length);
    free(v->sub_s);
    //LIBERARE v->res A TERMINE DEL PROGRAMMA
    //LIBERARE LISTA v A TERMINE DEL PROGRAMMA
    return(v->res);
}*/

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

    //free(n);
    return(p);
}

void    ft_sort_lis(t_list **a, t_list **b, int size)
{
    int i;
    //int j;
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
    //j = 0;

    tmp_a = tmp_b;

    do printf(" %d", tmp_a->content); while ((tmp_a = tmp_a->next));
	putchar('\n');

    //j = ft_list_size(tmp_b);

    printf("\nSIZE = %d", size);
    printf("\ncosa dovrei trovare nello stack A =");
    while(i < size)
    {
        //if((*a)->next == NULL)
        //    break; 
        printf(" %d", tmp_b->content);
        if(tmp_b->content == (*a)->content && tmp_b->next != NULL) 
            {
                ra(a);
                tmp_b = tmp_b->next;               
            }
        else
            {
                pb(a, b);
            }       
        i++;
    }
}