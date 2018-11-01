#include <stdio.h>
#include <stdlib.h>
#include "array_stack.h"

#define TRUE 1
#define FALSE 0

void display_menu (Stack *stkPtr);
void demo (Stack *stkPtr);

int main (int argc, char *argv[])
{
  /* Δημιούργησε μια μεταβλητή τύπου stack */
  Stack s1;
  /* Δημιούργησε το stack και σώσε το στη μεταβλητή s1) */
  create (&s1, 10);

  display_menu (&s1);

  return 0;
}

void display_menu (Stack *stkPtr)
{
    int no, ch = 1;

    printf("\n 0 - Demo Example");
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
        printf ("\n\nEnter choice: ");
        scanf ("%1d", &ch);

        switch (ch)
        {
        case 0:
            demo (stkPtr);
            break;
        case 1:
            printf("\nEnter data : ");
            scanf("%d", &no);
            push(stkPtr, no);
            break;
        case 2:
            pop(stkPtr);
            break;
        case 3:
            topelement(stkPtr);
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
            destroy(stkPtr);
            break;
        case 8:
            exit(0);
        default :
            printf(" Wrong choice, Please enter correct choice  ");
            break;
        }
    }
}

void demo (Stack *stkPtr)
{
  /* Τύπωσε μια άδεια στοίβαι*/
  printf ("\nPrinting the new stack...\n");
  print_stack (stkPtr);

  printf ("\nAdding data to stack...\n");
  printf ("push number 33");
  push (stkPtr, 33);
  printf ("\npush number 44");
  push (stkPtr, 44);
  printf ("\npush number 55\n");
  push (stkPtr, 55);
  printf ("\nPrinting the stack again...\n");
  print_stack (stkPtr);

  printf ("\nRemoving data from stack...\n");
  printf ("Running pop once\n");
  pop (stkPtr);
  printf ("\nPrinting the stack again...\n");
  print_stack (stkPtr);

}


