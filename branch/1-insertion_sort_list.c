#include <stddef.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                       using Insertion sort algorithm
 *
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current, *temp;

    current = (*list)->next;

    while (current != NULL)
    {
        temp = current->prev;
        while (temp != NULL && temp->n > current->n)
        {
            /* Swap nodes */
            if (temp->prev != NULL)
                temp->prev->next = current;
            else
                *list = current;

            if (current->next != NULL)
                current->next->prev = temp;

            temp->next = current->next;
            current->prev = temp->prev;

            current->next = temp;
            temp->prev = current;

            /* Move temp backward */
            temp = current->prev;

            /* Print the list after each swap */
            print_list(*list);
        }
        current = current->next;
    }
}
