#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending
 * order using the Counting sort algorithm
 *
 * @array: pointer to array
 * @size: size of the array
 **/
void counting_sort(int *array, size_t size)
{
    int n; /* Maximum element in the array */
    int j; /* Loop counter */
    int *count_array; /* Counting array */
    int *aux; /* Auxiliary array */
    size_t i; /* Loop counter */

    if (!array || size < 2)
        return;

    /* Find the maximum element in the array to determine the size of the counting array */
    n = array[0];
    for (i = 0; i < size; i++)
    {
        if (array[i] > n)
            n = array[i];
    }

    /* Create a counting array of size n + 1 and initialize it with zeros */
    count_array = (int *)calloc((n + 1), sizeof(int));

    /* Populate the counting array with the count of each element */
    for (i = 0; i < size; i++)
    {
        count_array[array[i]]++;
    }

    /* Modify the counting array to contain the correct positions of each element in the sorted order */
    for (j = 1; j < n; j++)
    {
        count_array[j + 1] += count_array[j];
    }

    /* Print the counting array */
    print_array(count_array, n + 1);

    /* Allocate an auxiliary array to store the sorted elements */
    aux = (int *)malloc(sizeof(int) * size);

    /* Build the auxiliary array using the counting array */
    for (i = 0; i < size; i++)
    {
        count_array[array[i]]--;
        aux[count_array[array[i]]] = array[i];
    }

    /* Copy the sorted elements back to the original array */
    for (i = 0; i < size; i++)
    {
        array[i] = aux[i];
    }

    /* Free the dynamically allocated memory */
    free(aux);
    free(count_array);
}
