#include <stddef.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		temp = current;
		prev = current->prev;

		while (prev && temp->n < prev->n)
		{
			if (temp->next)
				temp->next->prev = prev;

			prev->next = temp->next;
			temp->prev = prev->prev;

			if (prev->prev)
				prev->prev->next = temp;
			else
				*list = temp;

			prev->prev = temp;
			temp->next = prev;

			print_list(*list);

			prev = temp->prev;
		}

		current = current->next;
	}
}
