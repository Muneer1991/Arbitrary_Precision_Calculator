#include "double_list.h"

/* Function definition to do addition */
void add_list(Dlist *op1_tail, Dlist *op2_tail, Dlist **result_head, Dlist **result_tail)
{
    /* Variable to keep track of carry */
	int carry = 0;

    /* Loop until the end of operand lists */
	while (op1_tail || op2_tail)
	{
        /* Condition if both the lists not reached end node */
		if (op1_tail && op2_tail)
		{
            /* Function call to do addition */
			carry = carry_sum(op1_tail -> data, op2_tail -> data, carry, result_head, result_tail);
			op1_tail = op1_tail -> prev;
			op2_tail = op2_tail -> prev;
		}
        /* Condition if 2nd operand reached end and other has more nodes */
		else if(op1_tail)
		{
            /* Function call to do addition */
			carry = carry_sum(op1_tail -> data, 0, carry, result_head, result_tail);
			op1_tail = op1_tail -> prev;
		}
         /* Condition if 1st operand reached end and other has more nodes */
		else
		{
            /* Function call to do addition */
			carry = carry_sum(0, op2_tail -> data, carry, result_head, result_tail);
			op2_tail = op2_tail -> prev;
		}
	}
    /* Condition to check if carry present then insert the carry at the end of the operation */
	if (carry)
	{
		insert_first(result_head, carry, result_tail);
	}


}