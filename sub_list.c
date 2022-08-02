#include "double_list.h"

/* Function definition for substraction */
void subs_list(Dlist *op1_head, Dlist *op2_head, Dlist *op1_tail, Dlist *op2_tail, Dlist **result_head, Dlist **result_tail, int sign1, int sign2, char opr)
{
    /* Variable definitions */
	int borrow = 0, sign = 0;
    
    /* Function call to store the greatness of the operands */
	int value = compare (op1_head, op2_head);
    
    /* Conditions to do check if addition is to be done */
    /* When the operator is '-' and the sign of 2nd operand is also '-' */
    /* sign2 is made positive in sign_check function */
    if(opr == '-' && sign1 == 0 && sign2 == 0)
    {
        add_list(op1_tail, op2_tail, result_head, result_tail);
        return;
    }

    /* if both the signs are '-' then do addition and make result '-' */
    else if(sign1 == 1 && sign2 == 1)
    {
        add_list(op1_tail, op2_tail, result_head, result_tail);
        (*result_head) -> data =(*result_head) -> data * -1;
        return;
    }

    /* When both the operands are same then result is 0 */
    if (value == equal)
	{
		insert_first(result_head, 0,result_tail);
		return;
	}

    /* When the 1st operand is lesser do swapping */
    /* No swapping needed during division */
	if ((value == less && opr == '-') || (value == less && opr == '+'))
    {

		Dlist *temp;
		temp = op1_tail;
		op1_tail = op2_tail;
		op2_tail = temp;
        if(sign2 == 1 && opr == '+') //condition when operator is '+' and sign2 is '-'
		    sign = 1;

	}

    /* Condition when 1st operand is greater and its sign is '-' */
    if(value == more && sign1 == 1)
    {
        sign = 1;
    }

    /* Loop until both the operand list traversal are completed */
	while (op1_tail || op2_tail)
	{
        /* if both the list have valid nodes */
		if (op1_tail && op2_tail)
		{
            /* sub function call to do subtraction*/

			borrow = borrow_list(op1_tail -> data, op2_tail -> data, borrow, op1_tail -> prev, result_head, result_tail);
            /* Traverse */
			op1_tail = op1_tail -> prev;
			op2_tail = op2_tail -> prev;
		}
		else 
		{
            /* sub function call to do subtraction*/
            if(op1_tail -> prev && op1_tail -> data == 0)
			    borrow = borrow_list(op1_tail -> data, 0, borrow,  op1_tail -> prev, result_head, result_tail);
            else
                borrow = borrow_list(op1_tail -> data, 0, borrow,  NULL, result_head, result_tail);
            /* Traverse */
			op1_tail = op1_tail -> prev;
		}
		
	}

    /* If the sign flag is high make the result '-' */
	if (sign)
	{
        if((*result_head) -> data == 0)
            delete_first(result_head, result_tail);
        
		(*result_head) -> data =(*result_head) -> data * -1; 
	}
}