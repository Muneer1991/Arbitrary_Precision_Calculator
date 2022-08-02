#include "double_list.h"

/* Function defintion to compare the greatness of the operands */
Status compare (Dlist *op1_head, Dlist *op2_head)
{
    /* Function call to find number of nodes and store them in 2 variables */
	unsigned int node1 = total_node(op1_head);	
	unsigned int node2 = total_node(op2_head);

    /* Count variable used for checking if the operands are equal*/
    unsigned int count = 0;

    /* Condition to check if the length of 1st operand is more than 2nd operand */
	if (node1 > node2)
	{
		return more;
	}
    /* Condition to check if the length of 1st operand is less than 2nd operand */
	else if (node1 < node2)
	{	
        return less;
	}
    /* Condition to check if the length of 1st operand is equal to 2nd operand */
	else
	{
        /* Checking the greatness of the first four digits of the operands */
		if (op1_head -> data > op2_head -> data)
		{
			return more;
		}
		else if (op1_head -> data < op2_head -> data)
		{
			return less;
		}
		else
		{
            /* Loop to check if the operands are equal */
            while(op1_head != NULL)
            {
                /* Check whether the data part of the nodes are equal and increment the count */
                if(op1_head -> data == op2_head -> data)
                    count++;

                /* Traverse through both the nodes */
                op1_head = op1_head -> next;
                op2_head = op2_head -> next;
            }
            /* This condition means both that all nodes data are equal */
            if(count == node1)
            {
                return equal;    
            }
		}	
	}
    /* Return more if no conditions are matching */
    return more;
}