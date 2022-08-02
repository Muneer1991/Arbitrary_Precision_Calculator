#include "double_list.h"

/* Function defintion to delete the entire list */
Status delete_list(Dlist **head, Dlist **tail)
{
	/* Check if the list is empty */
	if(*head == NULL)
		return failure;

	/* Check if there is only 1 node */
	/* free the only node and update the head and tail */
	if(*head == *tail)
	{
		free(*head);
		*head = NULL;
		*tail = NULL;
		return success;
	}

	/* Condition for more than 1 node */
	else
	{
		/* Temporary pointer to traverse through the list */
		Dlist *temp = *head;
		/* free the first node each time and update the head with next node */
		while(temp != NULL)
		{
			*head = temp -> next;
			free(temp);
			temp = *head;
		}
		/* update tail with NULL at last */
		*tail = NULL;
		return success;
	}
}