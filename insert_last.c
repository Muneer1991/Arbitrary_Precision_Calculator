#include "double_list.h"

/* Function definition to insert node at the end */
Status insert_last(Dlist **head, int data, Dlist **tail)
{
	/* Create a new node */
	Dlist *new = calloc(sizeof(Dlist),1);

	/* Check if node is created */
	if(new == NULL)
		return failure;

	/* Update node values */
	new -> data = data;
	new -> prev = NULL;
	new -> next = NULL;

	/* if list is empty update head and tail */
	if(*head == NULL)
	{
		*head = new;
		*tail = new;
		return success;
	}

	/* If list is non empty insert the node at the last */
	else
	{
		new -> prev = *tail;
		(*tail) -> next = new;
		*tail = new;
		return success;
	}
}