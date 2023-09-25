#include "sort.h"

/**
 * swap_ints - two array integers swapped.
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
 * hoare_partition - subset of an array of integers ordered
 *                   according to hoare partition scheme.
 * @array: array of integers.
 * @size: array size.
 * @left: first index of subset to be ordered.
 * @right: last index of subset to be ordered.
 *
 * Return: last partition index.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - quicksort algorithm through recursion adopted.
 * @array: array of integers.
 * @size: array size.
 * @left: first index of array partition to be ordered.
 * @right: lastindex of array partition to be ordered.
 *
 * Description: Hoare partition scheme implemented.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - array of integers sorted in ascending
 *                    order using quicksort algorithm.
 * @array: array of integers.
 * @size: array size.
 *
 * Description: array printed after each swap.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
