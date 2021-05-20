/*
 * linked_list.c
 *
 *  Created on: Apr 1, 2021
 *      Author: Daniel Calvo
 */

#include "../headers/linked_list.h"

/*
 * Create a new node and return its address
 */
node *new_node(int x, int y)
{
    node *ptr = malloc(sizeof(node));

    ptr->x = x;
    ptr->y = y;
    ptr->next = NULL;

    return ptr;
}

/*
 * Add a node at the beginning of a linked list
 */
void add_first(node **head, int x, int y)
{
    node *temp = new_node(x, y);
    temp->next = *head;
    *head = temp;
}

/*
 * Add a node at the end of a linked list
 */
void add_last(node **head, int x, int y)
{
    if (*head == NULL)
    {
        *head = new_node(x, y);
    }
    else
    {
        node *tmp = *head;

        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }

        tmp->next = new_node(x, y);
    }
}

/*
 * Display values of a linked list
 */
void read_linked_list(node *head)
{
    if (head == NULL)
    {
        printf("There is no linked list.\n");
        return;
    }

    for (node *ptr = head; ptr != NULL; ptr = ptr->next)
    {
        printf("(%d, %d)", ptr->x, ptr->y);
        printf(" -> ");
    }

    printf("NULL\n");
}

/*
 * Delete the first node of a linked list
 */
void deleteFirstNode(node **head)
{
    node *temp = *head;
    *head = temp->next;
    free(temp);
}

/*
 * Free a linked list
 */
void destroy_linked_list (node **head)
{
    if (*head == NULL)
    {
        return;
    }

    destroy_linked_list(&((*head)->next));

    free(*head);

    *head = NULL;
}
