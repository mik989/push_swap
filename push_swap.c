#include "include/push.h"

int main (int ac, char **av)
{
    int j;
    int i;
    t_list *a;
    t_list *new;
    t_list *b;

    a = NULL;
    b = NULL;
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
            new = ft_lstnew(pippo);
            ft_lstadd_back(&a, new);
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
        ft_free_stack(a);
        ft_free_stack(b);
        ft_free_stack(new);


}   