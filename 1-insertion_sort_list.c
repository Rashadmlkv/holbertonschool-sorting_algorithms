#include "sort.h"

/**
 * insertion_sort_list - insertion sort algortithm
 * @list: linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = *list, *swap, *tmp2;

	for (; tmp != NULL; tmp = tmp->next)
	{
		if (tmp->prev != NULL && (tmp->n < tmp->prev->n))
		{
			swap = tmp;
			tmp = tmp->prev;
			tmp->next = swap->next;
                        if (tmp->next)
                                tmp->next->prev = tmp;

			tmp2 = tmp;
			for (; tmp2->prev && (swap->n < tmp2->n); tmp2 = tmp2->prev)
				;

			if (!tmp2->prev)
			{
				swap->prev = tmp2->prev;
				swap->next = tmp2;
				tmp2->prev = swap;
				*list = swap;
			}
			else
			{
				swap->prev = tmp2;
				swap->next = tmp2->next;
				tmp2->next = swap;
				swap->next->prev = swap;
			}
			print_list(*list);
		}
	}
}
