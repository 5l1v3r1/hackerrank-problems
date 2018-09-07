#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define wl(n) while(n--)
#define fl(i,a,b) for(i=a; i<b; ++i)
#define max(a,b) a>=b?a:b

// Complete the equal function below.
int maxSubsetSum(int* arr, int arr_s) {
    arr[1] = max(arr[1], arr[0]);

    for(int i = 2 ; i < arr_s ; ++i)
    {
        arr[i] = max(max(arr[i-2] + arr[i], arr[i-1]), arr[i]);
    }

    return arr[arr_s - 1];
}

void fastscan(int* number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;
 
    *number = 0;
 
    // extract current character from buffer
    c = getchar_unlocked();
    if (c=='-')
    {
        // number is negative
        negative = true;
 
        // extract the next character from the buffer
        c = getchar_unlocked();
    }
 
    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar_unlocked())
        *number = *number *10 + c - 48;
 
    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        *number *= -1;
}

int main()
{
    int n = 0;
    fastscan(&n);

    int* arr = malloc(sizeof(int) * n);

    int i;
    fl(i,0,n)
    {
        fastscan(&arr[i]);
    }

    int result = maxSubsetSum(arr, n);

    free(arr);

    printf("%d\n", result);

    return 0;
}
