#include "sort.h"

/**
 * swap_ints - Two array integers swapped.
 * @a: first integer to be swapped.
 * @b: second integer to be swapped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - subset of an array of integers ordered according to
 *                    lomuto partition scheme.
 * @array: array of integers.
 * @size: array size.
 * @left: first index of subset to be ordered.
 * @right: last index of subset to be ordered.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - quicksort algorithm through recursion used.
 * @array: array of integers to be sorted.
 * @size: array size.
 * @left: first index of array partition to be ordered.
 * @right: last index of array partition to be ordered.
 *
 * Description: Lomuto partition scheme implemented.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - array of integers sorted in ascending
 *              order using quicksort algorithm.
 * @array: array of integers.
 * @size: array size.
 *
 * Description: array printed after each swap.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
