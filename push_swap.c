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
    new = NULL;
    j = 1;
    i = 0;
        if(ac == 1)
            return 0;         
        while(j < ac)
        {
            while(av[j][i] != '\0' && (j < ac))
                {
                    if (ft_isdigit(av[j][i]))
                        i++;
                    else
                    {   write(2, "Error\n", 6);
                        exit(0);
                    }
                }
                j++;
                i = 0;
        }
        j = 1;
        i = j + 1;
        while(j < ac)
        {
            while(av[j] && (i < ac))
                {
                    if(atoi(av[j]) == atoi(av[i]))
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
            int pippo = atoi(av[i]); 
            //printf("PIPPO = %d\n", pippo);           
            new = ft_lstnew(pippo);
            ft_lstadd_back(&a, new);
            i++;
        }        
        if (ac == 2)
            return 0;
        
        if (ac > 2 && ac <= 6)
           ft_sort(&a, &b, (ac - 1));
        if (ac > 6)
            ft_sort_lis(&a, &b, (ac - 1));

       /* printf("\n***** STACK A E B FINALI *****");
        printf("\nstack A = ");
        while(a != NULL )
        {
            printf("%d ", a->content);
            a = a->next;
        }
        printf("\nstack B = ");
        while(b != NULL )
        {
            printf("%d ", b->content);
            b = b->next;
        }
        putchar('\n');*/
        //ft_free_stack(a);
        //ft_free_stack(b);
        //ft_free_stack(new);

}   