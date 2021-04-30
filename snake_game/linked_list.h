/*
 * linked_list.h
 *
 *  Created on: Apr 6, 2021
 *      Author: Daniel Calvo
 *
 *	Description: Function declarations for linked list operations.
 *	These functions will be implemented for snake operations.
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node
{
    int x;
    int y;
    node *next;
};

node *newNode(int x_coord, int y_coord);
void addFirst(node **head, int x_coord, int y_coord);
void addLast(node **head, int x_coord, int y_coord);
void deleteFirstNode(node **head);
void destroyLinkedList (node **head);
void readLinkedList(node *head);

#endif /* LINKED_LIST_H_ */
