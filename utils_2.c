#include "include/push.h"

int nextGreaterElement(t_list **a, int n)
{
    t_list *tmp_a;
    int i;
    int flag;
    int prev;
    int c;

    flag = 1;
    i = 1;
    c = 0;
    tmp_a = *a;
    while(tmp_a)
    {
        if(tmp_a->content > n && flag)
        {
        c = i;
        prev = tmp_a->content;
        flag = 0;
        }
        else if(tmp_a->content > n && !flag)
        {
            if(tmp_a->content < prev)
            {
                c = i;
                prev = tmp_a->content;
            }
        }
        tmp_a = tmp_a->next;
        i++;
    }
    
    if(c == 0)
    {
        return(ft_is_min_pos(a));
    }
    if((c - 1) < (ft_list_size(*a) / 2))
        return(c - 1);
    else
        return(c - 1 - ft_list_size(*a));
}

/*
int nextGreaterElement(t_list **a, int n)
{
  t_list *tmp_a;
    int i;
    int flag;

    flag = 0;
    i = 0;
    tmp_a = *a;
    while(tmp_a)
    {
        i++;
        if((n > tmp_a->content) && (n < tmp_a->next->content))        
        {
            flag = 1;
            break;
        }
        tmp_a = tmp_a->next;
        if(tmp_a->next == NULL)
            break;      
    }
    //return(i+1);
    //printf("\n***** POSIZIONE DEL NUMERO = %d *****\n", i);
    if(flag == 0)
        {
            i = ft_is_min_pos(a);
            //printf("\n***** VALORE N = %d *****\n", n);
            //printf("\n***** VALORE MIN_POS = %d *****\n", i);
        }
    if(i < (ft_list_size(*a) / 2))
        return(i);
    else
        return(i - ft_list_size(*a));
}*/