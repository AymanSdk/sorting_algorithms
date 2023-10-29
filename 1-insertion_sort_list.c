#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @node1: A pointer to the first node to swap.
 * @node2: The second node to swap.
 * @head : head.
 * Return: void
 */
void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
		node2->prev = (*node1)->prev;
		node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list
 * @list: A pointer to the head of a doubly-linked list
 * Return: void.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insertion, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
		current = (*list)->next;
	while (current != NULL)
	{
		temp = current->next;
		insertion = current->prev;
	while (insertion != NULL && current->n < insertion->n)
	{
		swap_nodes(list, &insertion, current);
		print_list((const listint_t *)*list);
	}
	current = temp;
}
}
