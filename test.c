#include "sort.h"

/**
 * sortList - Function to sort linked list by insertion sort
 * @sort: pointer to an unsorted array
 * @nextNode: pointer to a next node in the array
 * Return: a sorted list
*/

listint_t *sortList(listint_t *sort, listint_t *nextNode) 
{
        listint_t *current;

        if (sort == NULL || sort->n >= nextNode->n)
        {
                nextNode->next = sort;
                return nextNode;
        }
        current = sort;
        while (current->next != NULL && current->next->n < nextNode->n) {
                current = current->next;
        }
    
        nextNode->next = current->next;
        current->next = nextNode;
        return sort;

}

/**
 * insertion_sort_list - sort an array using insertion sort
 * @list: pointer to the unsorted list
 * Return: void
*/

void insertion_sort_list(listint_t **list) {
        listint_t *sortedList = NULL;
        listint_t *current, *nextNode;
        
        if (list == NULL || *list == NULL) {
                return;
        }
        
        current = *list;
        while (current != NULL) {
                nextNode = current->next;
                print_list(sortedList);
                sortedList = sortList(sortedList, current);
                current = nextNode;
        }
        
        *list = sortedList;
}