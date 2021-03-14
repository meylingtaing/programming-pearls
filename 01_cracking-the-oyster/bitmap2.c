/*
    A two-pass algo for the bitmap sort
*/

#include <stdio.h>
#include <limits.h>

#define MAXSIZE 10000000
#define index_size CHAR_BIT

void print_arr(unsigned char arr[], int len);
int  insert_into_bitmap(char *filename, unsigned char arr[], int min, int max);
void print_sorted_bitmap(unsigned char arr[], int min, int max);

int main(int argc, char *argv[])
{
    // 1. Get the file that we're reading from
    if (argc != 2) {
        printf("Usage: %s input_file.txt\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];

    // 2. Figure out how large this array needs to be to hold the half bitmap
    int first_half_max = MAXSIZE / 2;
    int arrlen         = first_half_max / index_size + 1;

    // Also, keep track of the max index so we're not reading more than
    // we need to
    //int max_index  = 0;

    // 3. Create the bitmap array and set all the bits to 0
    // XXX See if changing this to static makes a difference
    unsigned char arr[arrlen];
    int i;

    for (i = 0; i < arrlen; i++)
        arr[i] = 0;

    // Sort the first half
    int insert_res = 0;
    insert_res = insert_into_bitmap(filename, arr, 0, first_half_max);
    if (insert_res)
        return 1;
    print_sorted_bitmap(arr, 0, first_half_max);

    // For debugging purposes...
    //printf("Bitmap:\n");
    //print_arr(arr, arrlen);

    // And reset the array and sort the second
    for (i = 0; i < arrlen; i++)
        arr[i] = 0;

    insert_res = insert_into_bitmap(filename, arr, first_half_max, MAXSIZE);
    if (insert_res)
        return 1;
    print_sorted_bitmap(arr, first_half_max, MAXSIZE);

    // For debugging purposes...
    //printf("Bitmap:\n");
    //print_arr(arr, arrlen);

    return 0;
}

int insert_into_bitmap(char *filename, unsigned char arr[], int min, int max)
{
    int len = max - min;
    FILE *fp = fopen(filename, "r");

    while (1) {
        int num_to_sort;
        int scanf_res = fscanf(fp, "%d\n", &num_to_sort);

        if (scanf_res == 0) {
            printf("Got bad input\n");
            return 1;
        }
        else if (scanf_res == EOF) {
            break;
        }

        // Okay, got a number, now we need to put it in the array
        if (num_to_sort >= min && num_to_sort < max) {
            num_to_sort -= min;

            int arr_index = num_to_sort >> 3;
            int bit       = num_to_sort & 7;

            if (arr_index >= len)
                arr_index = arr_index >> len;

            arr[arr_index] |= (1 << bit);
        }
    }
    fclose(fp);
    return 0;
}

void print_sorted_bitmap(unsigned char arr[], int min, int max)
{
    int i = 0;
    int len = max - min;
    int index_to_check = 0;
    unsigned char num_to_check = 1;

    while (i < len) {
        if (num_to_check & arr[index_to_check]) {
            printf("%d\n", i + min);
        }

        i++;
        num_to_check = num_to_check << 1;
        if (num_to_check == 0) {
            index_to_check++;
            num_to_check = 1;
        }
    }
}

//*
void print_arr(unsigned char arr[], int len)
{
    int i;
    for (i = 0; i < len; i++)
        printf("%u ", arr[i]);
    putchar('\n');
}
//*/
