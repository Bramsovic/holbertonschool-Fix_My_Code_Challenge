#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current;
    unsigned int p;

    if (head == NULL || *head == NULL)
        return (-1);

    current = *head;
    p = 0;

    /* Avancer jusqu'à l'index */
    while (p < index && current != NULL)
    {
        current = current->next;
        p++;
    }

    /* Vérifier si l'index est valide */
    if (current == NULL)
        return (-1);

    /* Suppression du premier élément */
    if (index == 0)
    {
        *head = current->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(current);
    }
    /* Suppression d'un élément au milieu ou à la fin */
    else
    {
        if (current->prev)
            current->prev->next = current->next;
        if (current->next)
            current->next->prev = current->prev;
        free(current);
    }

    return (1);
}
