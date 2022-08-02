#include "double_list.h"

/* Function defintion for multiplication operation*/
void multi_list(Dlist *op1_head, Dlist *op2_head, Dlist *op1_tail, Dlist *op2_tail, Dlist **result_head, Dlist **result_tail, int sign1, int sign2)
{
    /* Count variable to keep track of number of nodes present in 2nd operand */
	int count = 0;
    /* temporary pointer to point to result tail */
	Dlist *temp = NULL;
    /* Temporary pointer to point to 1st operand tail */
	Dlist *temp_op1 = op1_tail;
    /* Check the greatness of the operands through compare function call */
	int value = compare (op1_head, op2_head);

    /* Condition if the 1st operand is lesser than 2nd */
	if(value == less)
	{
		op1_tail = op2_tail;
		op2_tail = temp_op1;
		temp_op1 = op1_tail;
	}
	temp = *result_tail;

    /* Loop till the end of 2nd operand list */
	while(op2_tail)
	{
        /* Declaring variables */
		int carry_out = 0;    //After 2nd operand's each node is processed make the carry_out 0
		int data;
		Dlist *temp_result = temp;	// To traverse result by one node every time
		while (op1_tail)
		{
			/* Long unsigned int to store multiplication of two integers */
			long unsigned int prod = 0;
		
			prod = (long unsigned int) op1_tail->data * op2_tail->data;	// Type cast op1 so does op2 to long unsigned int
			prod = prod + carry_out;

            /* Condition if there are more than 1 node for 2nd operand list */
			if (temp_result)
			{
				data = temp_result -> data;			// Get the data from result node
				carry_out = (data + prod) / TEN_POWER_FOUR;
				data = (data + prod) % TEN_POWER_FOUR;
				temp_result -> data = data;			// Modify the data in result node
				temp_result = temp_result -> prev;	// Traverse to previous result node
			}
            /* Condition for processing the last node of the 2nd operand */
			else
			{
				data = prod % TEN_POWER_FOUR;
				carry_out = prod / TEN_POWER_FOUR;
				insert_first(result_head, data, result_tail);
			}
            
			op1_tail = op1_tail -> prev;
		}
        /* Store the carry out at the end of 2nd operand's 1 node operation */
		if (carry_out)
		{
			insert_first(result_head, carry_out, result_tail);
		}
        /* traverse thr 2nd operand's tail */
		op2_tail = op2_tail -> prev;
        /* Conditions to point to the result after the multiplication */
		if (count)
		{
			temp = temp -> prev;
		}
		else
		{
			temp = *result_tail;
			temp = temp -> prev;
		}
        /* Increment pointer for more than 1 node for 2nd operand */
		count++;	

        /* Start again from the 1st operand tail */
		op1_tail = temp_op1;						
	}	

    /* signed conditions for operands */
    if(sign1 && sign2)
    {
        return;
    }
    else if(sign1 || sign2)
    {
        (*result_head) -> data = (*result_head) -> data * (-1);
    }
}