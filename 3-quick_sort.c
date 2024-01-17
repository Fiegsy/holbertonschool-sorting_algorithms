#include "sort.h"
#include <stdlib.h>

/**
 * hoare_partition - Hoare partition scheme.
 * @array: The array that will be sorted.
 * @low: Index of the smaller element.
 * @high: Index of the last element.
 * @size: Size of the array.
 * Return: Index j.
 */
size_t hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[low];
	int i = low - 1, j = high + 1;

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

		/* Swap elements at i and j */
		if (array[i] != array[j])
		{
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
}

/**
 * quicksort_recursive - Recursive function to perform Quick sort.
 * @array: The array that will be sorted.
 * @low: Index of the smaller element.
 * @high: Index of the last element.
 * @size: Size of the array.
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = hoare_partition(array, low, high, size);

		quicksort_recursive(array, low, pivot_index, size);
		quicksort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm (Hoare partition).
 * @array: The array that will be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}

