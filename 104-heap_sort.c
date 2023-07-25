#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * sift_down - Performs the sift-down operation on a subtree
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @root: The root index of the subtree
 * @size_init: The original size of the array
 */
void sift_down(int *array, size_t size, size_t root, size_t size_init)
{
    size_t max_child, left_child, i;

    for (i = root; (left_child = 2 * i + 1) < size; i = max_child)
    {
        max_child = left_child;

        if (left_child + 1 < size && array[left_child + 1] > array[max_child])
            max_child++;

        if (array[i] >= array[max_child])
            break;

        swap(&array[i], &array[max_child]);
        print_array(array, size_init);
    }
}

/**
 * heapify - Builds a max heap from the array
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void heapify(int *array, size_t size)
{
    ssize_t i;

    for (i = (size / 2) - 1; i >= 0; i--)
        sift_down(array, size, (size_t)i, size);
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
    size_t i;

    if (array == NULL || size < 2)
        return;

    heapify(array, size);

    for (i = size - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        print_array(array, size);
        sift_down(array, i, 0, size);
    }
}
