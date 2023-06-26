#include <stdio.h>
#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 *
 * @list: Pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;
		while (temp->prev != NULL && temp->prev->n > temp->n)
		{
			/* Swap temp and temp->prev */
			listint_t *prev = temp->prev;
			listint_t *next = temp->next;

			if (prev->prev != NULL)
				prev->prev->next = temp;
			else
				*list = temp;
			temp->prev = prev->prev;
			temp->next = prev;
			prev->prev = temp;
			prev->next = next;
			if (next != NULL)
				next->prev = prev;
			print_list(*list);
		}
		current = current->next;
	}
}
