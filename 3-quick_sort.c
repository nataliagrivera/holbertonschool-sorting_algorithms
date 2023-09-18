#include "sort.h"
#include <stddef.h>
/**
 * lomuto_partition - Lomuto partition scheme
 * @array: array to take in
 * @start: start of array;
 * @end: end of array
 * @size: full size of array
 * Return: position of pivot
 */
int lomuto_partition(int *array, int start, int end, int size)
{
	int pivot = array[end];
	int i = start - 1;
	int j;
	int temp;

	for (j = start; j <= end - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[end])
	{
		temp = array[i + 1];
		array[i + 1] = array[end];
		array[end] = temp;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_helper - quick sorting with recursion
 * @array: to sort through
 * @low: start
 * @high: end
 * @size: of full array
 *
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int piv;

		if (low < high)
		{
			piv = lomuto_partition(array, low, high, size);
			quick_sort_helper(array, low, piv - 1, size);
			quick_sort_helper(array, piv + 1, high, size);
		}
}

/**
 * quick_sort - of an array
 * @array: to sort
 * @size: of an array
 *
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	quick_sort_helper(array, 0, size - 1, size);
}
