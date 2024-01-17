#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 *
 * @a: Pointer to the first integer to swap.
 * @b: Pointer to the second integer to swap.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * hoare_partition - Partitions the array using Hoare partition scheme.
 *
 * @array: The array to be sorted.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: The size of the array.
 *
 * Return: The pivot index.
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[low + (high - low) / 2];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do
		{
			i++;
		} while (array[i] < pivot);

		do
		{
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return j;

		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * quick_sort_recursive - Recursive function to sort an array using Quick sort.
 *
 * @array: The array to be sorted.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: The size of the array.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = hoare_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_index, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using Quick sort (Hoare partition).
 *
 * @array: The array to be sorted.
 * @size: Number of elements in @array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

