#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a linked list
 * @head: Pointer to the head of the list
 * @node1: First node to be swapped
 * @node2: Second node to be swapped
 */
void swap_nodes(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t *prev_node1, *next_node2;

	prev_node1 = node1->prev;
	next_node2 = node2->next;

	if (prev_node1 != NULL)
		prev_node1->next = node2;
	else
		*head = node2;
	node1->prev = node2;
	node1->next = next_node2;
	node2->prev = prev_node1;
	node2->next = node1;
	if (next_node2)
		next_node2->prev = node1;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using the cocktail sort algorithm
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int sorted = 0;

	if (!list || !*list || !(*list)->next)
		return;

	do {
		sorted = 0;
		for (current = *list; current->next != NULL; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				sorted = 1;
				current = current->prev;
			}
		}
		if (!sorted)
			break;
		sorted = 0;
		for (; current->prev != NULL; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				print_list(*list);
				sorted = 1;
				current = current->next;
			}
		}
	} while (sorted);
}
