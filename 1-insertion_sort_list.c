#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort algorithm
 *
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *temp, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	while (curr != NULL)
	{
		temp = curr->next;
		prev = curr->prev;

		while (prev != NULL && prev->n > curr->n)
		{
			prev->next = curr->next;

			if (curr->next != NULL)
				curr->next->prev = prev;

			curr->next = prev;
			curr->prev = prev->prev;
			prev->prev = curr;

			if (curr->prev != NULL)
				curr->prev->next = curr;
			else
				*list = curr;

			print_list(*list);
			prev = curr->prev;
		}
		curr = temp;
	}
}
