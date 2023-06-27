#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: array of integers to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int i, max = 0;
	int *count_array, *output_array;

	if (!array || size < 2)
		return;

	for (i = 0; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];

	count_array = malloc(sizeof(int) * (max + 1));
	if (!count_array)
		return;

	for (i = 0; i <= max; i++)
		count_array[i] = 0;

	for (i = 0; i < (int)size; i++)
		count_array[array[i]]++;

	for (i = 1; i <= max; i++)
		count_array[i] += count_array[i - 1];

	print_array(count_array, max + 1);

	output_array = malloc(sizeof(int) * size);
	if (!output_array)
	{
		free(count_array);
		return;
	}

	for (i = 0; i < (int)size; i++)
	{
		output_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output_array[i];

	free(count_array);
	free(output_array);
}
