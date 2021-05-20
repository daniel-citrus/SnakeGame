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

node *new_node(int x_coord, int y_coord);
void add_first(node **head, int x_coord, int y_coord);
void add_last(node **head, int x_coord, int y_coord);
void delete_first_node(node **head);
void destroy_linked_list (node **head);
void read_linked_list(node *head);

#endif /* LINKED_LIST_H_ */
