#include "sort.h"

/**
 * heap_swap - swaps two elements in an array
 * @array: array of integers
 * @i: first index to swap
 * @j: second index to swap
 * @size: size of the array
 */
void heap_swap(int *array, int i, int j, size_t size)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
	print_array(array, size);
}
/**
 * sift_down - repairs the heap whose root element is at index 'start'
 * @array: array of integers
 * @start: root index
 * @end: last index of the heap
 * @size: size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	size_t child;
	size_t swap_index;

	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;
		swap_index = root;

		if (array[swap_index] < array[child])
			swap_index = child;

		if (child + 1 <= end && array[swap_index] < array[child + 1])
			swap_index = child + 1;

		if (swap_index == root)
			return;

		heap_swap(array, root, swap_index, size);
		root = swap_index;
	}
}

/**
 * heapify - orders elements in an array representing a heap
 * @array: array of integers
 * @size: size of the array
 */
void heapify(int *array, size_t size)
{
	int start = (size - 2) / 2;

	while (start >= 0)
	{
		sift_down(array, start, size - 1, size);
		start--;
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: array of integers to sort
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int end = size - 1;

	if (!array || size < 2)
		return;

	heapify(array, size);

	while (end > 0)
	{
		heap_swap(array, end, 0, size);
		end--;
		sift_down(array, 0, end, size);
	}
}
