#include "sort.h"

/**
 * merge - merges two subarrays of int array
 * @array: array of integers
 * @size: size of the array
 * @mid: middle index
 * @temp: temporary array
 */
void merge(int *array, size_t size, int mid, int *temp)
{
	int i = 0, j = mid, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, mid);
	printf("[right]: ");
	print_array(array + mid, size - mid);

	while (i < mid && j < (int)size)
	{
		if (array[i] < array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	while (i < mid)
		temp[k++] = array[i++];
	while (j < (int)size)
		temp[k++] = array[j++];

	for (i = 0; i < (int)size; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array(temp, size);
}

/**
 * split_merge - splits int array and merges
 * @array: array of integers
 * @size: size of the array
 * @temp: temporary array
 */
void split_merge(int *array, size_t size, int *temp)
{
	int mid;

	if (size < 2)
		return;

	mid = size / 2;
	split_merge(array, mid, temp);
	split_merge(array + mid, size - mid, temp);
	merge(array, size, mid, temp);
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: array of integers to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;

	split_merge(array, size, temp);

	free(temp);
}
