#include "double_list.h"

/* Function defintion to check the sign of operands and the operators */
void sign_check(Dlist **op1_head, Dlist **op2_head, Dlist **op1_tail, Dlist **op2_tail,int *sign1, int *sign2, char opr)
{
    /* Conditions to check if the 1st operand is negetive */
    if((*op1_head) -> data < 0)
    {
        *sign1 = 1;
        (*op1_head) -> data *= -1;
    }
    else if((*op1_head) -> data == 0)
    {
        *sign1 = 1;
        delete_first(op1_head, op1_tail);
    }

    /* Conditions to check if the 2nd operand is negetive */
    if((*op2_head) -> data < 0)
    {
        *sign2 = 1;
        (*op2_head) -> data *= -1;
    }
    else if((*op2_head) -> data == 0)
    {

        *sign2 = 1;
        delete_first(op2_head, op2_tail);
    }

    /* Conditions to check if the the 2nd operand sign and operator is as follows */
    if((opr == '+' && *sign2 == 1) || (opr == '-' && *sign2 == 0))
    {
        *sign2 = 1;
    }
    else if((opr == '-' && *sign2 == 1) || (opr == '-' && *sign2 == 0))
    {
        *sign2 = 0;
    }
}