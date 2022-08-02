#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* Macro definitions */
#define MAX_DIGIT 4
#define TEN_POWER_FOUR 10000

/* Structure declaration */
typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
} Dlist;

/* Return type of functions */
typedef enum 
{
	success,
	failure,
	less,
	more,
	equal,
    same_node
} Status;

/* Function prototype to insert node at the end */
Status insert_last(Dlist **head, int data, Dlist **tail);

/* Function prototype for printing list */
Status print_list(Dlist *head);

/* Function prototype to insert element at the starting of the list */
Status insert_first(Dlist **head, int data, Dlist **tail);

/* Function prototype to delete the first node */
Status delete_first(Dlist **head, Dlist **tail);

/* Function prototype to delete last */
Status delete_last(Dlist **head, Dlist **tail);

/* Function prototype to delete list */
Status delete_list(Dlist **head, Dlist **tail);

/* Function prototype to calculate number of nodes in a list */
unsigned int total_node(Dlist *head);

/* Function prototype to do addition */
void add_list(Dlist *op1_tail, Dlist *op2_tail, Dlist **result_head, Dlist **result_tail);

/* Sub-function prototype for addition */
int carry_sum(int op1_data, int op2_data, int carry, Dlist **result_head, Dlist **result_tail);

/* Function prototype for subtraction */
void subs_list(Dlist *op1_head, Dlist *op2_head, Dlist *op1_tail, Dlist *op2_tail, Dlist **result_head, Dlist **result_tail, int sign1, int sign2, char opr);

/* Sub-function prototype to do substraction */
int borrow_list(int op1, int op2, int borrow_in, Dlist *next, Dlist **result_head, Dlist **result_tail);

/* Function prototype for division */
void divi_list(Dlist *op1_head, Dlist *op2_head, Dlist *op1_tail, Dlist *op2_tail, Dlist **result_head, Dlist **result_tail, int sign1, int sign2, char opr);

/* Function prototype to do multiplication */
void multi_list(Dlist *op1_head, Dlist *op2_head, Dlist *op1_tail, Dlist *op2_tail, Dlist **result_head, Dlist **result_tail, int sign1, int sign2);

/* Function prototype to find the greatness between 2 operands */
Status compare (Dlist *op1_head, Dlist *op2_head);

/* Function prototype to check signs and operators */
void sign_check(Dlist **op1_head, Dlist **op2_head, Dlist **op1_tail, Dlist **op2_tail, int *sign1, int *sign2, char opr);

/* Function prototype to find the remainder after division */
void mod_list(Dlist *op1_head, Dlist *op2_head, Dlist *op1_tail, Dlist *op2_tail, Dlist **result_head, Dlist **result_tail, int sign1, int sign2, char opr);

/* Function prototype to find the power of an operand */
void power_list(Dlist *op1_tail, Dlist *op1_head, Dlist *op2_tail, Dlist *op2_head, Dlist **result_head, Dlist **result_tail, int sign1, int sign2, char opr);

#endif