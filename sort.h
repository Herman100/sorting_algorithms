#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
/**
 * struct listint_s - Doubly linked list node structure
 * @n: Integer value stored in the node
 * @prev: Pointer to the previous element in the list
 * @next: Pointer to the next element in the list
 *
 * Description: Node structure for a doubly linked list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Function prototypes */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap(int *a, int *b, int *array, size_t size);
int partition(int *array, int low, int high, size_t size);
void quicksort(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
int swap_check(listint_t **list, listint_t **node1, listint_t **node2);
void counting_sort(int *array, size_t size);
void populate_output_array(int *array, int *output_array,
		int *count_array, size_t size);
void init_count_array(int *count_array, int max);
void merge(int *array, size_t size, int mid, int *temp);
void split_merge(int *array, size_t size, int *temp);
void merge_sort(int *array, size_t size);
void heap_swap(int *array, int i, int j, size_t size);
void sift_down(int *array, size_t start, size_t end, size_t size);
void heapify(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void radix_counting_sort(int *array, size_t size, int exp, int *output);








#endif /* SORT_H */
