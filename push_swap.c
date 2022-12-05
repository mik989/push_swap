#include <unistd.h>
#include "lib/libft.h"

int main (int ac, char **av)
{
    int j;
    int i;

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
                    {   write(2, "error\n", 6);
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
                        write(2, "error\n", 6);
                        exit(0);
                    }
                    else
                        i++;
                }
            j++;
        }        
        
        if (ac == 2)
            return 0;
        /*if(ac > 2)
        {

        }*/
}