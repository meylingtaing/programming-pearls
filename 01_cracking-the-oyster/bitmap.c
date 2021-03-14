/*
    Reads a list of numbers from STDIN and outputs the numbers sorted.
*/

#include <stdio.h>
#include <limits.h>

#define MAXSIZE 10000000

//void print_arr(unsigned char arr[], int len);

int main()
{
    int i;

    // Figure out how large this array needs to be to hold the full bitmap
    int index_size = CHAR_BIT;
    int arrlen     = MAXSIZE / index_size + 1;

    // Also, keep track of the max index so we're not reading more than
    // we need to
    int max_index  = 0;

    // Create the array and set all the bits to 0
    unsigned char arr[arrlen];
    for (i = 0; i < arrlen; i++)
        arr[i] = 0;

    // Read ints from STDIN
    while (1) {
        int num_to_sort;
        int scanf_res = scanf("%d\n", &num_to_sort);

        if (scanf_res == 0) {
            fprintf(stderr, "Got bad input\n");
            return 1;
        }
        else if (scanf_res == EOF) {
            break;
        }
        else if (num_to_sort >= MAXSIZE || num_to_sort < 0) {
            fprintf(stderr, "%d is not in range\n", num_to_sort);
        }

        // Okay, got a number, now we need to put it in the array
        int arr_index = num_to_sort >> 3;
        int bit       = num_to_sort & 7;

        if (arr[arr_index] & (1 << bit)) {
            fprintf(stderr, "%d appears twice\n", num_to_sort);
            return 1;
        }
        arr[arr_index] |= (1 << bit);

        if (arr_index > max_index)
            max_index = arr_index;
    }

    // For debugging purposes...
    //printf("Bitmap:\n");
    //print_arr(arr, max_index + 1);

    // Now, get the sorted array and print it
    i = 0;
    int index_to_check = 0;
    unsigned char num_to_check = 1;

    while (i < MAXSIZE && index_to_check <= max_index) {
        if (num_to_check & arr[index_to_check]) {
            printf("%d\n", i);
        }

        i++;
        num_to_check = num_to_check << 1;
        if (num_to_check == 0) {
            index_to_check++;
            num_to_check = 1;
        }
    }

    return 0;
}

/*
void print_arr(unsigned char arr[], int len)
{
    int i;
    for (i = 0; i < len; i++)
        printf("%u ", arr[i]);
    putchar('\n');
}
//*/
