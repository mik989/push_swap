#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int array[] = {0, 4, 12, 2, 10, 6, 9, 13, 3, 11, 7, 15};
    int len_array = (int)(sizeof(array) / sizeof(int));
    int length[] = {0, 4, 12, 2, 10, 6, 9, 13, 3, 11, 7, 15};
    int sub_s[] = {0, 4, 12, 2, 10, 6, 9, 13, 3, 11, 7, 15};
    int i = 0;
    int j;
    int k = 1;
    while(i < len_array)
    {
        length[i] = 1;
        sub_s[i] = 0;
        i++;
    }
    i = 1;
    j = 0; 
    while(i < len_array)
    {
        while(j < i)
        {
            if(array[j] < array[i])
            {
                k = length[j] + 1;
                if(k >= length[i])
                { 
                    length[i] = k;
                    sub_s[i] = j;
                }
            }                      
            j++;      
        }                
        j = 0;
        i++;
    }
    i = 0;
    j = 0;
    printf("\nSub Sequence = ");
    while(i < len_array) 
    {
        printf("%d ", sub_s[i]);
        i++;
    }
    
    return 0;
}
