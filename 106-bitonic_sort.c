#include "sort.h"

/**
 * bitonic_sort - sorts an array of integers in ascending order using the
 * Bitonic sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	bitonic_sort_recursive(array, 0, size, true);
}

/**
 * bitonic_sort_recursive - recursive function to sort using bitonic sort
 * @array: array to sort
 * @low: low index of the sub-array to sort
 * @count: size of the sub-array to sort
 * @dir: direction to sort in (true for ascending, false for descending)
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, bool dir)
{
	size_t k = count / 2;
	size_t i;
	char *str_dir = dir ? "UP" : "DOWN";

	if (count < 2)
		return;

	printf("Merging [%lu/%lu] (%s):\n", count, k, str_dir);
	print_array(array + low, count);

	for (i = low; i < low + k; i++)
		bitonic_compare(array, i, i + k, dir);

	bitonic_sort_recursive(array, low, k, dir);
	bitonic_sort_recursive(array, low + k, k, dir);

	printf("Result [%lu/%lu] (%s):\n", count, k, str_dir);
	print_array(array + low, count);
}

/**
 * bitonic_compare - compare and swap elements based on direction
 * @array: array to sort
 * @i: first index to compare
 * @j: second index to compare
 * @dir: direction to sort in (true for ascending, false for descending)
 */
void bitonic_compare(int *array, size_t i, size_t j, bool dir)
{
	int temp;

	if (dir == (array[i] > array[j]))
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}
