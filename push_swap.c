#include "include/push.h"

int main (int ac, char **av)
{
    t_list *b;
    t_list *a;
    t_list *new;
    int j;

    j = 1;
    a = NULL;
    new = NULL;
    b = NULL;
    if(ac == 1)
        return 0;
    while(j < ac)
    {
        ft_checkisnumber(av[j]);
        j++;
    }
    ft_checkdouble(ac, av);      
    ft_buildstackA(ac, av, &a, &new); 
    ft_sorting(ac, &a, &b);
    ft_printlist(a);
}   