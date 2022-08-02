/**************Documentation**************
Name          : Muneer Mohammad Ali
Date          : 04/07/2022
Description   : Arbitrary Precision Calculator for '+' '-' '/' 'x' '%' '^'
Sample Input  : ./a.out 837682823824238479238947284 / 83427839213928364865346
Sample Output : Divident : 0837 6828 2382 4238 4792 3894 7284 
                Divisor: 0834 2783 9213 9283 6486 5346 
                Quotient = 10040
******************************************/
#include "double_list.h"

int main(int argc, char **argv)
{
    /* Conditions to check if there are 4 arguments given through CLA */
    if(argc != 4)
    {
        printf("Enter the operands and operator with spaces\n");
        printf("Eg: ./a.out 123456123456123456 + 123456123456123456\n");
        return 1;
    }
    
    /* Store the operands and operator as string literals */
	char *operand1 = argv[1];
	char *opr = argv[2];
	char *operand2 = argv[3];

    /* status variable for sign */
    int sign1 = 0, sign2 = 0;
    
    /* Print operator and operand */
	printf("----------------OPERATION------------------\n");
	printf("%s %s\n%s\n", operand1, opr, operand2);

    /* Find length of operands */
	int oprd1_len = strlen(operand1);
	int oprd2_len = strlen(operand2);

    /* Variables to store the number of nodes necessary to store the number in division of 4 */
	int extra1 = oprd1_len % MAX_DIGIT;
	int extra2 = oprd2_len % MAX_DIGIT;
    /* If the length is not divisible by 4 then 1 extra node is needed to save remaining number */
	int node1 = (oprd1_len / MAX_DIGIT) + !!extra1; 
	int node2 = (oprd2_len / MAX_DIGIT) + !!extra2;

    /* Array to store the number string and a NULL character */
	char fnode[5];

	printf("--------------LINKED LIST DATA-------------\n");	
	Dlist *op1_head = NULL, *op1_tail = NULL, *op2_head = NULL, *op2_tail = NULL;
    
	/* Variable to store the 4 digits */
	int num;

	/* Create double linked list */
    /* When length of operand is not divisible by 4 then store the extra digits first */
	if (extra1)
	{
		strncpy(fnode, operand1, extra1);
		fnode[extra1] = '\0';
        num = atoi(fnode);
        insert_last(&op1_head, num, &op1_tail);
		operand1 += extra1;    //delete the stored numbers from the operand
	}

	/* Store extra digit of operand 2 */
	if(extra2)
	{
		strncpy(fnode, operand2, extra2);
		fnode[extra2] = '\0';
		num = atoi(fnode);
		insert_last(&op2_head, num, &op2_tail);
		operand2 += extra2;    //delete the stored numbers from the operand
	}

    /* store rest of the numbers in 4's into the list*/
	while (*operand1)
	{
		strncpy(fnode, operand1, MAX_DIGIT);
		fnode[MAX_DIGIT] = '\0';
		num = atoi(fnode);
		insert_last(&op1_head, num, &op1_tail);
		operand1 += MAX_DIGIT;    //delete the stored numbers from the operand
	}
	while (*operand2)
	{
		strncpy(fnode, operand2, MAX_DIGIT);
		fnode[MAX_DIGIT] = '\0';
		num = atoi(fnode);
		insert_last(&op2_head, num, &op2_tail);
		operand2 += MAX_DIGIT;    //delete the stored numbers from the operand
	}

    /* Print the operand list */
	printf("First Operand : ");
	print_list(op1_head);
	printf("Second Operand : ");
	print_list(op2_head);

	/* Declaring the head and tail for storing the result */
	Dlist *result_head = NULL, *result_tail = NULL;

    /* Function call to store the sign of operands */
    sign_check(&op1_head, &op2_head, &op1_tail, &op2_tail, &sign1, &sign2, *opr);

    /* Switch case to operations */
	switch (*opr)
	{
        /* Addition operation */
		case '+':
            /* if both the signs are same then do addition */
            if ((sign1 && sign2) || (!sign1 && !sign2))
            {
                /* Function call to add the operands */
                add_list(op1_tail, op2_tail, &result_head, &result_tail);
                /* When sign is negetive then result is made negetive */
                if(sign1 == 1)
                    result_head -> data = (result_head -> data) * -1;
            }
            /* If any one sign is negetive then do subtraction in that case */
            else
            {
                /* Function call to do subtraction */
                subs_list(op1_head, op2_head, op1_tail, op2_tail, &result_head, &result_tail, sign1, sign2, *opr);
            }
			printf("-----------------ADDITION------------------\nSum is : ");
            /* Function call to print the result */
			print_list(result_head);
            printf("\n");
            /* Delete the result after operation is done */
            delete_list(&result_head, &result_tail);
            delete_list(&op2_head, &op2_tail);
			break;
        
        /* Substraction operation */
		case '-':
            /* Function call to do subtraction */
			subs_list(op1_head, op2_head, op1_tail, op2_tail, &result_head, &result_tail, sign1, sign2, *opr);
			printf("---------------SUBSTRACTION----------------\nSubstration is : ");
            /* Function call to print the result */
			print_list(result_head);
            printf("\n");
            /* Delete the result after operation is done */
            delete_list(&result_head, &result_tail);
            delete_list(&op2_head, &op2_tail);
			break;
        
        /* Multiplication operation */
		case 'x':
            /* Function call to do multiplication */
			multi_list(op1_head, op2_head, op1_tail, op2_tail, &result_head, &result_tail, sign1, sign2);
			printf("--------------MULTIPLICATION---------------\nMultiplication is: ");	
            /* Function call to print the result */
			print_list(result_head);
            printf("\n");
            /* Delete the result after operation is done */
            delete_list(&result_head, &result_tail);
            delete_list(&op2_head, &op2_tail);
			break;
        
        /* Division operation */
        case '/':
            /* Function call to do division */
            printf("-----------------DIVISION------------------\n");
            /* Print the divident */
            printf("Divident : ");
            print_list(op1_head);
            /* Print the divisor */
            printf("Divisor: ");
            print_list(op2_head);
            printf("Calculating...\n");
            /* Function call for division and printing the quotient */
            divi_list(op1_head, op2_head, op1_tail, op2_tail, &result_head, &result_tail, sign1, sign2, *opr);
            printf("\n");
            delete_list(&op2_head, &op2_tail);
            break;
        
        /* Modulus operation */
        case '%':
            /* Function call to do modulus */
            printf("------------------MODULUS------------------\n");
            /* Print the divident */
            printf("Divident : ");
            print_list(op1_head);
            /* Print the divisor */
            printf("Divisor: ");
            print_list(op2_head);
            /* Function call for modulus and printing the quotient */
            mod_list(op1_head, op2_head, op1_tail, op2_tail, &result_head, &result_tail, sign1, sign2, *opr);
            printf("\n");
            delete_list(&op2_head, &op2_tail);
            break;
        
        /* To find Power of a number */
        case '^':
            /* Function call to do modulus */
            printf("-------------------POWER-------------------\n");
            printf("Calculating...\n");
            /*  */
            power_list(op1_tail, op1_head, op2_tail, op2_head, &result_head, &result_tail, sign1, sign2, *opr);
            break;
        
		default:
			printf("Invalid operator\n");
	}
    
    /* Delete the operand lists */
	delete_list(&op1_head, &op1_tail);
	
	return 0;
}