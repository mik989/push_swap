#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int array[] = {0, 4, 12, 2, 10, 6, 9, 13, 3, 11, 7, 15};
    int len_array = (int)(sizeof(array) / sizeof(int));
    int *length = malloc(sizeof(int) * len_array);
    int *sub_s = malloc(sizeof(int) * len_array);
    int *res;
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

    res = malloc(sizeof(int) * length[i-1]); 

    j = length[len_array-1] - 1;
    k = sub_s[len_array-1];
     while(j > 0)
        {
            if(j == (length[len_array-1] - 1))
            {
                res[j] = len_array - 1;
                j--;
            }
            res[j] = k;   
            k = sub_s[k];      
            j--;
        }  
    int c = 0;
    j = 0;
    while(j < length[i-1])
    {  
        k = res[j];
        c = array[k];
        res[j] = c;    
        j++;
    }
    
    printf("\n i = %d", i); 
    printf("\nlength[i] = %d", length[i-1]);

    i = 0;
    j = 0;

    printf("\narray = ");
    while(i < len_array) 
    {
        printf("%d ", array[i]);
        i++;
    }

    i = 0;
    j = 0;

    printf("\nlength array = ");
    while(i < len_array) 
    {
        printf("%d ", length[i]);
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
    i = 0;
    j = length[len_array - 1];
    printf("\nFinal result = ");
    while(i < j) 
    {  
        printf("%d ", res[i]);
        i++;
    }

    printf("\n");
    free(length);
    free(sub_s);
    free(res);
    return 0;
}