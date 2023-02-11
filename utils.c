#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
    int array[] = {0, 4, 12, 2, 10, 6, 9, 13, 3, 11, 7, 15};
    int *length;
    int *sub_s;
    int *res; 
    int len = (int)(sizeof(array)/sizeof(int));
    int i = 0;
    int j = 0;
    int k = 0;
    int c = 0;

    length = malloc(sizeof(int) * len);
    sub_s = malloc(sizeof(int) * len);

    while(i < len)
    {
        length[i] = 1;
        sub_s[i] = 0;
        i++;
    }
    i = 1;
    while(i < len)
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

    res = malloc(sizeof(int) * sub_s[len-1]);

    j = length[len-1] - 1;
    k = sub_s[len-1];

    while(j >= 0)
        {
            if(j == (length[len-1] - 1))
            {
                res[j] = len - 1;
                j--;
            }
            res[j] = k;   
            k = sub_s[k];      
            j--;
        }

    j = 0;

    while(j < length[i-1])
    {  
        k = res[j];
        c = array[k];
        res[j] = c;    
        j++;
    }  

    printf("\nstringa finale = ");
    j = 0;
    while(j < length[i-1])
    {
        printf("%d ", res[j]);
        j++;
    }
    free(length);
    free(sub_s);
    free(res);
}
