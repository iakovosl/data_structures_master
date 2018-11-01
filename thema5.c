/*
 * Υλοποίηση στοίβας με συνδεδεμένη λίστα 
 */
#include <stdio.h>
#include <stdlib.h>
#include "linked_list_stack.h"

#define TRUE 1
#define FALSE 0

void display_menu (Stack *stkPtr);

int main(int argc, char *argv[])
{
    Stack s1;
    create(&s1);
    display_menu (&s1);

    return 0;
}

void display_menu (Stack *stkPtr)
{
    int no, ch = 1;

    printf("\n 1 - Push");
    printf("\n 2 - Pop");
    printf("\n 3 - Top Element");
    printf("\n 4 - Is Empty?");
    printf("\n 5 - Print Stack");
    printf("\n 6 - Stack Count");
    printf("\n 7 - Empty Stack");
    printf("\n 8 - Exit");

    while (TRUE)
    {
        printf("\n Enter choice : ");
        scanf("%1d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &no);
            push(stkPtr, no);
            break;
        case 2:
            pop(stkPtr);
            break;
        case 3:
            if (empty (stkPtr))
                printf("No elements in stack");
            else
                printf("\n Top element : %d", topelement(stkPtr));

            break;
        case 4:
            if (empty (stkPtr))
                printf("\n Stack is empty");
            else
                printf ("The stack is not empty");
                printf("\n No. of elements in stack : %d", stack_count(stkPtr));
            break;
        case 5:
            print_stack (stkPtr);
            break;
        case 6:
            printf("\n No. of elements in stack : %d", stack_count(stkPtr));
            break;
        case 7:
            delete(stkPtr);
            break;
        case 8:
            exit(0);
        default :
            printf(" Wrong choice, Please enter correct choice  ");
            break;
        }
    }
}

