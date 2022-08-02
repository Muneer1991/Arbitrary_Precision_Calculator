#include "double_list.h"

/* Sub function defintion for doing addition */
int carry_sum(int op1_data, int op2_data, int carry, Dlist **result_head, Dlist **result_tail)
{
    /* Variable declarations */
	int carry_out = 0, sum;

    /* Store addition result of operand1 node data and operand2 node data in a variable*/
	sum  = op1_data + op2_data + carry;
    /* Find carry */
	carry_out = sum / TEN_POWER_FOUR;

    /* If carry present then update sum */
	if (carry_out)
	{
		sum = sum - (carry_out * TEN_POWER_FOUR);
	}
    
    /* Insert the sum to result */
	insert_first(result_head, sum, result_tail);

    /* return the carry */
	return carry_out;
}