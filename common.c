#include "double_list.h"

/* Function defintion to print the list */
Status print_list(Dlist *head)
{
    /* Check if list is not empty */
	if (head)
	{
        /* Traverse through the list and print the data in 4's */
		while(head !=  NULL)
		{
            /* Add 0's if there are digits less than 4 */
			printf("%0*d ", MAX_DIGIT, head -> data);
			head = head -> next;
		}
        
		printf("\n");
		return success;
	}
	else
	{
		printf("Error: List is empty\n");
		return failure;
	}
}

/* Function defintion to find the number of nodes */
unsigned int total_node(Dlist *head)
{
    /* Variable to keep count of the nodes */
	unsigned int count = 0;
    /* If the list is empty then return 0 */
	if (head == NULL)
	{
		return count;
	}
    /* If above condition is false then there is one node */
	count = 1;
    /* Traverse and count the number of number */
	while(head -> next)
	{
		count++;
		head = head -> next;
	}
    /* return count after traversal */
	return count;
}