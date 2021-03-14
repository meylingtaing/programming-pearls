/*
    Exercise 2.3
*/

#include <stdio.h>

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

void rotate_vector(char vector[], int length, int shift)
{
    // We might end up hitting the same number while juggling, so we have to
    // do several iterations of this
    int curr_start_index = 0;

    int curr_index = 0;
    int curr_value = vector[curr_index];
    //fprintf(stderr, "\tCurr_value %c\n", curr_value);

    int i;
    for (i = 0; i < length; i++) {
        // Determine new location of curr_index
        int next_index = curr_index - shift;
        if (next_index < 0) next_index = length + next_index;
        //fprintf(stderr, "\tNew index %d\n", next_index);

        // Save value at that location
        char next_value = vector[next_index];
        //fprintf(stderr, "\tNext value %c\n", next_value);
        vector[next_index] = curr_value;
        //fprintf(stderr, "\tSaved the new value?\n");

        // And set up for the next iteration. If we come across an index we've
        // already hit, then move over one.
        if (next_index == curr_start_index) {
            curr_start_index = curr_index = next_index + 1;
            curr_value = vector[curr_index];
        }
        else {
            curr_index = next_index;
            curr_value = next_value;
        }
    }
}
