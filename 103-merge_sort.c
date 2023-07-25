#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
    size_t mid;
    int *left, *right;
    size_t left_size, right_size;
    int *merged;
    size_t i, j, k;

    /* Base case: If the array has less than 2 elements, it is already sorted */
    if (size < 2)
        return;

    /* Calculate the middle index to divide the array into two sub-arrays */
    mid = size / 2;

    /* Create left and right sub-arrays */
    left = array;
    left_size = mid;

    right = array + mid;
    right_size = size - mid;

    /* Recursively sort the left and right sub-arrays */
    merge_sort(left, left_size);
    merge_sort(right, right_size);

    /* Merge the sorted left and right sub-arrays */
    merged = malloc(size * sizeof(int));
    if (!merged)
    {
        fprintf(stderr, "Memory allocation error\n");
        return;
    }

    printf("Merging...\n[left]: ");
    for (i = 0; i < left_size; i++)
    {
        printf("%d", left[i]);
        if (i != left_size - 1)
            printf(", ");
    }

    printf("\n[right]: ");
    for (i = 0; i < right_size; i++)
    {
        printf("%d", right[i]);
        if (i != right_size - 1)
            printf(", ");
    }
    printf("\n");

    i = j = k = 0;

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
            merged[k++] = left[i++];
        else
            merged[k++] = right[j++];
    }

    while (i < left_size)
        merged[k++] = left[i++];

    while (j < right_size)
        merged[k++] = right[j++];

    /* Copy the merged array back to the original array */
    for (i = 0; i < size; i++)
        array[i] = merged[i];

    /* Print the merged array */
    printf("[Done]: ");
    for (i = 0; i < size; i++)
    {
        printf("%d", array[i]);
        if (i != size - 1)
            printf(", ");
    }
    printf("\n");

    /* Free the dynamically allocated memory */
    free(merged);
}
