#ifndef SORT_H
#define SORT_H

#include <stdlib.h>

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







#endif /* SORT_H */