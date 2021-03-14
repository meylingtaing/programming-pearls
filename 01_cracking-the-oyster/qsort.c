/*
    Sorts a list of numbers from STDIN using the built-in quicksort
    implementation
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ARRSIZE 1000000

void print_arr(int [], int);
int compare (const void *a, const void *b);

int main()
{
    int arr[ARRSIZE];
    int i = 0;

    // Generate array to sort
    /*
    srand(time(NULL));
    for (i = 0; i < ARRSIZE; i++) {
        arr[i] = rand() % 1000;
    }
    */

    while (1) {
        int num_to_sort;
        int scanf_res = scanf("%d\n", &num_to_sort);

        if (scanf_res == 0) {
            printf("Got bad input\n");
            exit(0);
        }
        else if (scanf_res == EOF) {
            break;
        }

        // Okay, got a number, now we need to put it in the array
        arr[i++] = num_to_sort;
    }

    //puts("Unsorted: ");
    //print_arr(arr, ARRSIZE);

    //printf("Sorting...\n");
    qsort(arr, ARRSIZE, sizeof(int), compare);
    print_arr(arr, ARRSIZE);

    return 0;
}

int compare (const void *a, const void *b)
{
    return *(int*)a - *(int*)b; 
}

void print_arr(int arr[], int len)
{
    int i;
    for (i = 0; i < len; i++)
        printf("%d\n", arr[i]);
    //putchar('\n');
}
