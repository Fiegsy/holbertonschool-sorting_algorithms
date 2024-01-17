#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * hoare_partition - Partitions the array using Hoare partition scheme.
 * @array: Pointer to the array.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of array.
 * Return: Index of the pivot element.
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[low + (high - low) / 2];
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return (j);

        swap(&array[i], &array[j]);
        print_array(array, size);
    }
}

/**
 * quicksort_recursion - Recursive function to perform quick sort.
 * @array: Pointer to the array.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of array.
 */
void quicksort_recursion(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot_index = hoare_partition(array, low, high, size);

        quicksort_recursion(array, low, pivot_index, size);
        quicksort_recursion(array, pivot_index + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array in ascending order
 * using the Quick sort algorithm (Hoare partition).
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort_recursion(array, 0, size - 1, size);
}

