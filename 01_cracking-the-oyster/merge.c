/*
    Merge sort implementation
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ARRSIZE 25

void print_arr(int [], int);
void merge_sort(int [], int);

int main()
{
    int arr[ARRSIZE];
    int i;

    srand(time(NULL));
    for (i = 0; i < ARRSIZE; i++) {
        arr[i] = rand() % 1000;
    }

    puts("Unsorted: ");
    print_arr(arr, ARRSIZE);

    printf("Sorting...\n");
    merge_sort(arr, ARRSIZE);
    print_arr(arr, ARRSIZE);

    return 0;
}

void merge_sort(int arr[], int len)
{
    if (len > 1) {
        int mid = (1+len)/2;
        int arr1[mid], arr2[len-mid];

        // Make temp arrays
        for (int i = 0; i < mid; i++)
            arr1[i] = arr[i];
        for (int i = 0; i < (len-mid); i++)
            arr2[i] = arr[i+mid];

        merge_sort(arr1, mid);
        merge_sort(arr2, len-mid);

        // Merge the two arrays together
        int i = 0, j = 0;
        for (int n = 0; n < len; n++) {
            if (i < mid && j < len-mid) {
                if (arr1[i] < arr2[j])
                    arr[n] = arr1[i++];
                else
                    arr[n] = arr2[j++];
            }
            else {
                if (j >= len-mid)
                    arr[n] = arr1[i++];
                else
                    arr[n] = arr2[j++];
            }
        }
    }
}

void print_arr(int arr[], int len)
{
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    putchar('\n');
}
