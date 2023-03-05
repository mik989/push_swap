#include "include/push.h"

void    ft_ultimate_movement(t_list **a)
{
    int i;

    i = ft_list_size(*a);

    if(ft_is_min_pos(a) > i/2)
    {
        while(ft_is_min_pos(a) != 0)
            rra(a);
    }
    else
    {
        while(ft_is_min_pos(a) != 0)
            ra(a);
    }

}