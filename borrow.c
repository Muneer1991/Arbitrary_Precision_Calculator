#include "double_list.h"

/* Sub function for substraction */
int borrow_list(int op1, int op2, int borrow_in, Dlist *next, Dlist **result_head, Dlist **result_tail)
{
    /* Variable declaration */
	int borrow_out = 0, diff;

    /* Next is the previous node of the 1st operand starting from tail end */
    /* Also when the data is 0 but there is a borrow_in */
	if (next)
	{
        /* Condition to check if the number in 1st operand is less than number in 2nd operand */
		if ((op1 < op2) || (op1 == 0 && op2 == 0 && borrow_in == 1))
		{
            /* Operations to make op1 greater and store the borrow status */
			borrow_out = 1;
			op1 = op1 + (borrow_out * TEN_POWER_FOUR);
		}
	}

    /* Find the difference and store in result */
	diff = op1 - op2 - borrow_in;

	insert_first(result_head, diff, result_tail);

    /* Return the borrow status */
	return borrow_out;
}