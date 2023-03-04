#include "include/push.h"

int *ft_move_b(int k)
{
    int i;
    int *mov_b;
    
    mov_b = calloc(sizeof(int), k);
    if(!mov_b)
        {
           return NULL; 
        }
    i = 0;    
    while(i < k)
    {
        if(i < k / 2)
            mov_b[i] = i;
        else
            mov_b[i] = i - k;
        i++;
    }
    return(mov_b);
}

int *ft_move_a(int k, t_list **a, t_list **b)
{
    int i;
    int j;
   // int flag = 0;
    int *mov_a;
    t_list *tmp_a;
    t_list *tmp_b;

    mov_a = calloc(sizeof(int), k);
    tmp_a = *a;
    tmp_b = *b;
    i = 0;
    j = 0;
    while(tmp_b->next != NULL)
    {
        while(tmp_a->next != NULL)
        {
            if(tmp_b->content < tmp_a->content)
            {
                if(i < k / 2)
                    mov_a[j] = i;
                else
                    mov_a[j] = i - k;
                j++;
                break;
            }
            //else
            //   flag = tmp_b->content;
            i++;
            tmp_a = tmp_a->next;
        } 
      // A 70 15 40 50 65
      // B 35 42 90 10 85
        i = 0;
        tmp_a = *a;
        tmp_b = tmp_b->next;
    }
    //if (flag == 1)
    return(mov_a);
}
int ft_max(int mov_a, int mov_b)
{
    if(mov_a > mov_b)
        return(mov_a);
    return(mov_b);
}
int ft_min(int mov_a, int mov_b)
{
    if(mov_a < mov_b)
        return(mov_a * -1);
    return(mov_b * -1);
}
int ft_abs_b(int mov_a, int mov_b)
{
    mov_b *= -1;
    return(mov_a + mov_b);
}
int ft_abs_a(int mov_a, int mov_b)
{
    mov_a *= -1;
    return(mov_a + mov_b);
}

int ft_best_mov(int size, int *mov_a, int *mov_b)
{
    int i;
    int k;
    int j;
    //int size;

    //size = ((int)(sizeof(mov_b))/sizeof(int));
    i = 0;
    j = -1;
    //k = 0;
    //printf("\nVALORE SIZE= %d\n", size);
    while(i < size)
    {
        //printf("\n***** CLICLO n %d *****\n", i);
        
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
        if(k < j)
            j = k;
        //else
            //printf("\nk > j\n");
        i++;
        //printf("\nVALORE J= %d\n", j);
        //printf("\nVALORE K= %d\n", k);
}
    //printf("\nmigliore mossa = %d\n", j);
    //exit(0);
    return(j);
}

int ft_best_mov2(int mov_a, int mov_b)
{
    int k;

    k = 0;
    if(mov_a >= 0 && mov_b >= 0)
        k = ft_max(mov_a, mov_b);
    else if(mov_a < 0 && mov_b < 0)
        k = ft_min(mov_a, mov_b);
    else if(mov_a >= 0 && mov_b < 0)
        k = ft_abs_b(mov_a, mov_b);
    else if(mov_a < 0 && mov_b >= 0)
        k = ft_abs_a(mov_a, mov_b);
    return(k);
}

int ft_index(int size, int *mov_a, int *mov_b)
    {
        int i;
        int k;

        k = 0;
        i = 0;       
        k = ft_best_mov(size, mov_a, mov_b);
        while(k != ft_best_mov2(mov_a[i], mov_b[i]))
        {
            //printf("\n           K= %d\n", k);
            //printf("\nft_best_mov2= %d\n", ft_best_mov2(mov_a[i], mov_b[i]));
            i++;
        }
        return(i);
    }
void    ft_move_min(int mov_a, int mov_b, t_list **a, t_list **b)
{
    mov_a *= -1;
    mov_b *= -1;
    while(mov_a != 0 && mov_b != 0)
    {
        rrr(a, b);
        mov_a--;
        mov_b--;
    }
    while(mov_a != 0 || mov_b != 0)
    {
        if(mov_b != 0)
        {
            rrb(b);
            mov_b--;
        }
        if(mov_a != 0)
        {
            rra(a);
            mov_a--;           
        }
    }
    pa(a, b);    
    return;
}
void    ft_move_max(int mov_a, int mov_b, t_list **a, t_list **b)
{
    while(mov_a != 0 && mov_b != 0)
    {
        rr(a, b);
        mov_a--;
        mov_b--;
    }
    while(mov_a != 0 || mov_b != 0)
    {
        if(mov_b != 0)
        {
            rb(b);
            mov_b--;
        }
        if(mov_a != 0)
        {
            ra(a);
            mov_a--;           
        }
    }
    pa(a, b);    
    return;
}
void    ft_move_max_min(int mov_a, int mov_b, t_list **a, t_list **b)
{
   
    while(mov_a > 0)
    {
        ra(a);
        mov_a--;
    }
    while(mov_b < 0)
    {
        rb(b);
        mov_b++;
    }
}
void    ft_move_min_max(int mov_a, int mov_b, t_list **a, t_list **b)
{    
    while(mov_a < 0)
    {
        ra(a);
        mov_a++;
    }
    while(mov_b > 0)
    {
        rb(b);
        mov_b--;
    }
}
void ft_movement(t_list **a, t_list **b, int k)
{
    int *mov_b;
    int *mov_a;
    int i;
    t_list *_a;
    t_list *_b;

    _a = *a;
    _b = *b;

    i = 0;
    printf("\nNUMERI STACK A = ");
    while(i < k)
    {
        printf(" %d", _a->content);
        _a = _a->next;
        i++;
    }

    i = 0;
    printf("\nNUMERI STACK B = ");
    while(i < k)
    {
        printf(" %d", _b->content);
        _b = _b->next;
        i++;
    }


    i = 0;   
    //printf("\nLISTA A= ");
    //ft_printlist(*a);
    //printf("\nLISTA B= ");
    //ft_printlist(*b);
    mov_b = ft_move_b(k);
    mov_a = ft_move_a(k, a, b);
    printf("\nMOSSE mov_a = ");
    while(i < k)
          printf(" %d", mov_a[i++]);
    i = 0;
    printf("\nMOSSE mov_b = ");
    while(i < k)
          printf(" %d", mov_b[i++]);
    i = ft_index(k, mov_a, mov_b);
    //printf("\nindice mossa migliore = %d\n", i);
    if(mov_a[i] >= 0 && mov_b[i] >= 0)
        ft_move_max(mov_a[i], mov_b[i], a, b);        
    else if(mov_a[i] < 0 && mov_b[i] < 0)
        ft_move_min(mov_a[i], mov_b[i], a, b);
    else if(mov_a[i] >= 0 && mov_b[i] < 0)
        ft_move_max_min(mov_a[i], mov_b[i], a, b);
    else if(mov_a[i] < 0 && mov_b[i] >= 0)
        ft_move_min_max(mov_a[i], mov_b[i], a, b);
    free(mov_a);
    free(mov_b);
    return;
}
/*
4 8 9 12 27 32

10 13 1 2


-3 -2  0  0
 0  1  2  3
*/