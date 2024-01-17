#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 *
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
 * lomuto_partition - Partitions the array using Lomuto partition scheme.
 *
 * @array: Pointer to the array.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of array.
 *
 * Return: Index of the pivot element.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            if (i != j)
            {
                swap(&array[i], &array[j]);
                print_array(array, size);
            }
        }
    }

    if (array[i + 1] != array[high])
    {
        swap(&array[i + 1], &array[high]);
        print_array(array, size);
    }

    return i + 1;
}

/**
 * quicksort_recursion - Recursive function to perform quick sort.
 *
 * @array: Pointer to the array.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of array.
 */
void quicksort_recursion(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot_index = lomuto_partition(array, low, high, size);

        quicksort_recursion(array, low, pivot_index - 1, size);
        quicksort_recursion(array, pivot_index + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array in ascending order
 * using the Quick sort algorithm (Lomuto partition).
 *
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort_recursion(array, 0, size - 1, size);
}

