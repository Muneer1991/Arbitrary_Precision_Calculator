#include "double_list.h"

/* Function definition to insert node at first */
Status insert_first(Dlist **head, int data, Dlist **tail)
{
		/* Create node */
	Dlist *new = calloc(sizeof(Dlist),1);

	/* Check if not created succesfully */
	if(new == NULL)
		return failure;

	/* Update node values */
	new -> data = data;
	new -> prev = NULL;
	new -> next = NULL;

	/* Check if list is empty */
	/* Update head and tail with new node address */
	if(*head == NULL)
	{
		*head = new;
		*tail = new;
		return success;
	}

	/* if list is non empty insert new node to the first node */
	else
	{
		new -> next = *head;
		(*head) -> prev = new;
		*head = new;
		return success;
	}
}