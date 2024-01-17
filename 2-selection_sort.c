#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min_indx;

	for (i = 0; i < size - 1; i++)
	{
		min_indx = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_indx])
				min_indx = j;
		}

		if (min_indx != i)
		{
			swap(&array[min_indx], &array[i]);
			print_array(array, size);
		}
	}
}

/**
 * swap - swaps two integers
 * @xp: pointer to first integer
 * @yp: pointer to second integer
 * Return: void
 */

void swap(int *xp, int *yp)
{
	int temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}
