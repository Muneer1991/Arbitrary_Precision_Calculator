#include "double_list.h"

/* Function defintion to delete first node */
Status delete_first(Dlist **head, Dlist **tail)
{
	if(*head == NULL)
		return failure;

	/* condition to check if only 1 node present */
	if(*head == *tail)
	{
		/* free the node and update head and tail with null */
		free(*head);
		*head = NULL;
		*tail = NULL;
		return success;
	}
	/* if more than one node present update the head with 2nd node address */
	/* then free the first node */
	else
	{
		Dlist *temp = *head;
		*head = (*head) -> next;
		free(temp);
        (*head) -> prev = NULL;
		return success;
	}
}