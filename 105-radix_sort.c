#include "sort.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/**
 * counting_sort_radix - Performs counting sort based on a specific significant
 * digit of the numbers in the array.
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @exp: The exponent for the significant digit (1, 10, 100, ...)
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
    int *output = malloc(sizeof(int) * size);
    int count[10] = {0};
    size_t i;

    if (!output)
        return;

    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i < SIZE_MAX; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        if (i == 0)
            break;
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the Radix sort algorithm (LSD).
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void radix_sort(int *array, size_t size)
{
    int max, exp;
    size_t i;

    if (!array || size < 2)
        return;

    max = array[0];
    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort_radix(array, size, exp);
        print_array(array, size);
    }
}
