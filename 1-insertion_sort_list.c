#include "sort.h"

/**
 * insertion_sort_list - insertion sort algortithm
 * @list: linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = *list, *swap;

	for (; tmp != NULL; tmp = tmp->next)
	{
		if (tmp->prev != NULL && (tmp->n < tmp->prev->n))
		{
			swap = tmp;
			tmp = tmp->prev;
			
			tmp->next = swap->next;
			swap->next = tmp;
			if (tmp->next)
				tmp->next->prev = tmp;

			swap->prev = tmp->prev;
			tmp->prev = swap;
			if (swap->prev)
				swap->prev->next = swap;
		}
		printf("___________________\n");
	}
}
