#include "double_list.h"

/* Function definition to do modulus operation */
void mod_list(Dlist *op1_head, Dlist *op2_head, Dlist *op1_tail, Dlist *op2_tail, Dlist **result_head, Dlist **result_tail, int sign1, int sign2, char opr)
{
    /* Variable to check the greatness of operands */
    int value;

    /* Function call to check the greatness of operands */
    if((value = compare(op1_head, op2_head)) == equal)
    {
        printf("Remainder = 0\n");
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

    /* Loop until the difference is falling to negetive */
    while(1)
    {
        /* Do substraction recurrsively until negetve value is reached */
        subs_list(op1_head, op2_head, op1_tail, op2_tail, result_head, result_tail, 0, 0, opr);

        /* Condition to check if negetive is reached */
        if((*result_head) -> data < 0)
        {
            /* Empty the result list that contains the negetive value */
            delete_list(result_head, result_tail);
            /* Print the last difference value as the remainder*/
            printf("Remainder = ");
            print_list(diff_head);
            /* Delete difference list before terminating */
            delete_list(&diff_head, &diff_tail);
            break;
        }
        
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
        temp = NULL;
        
        /* Change the 1st operand to the difference list */
        op1_head = diff_head;
        op1_tail = diff_tail;
    }    
}