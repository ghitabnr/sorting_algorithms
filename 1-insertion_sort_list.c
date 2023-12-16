#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Pointer to the head of the linked list.
 * @first: First node to be swapped.
 * @second: Second node to be swapped.
 *
 * Description: This function swaps two nodes in a doubly linked list.
 */
void swap_nodes(listint_t **list, listint_t *first, listint_t *second)
{
	listint_t *first_prev, *first_next;

	first_prev = first->prev;
	first_next = first->next;

	if (first_prev)
		first_prev->next = second;
	else
		*list = second;

	if (second->next)
		second->next->prev = first;

	first->prev = second;
	first->next = second->next;
	second->prev = first_prev;
	second->next = first;

	if (first_next)
		first_next->prev = first;

	print_list(*list);
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: Pointer to the head of the linked list.
 *
 * Description: This function sorts a doubly linked list using
 * the Insertion sort algorithm.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next;

	if (!list || !*list || !(*list)->next)
		return;

	current = *list;
	next = current->next;

	while (next)
	{
		prev = current;
		current = next;
		next = next->next;

		while (prev && prev->prev && prev->prev->n > current->n)
		{
			swap_nodes(list, prev, current);
			prev = current->prev;
		}
	}
}
