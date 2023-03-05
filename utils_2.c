#include "include/push.h"

int nextGreaterElement(t_list **a, int n)
{
    t_list *tmp_a;
    int i;
    
    i = 0;
    tmp_a = *a;
    while(tmp_a)
    {
        if((n > tmp_a->content) && (n < tmp_a->next->content))
        {
            i++;
            break;
        }
        tmp_a = tmp_a->next;
        i++;
    }
    //printf("\n***** POSIZIONE DEL NUMERO = %d *****\n", i);
    if(i < (ft_list_size(*a) / 2))
        return(i);
    else
        return(i - ft_list_size(*a));
}