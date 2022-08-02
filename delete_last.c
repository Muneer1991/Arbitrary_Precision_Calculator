#include "double_list.h"

/* Function defintion to delete last node */
Status delete_last(Dlist **head, Dlist **tail)
{
    /* Check if the list is empty */
	if(*head == NULL)
		return failure;

	/* Check if only one node present */
	/* Then free the node and update head and tail with null */
	if(*head == *tail)
	{
		free(*head);
		*head = NULL;
		*tail = NULL;
		return success;
	}

	/* if more than one node present update 2nd last node link with NULL */
	/* free the last node */
	else
	{
		Dlist *last = *tail;
		(*tail) -> prev -> next = NULL;
		*tail = (*tail) -> prev;
		free(last);
		return success;
	}
}