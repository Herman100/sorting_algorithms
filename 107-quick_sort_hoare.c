#include "sort.h"

/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 */
void hoare_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * hoare_partition - partitions an array using the Hoare partition scheme
 * @array: array to partition
 * @size: size of the array
 * @low: low index of the sub-array to partition
 * @high: high index of the sub-array to partition
 *
 * Return: index of the pivot
 */
int hoare_partition(int *array, size_t size, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int j = high + 1;

    while (true)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return (j);

        hoare_swap(&array[i], &array[j]);
        print_array(array, size);
    }
}

/**
 * quick_sort_hoare_recursive - recursive function to sort using quick sort
 * @array: array to sort
 * @size: size of the array
 * @low: low index of the sub-array to sort
 * @high: high index of the sub-array to sort
 */
void quick_sort_hoare_recursive(int *array, size_t size, int low, int high)
{
    if (low < high)
    {
        int pivot = hoare_partition(array, size, low, high);
        quick_sort_hoare_recursive(array, size, low, pivot);
        quick_sort_hoare_recursive(array, size, pivot + 1, high);
    }
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending order using the
 * Quick sort algorithm with the Hoare partition scheme
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quick_sort_hoare_recursive(array, size, 0, size - 1);
}

