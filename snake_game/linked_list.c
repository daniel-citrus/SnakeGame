/*
 * linked_list.c
 *
 *  Created on: Apr 1, 2021
 *      Author: Daniel Calvo
 */


#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

// Create a new node and return its address
node *newNode(int num)
{
    node *ptr = malloc(sizeof(node));

    ptr->i = num;
    ptr->next = NULL;

    return ptr;
}


// Add a node at the beginning of a linked list, returns the new head
void addFirst(node **head, int num)
{
    node *temp = newNode(num);
    temp->next = *head;
    *head = temp;
}

// Add a node at the end of a linked list
void addLast(node **head, int num)
{
    if (*head == NULL)
    {
        *head = newNode(num);
    }
    else
    {
        node *tmp = *head;

        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }

        tmp->next = newNode(num);
    }
}

// Display values of a linked list
void readLinkedList(node *head)
{
	if (head == NULL)
	{
		printf("There is no linked list.\n");
		return;
	}

    for (node *ptr = head; ptr != NULL; ptr = ptr->next)
    {
        printf("%d", ptr->i);
        printf(" -> ");
    }

    printf("NULL\n");
}

// Delete the first instance of num in a linked list
void deleteNode(node **head, int num)
{
    if(head == NULL)
    {
        printf("Linked List is empty.\n");

        return;
    }

    node *h = *head;

    // First node is a match
    if (h->i == num)
    {
    	deleteFirstNode(head);

        return;
    }
    // Search the rest of the linked list
    else
    {
        node *before = h;
        node *temp = before->next;

        while (temp != NULL)
        {
            if (temp->i == num)
            {
                before->next = temp->next;
                free(temp);

                return;
            }
            else
            {
            	before = temp;
            	temp = temp->next;
            }
        }
    }

    printf("Value does not exist in the Linked List.\n");
}

// Delete the first node of a linked list
void deleteFirstNode(node **head)
{
    node *temp = *head;
    *head = temp->next;
    free(temp);
}

// Free a linked list
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
