/*
    Exercise 2.3 - this is the Aha! Algorithm for rotating a vector.
    Pretty neat actually.
*/

#include <stdio.h>

void reverse(char arr[], int start, int end);
void rotate_vector(char [], int, int);

int main()
{
    char vector[] = "abcdefgh";
    int n = 8; // Length of vector
    int i = 2; // How much to shift left

    printf("Original vector: %s\n", vector);
    rotate_vector(vector, n, i);
    printf("After rotating left %d: %s\n", i, vector);

    return 0;
}

void reverse(char arr[], int start, int end)
{
    int i;
    int length = end - start + 1;
    for (i = 0; i < length/2; i++) {
        int j = end - i;
        int j_val = arr[j];

        arr[j] = arr[i + start];
        arr[i + start] = j_val;
    }
}

void rotate_vector(char vector[], int length, int shift)
{
    reverse(vector, 0, shift-1);
    reverse(vector, shift, length-1);
    reverse(vector, 0, length-1);
}
