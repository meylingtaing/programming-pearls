/*
    Exercise 2.3 - recursive implementation of the swapping vector rotation
    algorithm.
*/

#include <stdio.h>

void rotate_vector(char [], int, int);

int main()
{
    char vector[] = "abcdefghi";
    int n = 9; // Length of vector
    int i = 6; // How much to shift left

    printf("Original vector: %s\n", vector);
    rotate_vector(vector, n, i);
    printf("After rotating left %d: %s\n", i, vector);

    return 0;
}

/*
    Swap two chunks in a vector
    arr: the array
    index_a: the starting index of the first chunk
    index_b: the starting index of the second chunk
    chunk_size: the size of each chunk
*/
void swap(char arr[], int index_a, int index_b, int chunk_size) {
    int i;
    for (i = 0; i < chunk_size; i++) {
        int val_a = arr[index_a + i];
        arr[index_a + i] = arr[index_b + i];
        arr[index_b + i] = val_a;
    }
}

/*
    Rotate a vector left
    vector: the array
    length: the length of the array
    shift: the amount to rotate left
*/
void rotate_vector(char vector[], int length, int shift)
{
    if (shift == 0 || shift == length) return;

    int a = shift;      // Length of first half
    int b = length - a; // Length of second half

    // If the second half is larger than the first, split up the second half
    // into left and right chunks. Chunk A gets swapped with Chunk B-right
    //
    // Then chunk A is in place and we need to swap Chunk B-right and
    // Chunk B-left
    if (b > a) {
        swap(vector, 0, b, a);
        rotate_vector(vector, b, a);
    }

    // If the second half is smaller than the first, split up the first half
    // into left and right chunks. Swap Chunk A-right with Chunk B
    //
    // Then chunk B is in place, but chunk A-left and A-right need to be
    // swapped
    else if (a > b) {
        swap(vector, a-b, a, b);
        rotate_vector(vector, a, a-b);
    }

    // And if they're the same size, swap em and you're done
    else {
        swap(vector, 0, shift, shift);
    }
}
