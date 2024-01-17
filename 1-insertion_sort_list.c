#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a doubly linked list.
 *
 * @list: pointer to a pointer to the head of the linked list.
 * @first: first node to swap.
 * @second: second node to swap.
 */
void swap_nodes(listint_t **list, listint_t *first, listint_t *second)
{
	if (first == NULL || second == NULL)
		return;

	if (first->prev != NULL)
		first->prev->next = second;

	if (second->next != NULL)
		second->next->prev = first;

	first->next = second->next;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;

	if (*list == first)
		*list = second;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the Insertion sort algorithm.
 *
 * @list: pointer to a pointer to the head of the linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL;
	listint_t *previous = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		previous = current->prev;

		while (previous != NULL && previous->n > current->n)
		{
			swap_nodes(list, previous, current);
			print_list(*list);
			previous = current->prev;
		}

		current = current->next;
	}
}

