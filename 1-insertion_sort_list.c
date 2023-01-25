#include "sort.h"
#include <stdlib.h>

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order
 * @list: the doubly linked list
 * Return: the sorted list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL;
	listint_t *temp = NULL;
	listint_t *temp_prev = NULL;
	listint_t *temp_next = NULL;

	if (!list || !*list)
		return;
	current = *list;
	while (current)
	{
		temp = current;
		while (temp->prev)
		{
			if (temp->n < temp->prev->n)
			{
				temp_prev = temp->prev;
				temp_next = temp->next;
				temp_prev->prev->next = temp;
				temp->prev = temp_prev->prev;
				temp->next = temp_prev;
				temp_prev->prev = temp;
				temp_prev->next = temp_next;
				if (temp_next)
					temp_next->prev = temp_prev;
			current = temp;
			print_list(temp);
			}
			else
			{
				temp = temp->prev;
			}
		}
		if (current->prev == NULL)
			*list = current;
		current = current->next;
	}
}
