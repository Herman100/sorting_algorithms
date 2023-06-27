#include "sort.h"

/**
 * cocktail_sort_list - sorts a dll using cocktail sort
 * @list: head of doubly linked list to be sorted
 *
 * Return: void
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *current_node, *next_node;
	int status, swap_counter;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (1)
	{
		current_node = *list;
		next_node = current_node->next;
		swap_counter = 0;
		while (next_node != NULL)
		{
			status = swap_check(list, &current_node, &next_node);
			swap_counter += status;
			current_node = current_node->next;
			next_node = current_node->next;
		}
		if (swap_counter == 0)
			break;

		swap_counter = 0;
		current_node = current_node->prev->prev;
		next_node = current_node->next;
		while (current_node != NULL)
		{
			status = swap_check(list, &current_node, &next_node);
			swap_counter += status;
			if (next_node != current_node)
				next_node = current_node;
			current_node = current_node->prev;
		}
		if (swap_counter == 0)
			break;
	}
}


/**
 * swap_check - A function that compares if node1 int
 * is greater than node2 int and then swaps them
 * @list: list head of a doubly linkedlst
 * @node1: doubly linked list node 1
 * @node2: doubly linked list node
 *
 * Return: 1 if true, 0 if false
*/
int swap_check(listint_t **list, listint_t **node1, listint_t **node2)
{
	if (node1 == NULL || node2 == NULL)
		return (0);

	if ((*node1)->n > (*node2)->n)
	{
		if ((*node1)->prev != NULL)
			(*node1)->prev->next = (*node2);
		(*node2)->prev = (*node1)->prev;
		(*node1)->next = (*node2)->next;

		if ((*node2)->next != NULL)
			(*node2)->next->prev = (*node1);

		(*node1)->prev = (*node2);
		(*node2)->next = (*node1);

		if ((*node2)->prev == NULL)
		{
			*list = *node2;
		}

		(*node1) = (*node2);
		print_list(*list);

		return (1);
	}

	return (0);
}
