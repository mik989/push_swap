#include "include/push.h"

int main (int ac, char **av)
{
    int j;
    int i;
    t_list *a;
    t_list *b;
    t_list *a1;

    a = NULL;
    b = NULL;
    a1 = NULL;
    j = 1;
    i = 0;
        if(ac == 1)
            return 0;         
        while(j < ac)
        {
            while(av[j][i] != '\0' && (j < ac - 1))
                {
                    if (ft_isdigit(av[j][i]))
                        i++;
                    else
                    {   write(2, "Error\n", 6);
                        exit(0);
                    }
                }
                j++;
        }
        j = 1;
        i = j + 1;
        while(j < ac)
        {
            while(av[j] && (i < ac))
                {
                    if(ft_atoi(av[j]) == ft_atoi(av[i]))
                    {
                        write(2, "Error\n", 6);
                        exit(0);
                    }
                    else
                        i++;
                }
            j++;
        }        
        i = 1;        
        while (i < ac)
        {
            int pippo = ft_atoi(av[i]);            
            a1 = ft_lstnew(pippo);
            ft_lstadd_back(&a, a1);
            i++;
        }        
        if (ac == 2)
            return 0;
        
        if (ac > 2 && ac <= 6)
           ft_sort(&a, &b, (ac - 1));

        while(a != NULL )
        {
            printf("%d ", a->content);
            a = a->next;
        }
/*
        if (ac == 6)
            xxxx;
        if (ac > 6)
            xxxx;*/
}