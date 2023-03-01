#include "include/push.h"

int *ft_move_b(t_list **b, int k)
{
    int *mov_b;
    int i;

    mov_b = malloc(sizeof(int) * k);
    i = 0;    
    while(i < k)
    {
        if(i < k / 2)
            mov_b[i] = i;
        else if (i > k / 2)
            mov_b[i] = i - k;
        else
            printf("error");
        i++;
    }
    return(mov_b);
}

int *ft_move_a(int k, t_list **tmp_a, t_list **tmp_b)
{
    int *mov_a;
    int i;

    mov_a = malloc(sizeof(int) * k);
    i = 0;
    while((*tmp_a)->next != NULL)
    {
        if((*tmp_a)->content > (*tmp_b)->content)
        {
            if(i < k / 2)
                mov_a[i] = i;
            else if (i > k / 2)
                mov_a[i] = i - k + 1;
        }
        i++;
        *tmp_a = (*tmp_a)->next;
    }
    return(mov_a);
}
int ft_best_mov( int *mov_a, int *mov_b)
    {
        int i;
        int k;
        int j;

        i = 0;
        j = -1;
        k = 0;
        while(mov_b[i])
        {
            if(k < j)
                j = k;
            if(mov_a[i] >= 0 && mov_b[i] >= 0)
                k = ft_max(mov_a[i], mov_b[i]);
            else if(mov_a[i] < 0 && mov_b[i] < 0)
                k = ft_min(mov_a[i], mov_b[i]);
            else if(mov_a[i] >= 0 && mov_b[i] < 0)
                k = ft_abs_b(mov_a[i], mov_b[i]);
            else if(mov_a[i] < 0 && mov_b[i] >= 0)
                k = ft_abs_a(mov_a[i], mov_b[i]);
            if(j == -1)
                j = k;
            i++;
        }
        return(j);
    }

void ft_movement(t_list **a, t_list **b, int k)
{
    int *mov_b;
    int *mov_a;
    int i;
    t_list **tmp_a;
    t_list **tmp_b;

    tmp_a = a;
    tmp_b = b;
    mov_b = ft_move_b(b, k);
    mov_a = ft_move_a(k, tmp_a, tmp_b);
    i = ft_best_mov(mov_a, mov_b);   
}


