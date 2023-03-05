#include "include/push.h"

int min_pos_2(int *arr, int result, int size)
{
    int j;
    int i;

    j = 0;
    i = 0;
    while(i < size)
    {
        if (result ==  arr[i])
            break;
        j++;
        i++;
    }
    return(j);
}

int     ft_is_min_arr_pos(int *arr, int size)
{
    int i;
    int result;
    
    i = 0;
	result = arr[i];
	while(i < size)
	{
		if (result >  arr[i + 1])
			result = arr[i + 1];
        i++;
	}
    i = min_pos_2(arr, result, size);
    return (i);
}
int     ft_is_min_arr(int *arr, int size)
{
    int i;
    int result;
    
    i = 0;
	result = arr[i];
	while(i < size)
	{
		if (result >  arr[i + 1])
			result = arr[i + 1];
        i++;
	}
    return (result);
}