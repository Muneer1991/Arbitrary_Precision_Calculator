#include "double_list.h"

/* Function definition to find power of a number */
void power_list(Dlist *op1_tail, Dlist *op1_head, Dlist *op2_tail, Dlist *op2_head, Dlist **result_head, Dlist **result_tail, int sign1, int sign2, char opr)
{
    /* Necessary lists initialization for doing the operations */
    Dlist *sub_head = NULL;
    Dlist *sub_tail = NULL;
    Dlist *op_head = NULL;
    Dlist *op_tail = NULL;
    Dlist *power_head = NULL;
    Dlist *power_tail = NULL;

    /* Adding a node with data as 1 used to decrement the counter */
    insert_first(&op_head, 1, &op_tail);
    
    /* Loop until counter is 0 */
    while(1)
    {
        /* Subtracting the counter (power value given by user) */
        subs_list(op2_head, op_head, op2_tail, op_tail, &sub_head, &sub_tail, sign1, sign2, opr);

        /* Temp pointer to store the result head pointer */
        Dlist *temp1 = sub_head;

        /* Delete power list, if already present */
        if(op2_head)
        {
            delete_list(&op2_head, &op2_tail);
        }
        
        /* Insert the difference result in op2_head list */
        while(temp1)
        {
            insert_last(&op2_head, temp1 -> data, &op2_tail);
            temp1 = temp1 -> next;
        }
        /* Then delete the result list */
        delete_list(&sub_head, &sub_tail);
        temp1 = NULL;
        
        /* Break the loop when counter reaches 0 */
        if(op2_head -> data == 0)
            break;

        /* Conditions to do multiplication to find out the operand^power */
        if(!power_head)
            multi_list(op1_head, op1_head, op1_tail, op1_tail, result_head, result_tail, sign1, sign2);
        else
            multi_list(power_head, op1_head, power_tail, op1_tail, result_head, result_tail, sign1, sign2);

        /* Temp pointer to store the result head pointer */
        Dlist *temp = (*result_head);
        
        /* Delete power list, if already present */
        if(power_head)
        {
            delete_list(&power_head, &power_tail);
        }
        /* Insert the multiplication result in another list */
        while(temp)
        {
            insert_last(&power_head, temp -> data, &power_tail);
            temp = temp -> next;
        }
        
        /* Then delete the result list */
        delete_list(result_head, result_tail);
        temp = NULL;
    }
    /* Print the power and delete the lists */
    printf("Power = ");
    print_list(power_head);
    delete_list(&op_head, &op_tail);
    delete_list(&power_head, &power_tail);
}