#include "sort.h"


/**
 * radix_counting_sort - Sorts an array of integers using the
 * Counting sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @exp: The current exponent
 * @output: The output array for storing sorted elements
 *
 * Description: This function implements the Counting sort algorithm to sort
 * an array of integers in non-decreasing order. It uses a counting array to
 * count the occurrences of each element, and then modifies the counting array
 * to store the position of each element in the sorted order. Finally, it
 * rearranges the elements in the output array based on the counting array.
 */

void radix_counting_sort(int *array, size_t size, int exp, int *output)
{
	int count[10] = {0};
	size_t j;

	for (j = 0; j < size; j++)
		count[(array[j] / exp) % 10]++;

	for (j = 1; j < 10; j++)
		count[j] += count[j - 1];

	for (j = size - 1; (int)j >= 0; j--)
	{
		output[count[(array[j] / exp) % 10] - 1] = array[j];
		count[(array[j] / exp) % 10]--;
	}

	for (j = 0; j < size; j++)
		array[j] = output[j];
}


/**
 * radix_sort - Sorts an array of integers in
 * ascending order using Radix sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */

void radix_sort(int *array, size_t size)
{
	size_t i;
	int max = array[0];
	int *output = malloc(sizeof(int) * size);
	int exp;

	if (array == NULL || size < 2)
		return;

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	if (output == NULL)
		return;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		radix_counting_sort(array, size, exp, output);
		print_array(array, size);
	}

	free(output);
}

