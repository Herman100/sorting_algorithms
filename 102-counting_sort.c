#include "sort.h"

/**
 * init_count_array - initializes the count_array
 * @count_array: array to initialize
 * @max: size of the count_array
 */
void init_count_array(int *count_array, int max)
{
	int i;

	for (i = 0; i <= max; i++)
		count_array[i] = 0;
}

/**
 * populate_output_array - populates the output_array
 * @array: input array
 * @output_array: array to populate
 * @count_array: count array
 * @size: size of the input and output arrays
 */
void populate_output_array(int *array, int *output_array,
		int *count_array, size_t size)
{
	int i;

	for (i = 0; i < (int)size; i++)
	{
		output_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}
}

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

	init_count_array(count_array, max);

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

	populate_output_array(array, output_array, count_array, size);

	for (i = 0; i < (int)size; i++)
		array[i] = output_array[i];

	free(count_array);
	free(output_array);
}
