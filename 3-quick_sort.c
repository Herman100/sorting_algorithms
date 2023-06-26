#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers
 *
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 * @array: The array being sorted
 * @size: Number of elements in the array
 *
 * Description: This function swaps the values of two integers and prints the
 * updated array after the swap.
 */
void swap(int *a, int *b, int *array, size_t size)
{
	if (*a != *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
		print_array(array, size);
	}
}

/**
 * partition - Partitions the array using Lomuto partition scheme
 *
 * @array: The array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 *
 * Return: Index of the pivot element
 *
 * Description: This function takes the last element of the array as the pivot
 * and rearranges the elements such that all elements smaller than the pivot
 * are moved to the left of it and all elements greater than the pivot are
 * moved to the right of it. It returns the index of the pivot element.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j], array, size);
		}
	}
	swap(&array[i + 1], &array[high], array, size);
	return (i + 1);
}

/**
 * quicksort - Recursive function to sort the array using Quick sort algorithm
 *
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 *
 * Description: This function recursively sorts the array using the Quick sort
 * algorithm. It selects a pivot element,
 * partitions the array around the pivot,
 * and applies the same process to the sub-arrays.
 */
void quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = partition(array, low, high, size);

		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in
 * ascending order using the Quick sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 * Description: This function sorts the array of integers in ascending order
 * using the Quick sort algorithm. It performs an initial check on the input
 * array and then calls the recursive quicksort
 * function to perform the sorting.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
