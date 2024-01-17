#include "sort.h"

/**
 * print_list - Prints a list of integers.
 *
 * @list: The list to be printed.
 */
void print_list(const listint_t *list)
{
    if (list == NULL)
        return;

    printf("%d", list->n);
    list = list->next;

    for (; list != NULL; list = list->next)
    {
        printf(", %d", list->n);
    }

    printf("\n");
}

