#include "double_list.h"

/* Function definition to do division operation */
/* Execution time for division will be greater if 2nd operand is very less compared to 1st */
/* Try giving a difference of 4 digits max eg: 837682823824238479238947284 / 83427839213928364865346 */
void divi_list(Dlist *op1_head, Dlist *op2_head, Dlist *op1_tail, Dlist *op2_tail, Dlist **result_head, Dlist **result_tail, int sign1, int sign2, char opr)
{
    /* Variable to check if the quotient is going to negetive */
    int diff = 0, sign = 0, value;
    /* Count variable used to increment after each substraction */
    long unsigned int count = 0;

    /* Conditions for signed operands and deciding the sign flag */
    if(sign1 == 1 && sign2 == 1)
    {
        sign1 = 0;
        sign2 = 0;
    }
    else if (sign1 == 1 || sign2 == 1)
    {
        sign = 1;
        sign1 = 0;
        sign2 = 0;
    }
    if((value = compare(op1_head, op2_head)) == equal)
    {
        printf("Quotient = 1\n");
        return;
    }
    else if(value == less)
    {
        printf("Divident should be more than Divisor\n");
        return;
    }
    /* Define head and tail pointers for a list to store the difference recurssively */
    Dlist *diff_head = NULL;
    Dlist *diff_tail = NULL;

    /* Loop until the quotient is falling to negetive */
    while(1)
    {
        /* Do substraction recurrsively until negetve value is reached */
        subs_list(op1_head, op2_head, op1_tail, op2_tail, result_head, result_tail, sign1, sign2, opr);
        
        /* Temp pointer to store the result */
        Dlist *temp = (*result_head);

        /* Delete difference list, if already present */
        if(diff_head)
        {
            delete_list(&diff_head, &diff_tail);
        }
        /* Insert the difference result in another list */
        while(temp)
        {
            insert_last(&diff_head, temp -> data, &diff_tail);
            temp = temp -> next;
        }
        /* Then delete the result list */
        delete_list(result_head, result_tail);

        /* Change the 1st operand to the difference list */
        op1_head = diff_head;
        op1_tail = diff_tail;
        
        /* Store the first for digits in a variable to check if negetive number is reached */
        diff = diff_head -> data;

        /* Incremenet counter if diff is positive or 0 */
        if(diff >= 0)
        {
            count++;    
        }
        else
        {
            delete_list(&diff_head, &diff_tail);
            break;    
        }
        
    }

    /* Count value is the quotient */
    if(sign == 0)
    {
        printf("Quotient = %ld\n",count);
    }
        
    else
    {
        printf("Quotient = %ld\n",count * (-1));
    }
        
}