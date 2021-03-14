/*
    Exercise 2.3 - I basically took the swap algorithm and iterative-ified
    it.

    It's been a while since I wrote this, but I remember thinking "I suddenly
    understand how tail recursion works now"
*/

#include <stdio.h>

void rotate_vector(char [], int, int);

int main()
{
    char vector[] = "abcdefgh";
    int n = 8; // Length of vector
    int i = 3; // How much to shift left

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

    int a, b; // Length of first and second half that we need to swap

    // Basically, I took my recursive solution and made it iterative. We keep
    // running the swap+rotate functions until the two chunks are the same
    // size. Since the recursive calls always happen at the end of this
    // function, we can transform that into a loop with changing variables.
    //
    // ...and I think I finally understand "tail recursion" and why people say
    // that it's easily transformed into a non-recursive algorithm.
    do {
        a = shift;
        b = length - a;

        if (b > a) {
            swap(vector, 0, b, a);
            length = b; 
            shift = a;
        }
        else if (a > b) {
            swap(vector, a-b, a, b);
            length = a;
            shift = a - b;
        }
    } while (a != b);

    swap(vector, 0, shift, shift);
}

/*
    The way the book describes this is different. I'm always swapping so the
    rightmost values are put in place, but the book always makes the "outer"
    values in place, so it keeps moving inward more.

    I think these end up being similar runtimes because in each iteration,
    we're always putting the same number of values in the right place.
*/
