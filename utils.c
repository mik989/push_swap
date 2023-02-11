#include "include/push.h"

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

void    ft_lis_init(int *array, t_lis_algo *v)
{
    v->len = (int)(sizeof(&array) / sizeof(int));
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
}

int *ft_lis_algo(int *array)
{
    t_lis_algo v;

    ft_lis_init(array, &v);
    ft_lis_sub_s_fill(array, &v);
    ft_index_res_fill(array, &v);   

    printf("\nstringa finale = ");
    v.j = 0;
    while(v.j < v.length[v.i-1])
    {
        printf("%d ", v.res[v.j]);
        v.j++;
    }
    free(v.length);
    free(v.sub_s);
    /*LIBERARE v.res A TERMINE DEL PROGRAMMA*/
    return(v.res);
}
