/*
    Generate unique random numbers using a swapping algorithm
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAXSIZE 10000000
#define SWAPS   1000000

int main ()
{
    static int arr[MAXSIZE];
    int i;

    srand(time(NULL));

    // Initialize sorted array
    for (i = 0; i < MAXSIZE; i++)
        arr[i] = i;

    for (i = 0; i < SWAPS; i++) {
        int num1 = arr[i];
        int j    = rand() % MAXSIZE;
        int num2 = arr[j];

        arr[i] = num2;
        arr[j] = num1;
    }

    for (i = 0; i < SWAPS; i++)
        printf("%d\n", arr[i]);

    return 0;
}
