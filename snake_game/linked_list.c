/*
 * linked_list.c
 *
 *  Created on: Apr 1, 2021
 *      Author: Daniel Calvo
 */

#include "linked_list.h"

/*
 * Create a new node and return its address
 */
node *newNode(int x, int y)
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
void addFirst(node **head, int x, int y)
{
    node *temp = newNode(x, y);
    temp->next = *head;
    *head = temp;
}

/*
 * Add a node at the end of a linked list
 */
void addLast(node **head, int x, int y)
{
    if (*head == NULL)
    {
        *head = newNode(x, y);
    }
    else
    {
        node *tmp = *head;

        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }

        tmp->next = newNode(x, y);
    }
}

/*
 * Display values of a linked list
 */
void readLinkedList(node *head)
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
void destroyLinkedList (node **head)
{
    if (*head == NULL)
    {
    	return;
    }

    destroyLinkedList(&((*head)->next));

    free(*head);

    *head = NULL;
}
