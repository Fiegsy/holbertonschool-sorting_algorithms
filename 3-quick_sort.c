#include "sort.h"
#include <stdlib.h>

/**
 * swap - Swaps two elements in an array.
 * @array: The array.
 * @a: Index of the first element.
 * @b: Index of the second element.
 */
void swap(int *array, int a, int b)
{
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme.
 * @array: The array that will be sorted.
 * @low: Index of the smaller element.
 * @high: Index of the last element.
 * @size: Size of the array.
 * Return: Index i.
 */
size_t lomuto_partition(int *array, int low, int high, size_t size)
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
				swap(array, i, j);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		swap(array, i + 1, high);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * lomuto_sort - Recursive function to perform Quick sort.
 * @array: The array that will be sorted.
 * @low: Index of the smaller element.
 * @high: Index of the last element.
 * @size: Size of the array.
 */
void lomuto_sort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = lomuto_partition(array, low, high, size);

		lomuto_sort(array, low, pivot_index - 1, size);
		lomuto_sort(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm (Lomuto partition).
 * @array: The array that will be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, 0, size - 1, size);
}

