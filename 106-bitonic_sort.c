#include "sort.h"

/**
 * swap_ints - Two array integers sorted.
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
 * bitonic_merge - bitonic sequence inside an array of integers sorted.
 * @array: array of integers.
 * @size: array size.
 * @start: first index of sequence to sort.
 * @seq: sequence size to sort.
 * @flow: direction to sort .
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
			    (flow == DOWN && array[i] < array[i + jump]))
				swap_ints(array + i, array + i + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - array of integers converted into a bitonic sequence.
 * @array: array of integers.
 * @size: array size.
 * @start: first index of block of building bitonic sequence.
 * @seq: size of block of building bitonic sequence.
 * @flow: direction to sort bitonic sequence block .
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - array of integers sorted in ascending
 *                order using bitonic sort algorithm.
 * @array: array of integers.
 * @size: array size.
 *
 * Description: array printed after each swap.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
