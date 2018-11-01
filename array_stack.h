/* Header file: array_stack.h
 *
 * Υλοποίηση στοίβας με πίνακα 
 *
 * Συναρτήσεις:
 * full
 * empty
 * create
 * push
 * pop
 * print_stack
 * stack_count
 * topelement
 */

/* Δημιούργησε μια δομή stack ώστε να αποθηκεύσουμε όλες τις πληροφορίες που
 * χρειαζόμαστε 
 * H δομή stack έχει τα ακόλουθα περιεχόμενα
 * - contents: O πίνακας ακεραίων που θα είναι η στοίβα μας
 * - top: τρέχουσα θέση της κορυφής
 * - max_size: μέγιστο μέγεθος στοίβας. (To χρησιμοποιούμε για να ελέγξουμε αν 
 *   η στοίβα είναι γεμάτη)
 */
typedef int stackElement; // Συντόμευση για τον τύπο δεδομένων των στοιχείων της 
                          // στοίβας

typedef struct stack {
    /* Δείκτης σε ένα πίνακα ακεραίων ( stackElement είναι συνώνυμο ακεραιου )
     */
    stackElement *contents;
    int top; /* Αποθηκεύουμε την τρέχουσα θέση το στοιχείου κορυφής */
    int max_size; /* Ο μέγιστος αριθμός των στοιχείων που μπορεί να έχει η στοίβα */
} Stack;


int empty (Stack *stkPtr)
{
  if (stkPtr->top >= 0)
    {
      return 0;
    }
  else
    {
      return 1;
    }
}

int stack_count (Stack *stkPtr)
{
  int count;
  if (empty (stkPtr))
    count = 0;
  else
    count = stkPtr->top + 1;

  return count;
}

/* Έλεγχος αν η στοίβα είναι γεμάτη */
int full (Stack *stkPtr)
{
  if (stkPtr->top == stkPtr->max_size - 1)
    return 1;
  else
    return 0;
}

void create (Stack *stkPtr, int max_size)
{
  stkPtr->contents = (stackElement *) malloc (sizeof (stackElement) * max_size);
  if (stkPtr->contents == NULL)
    {
      printf ("Couldn't allocate memory for the stack. Exiting...\n");
      exit (1);
    }
  stkPtr->top = -1;
  stkPtr->max_size = max_size;
}

int pop (Stack *stkPtr)
{
  /* Έλεγχος αν η στοίβα είναι άδεια */
  if (empty (stkPtr))
    {
      printf ("The stack is empty. Action cannot be completed!\n");
      return 1;
    }

  return stkPtr->contents[stkPtr->top--];
}

void push (Stack *stkPtr, int value)
{
  /* Έλεγχος αν η στοίβα είναι γεμάτη */
  if (full (stkPtr))
    {
      printf ("The stack is full. Action cannot be completed!\n");
      exit (1);
    }

  stkPtr->contents[++stkPtr->top] = value;
}

void print_stack (Stack *stkPtr)
{
  if (empty (stkPtr))
    {
      printf ("|   | -1 <-- Top\n");
      printf ("|---|\n\n");
    }
  else
    {
      int i;
      for (i = stkPtr->top; i >= 0; i--)
        {
          if (stkPtr->top == i)
            printf ("| %5d | %2d <-- Top\n", stkPtr->contents[i], i);
          else
            printf ("| %5d | %2d\n", stkPtr->contents[i], i);
          printf ("|-------| \n");
        }
		printf ("\n");
    }
}

void topelement (Stack *stkPtr)
{
  if (empty (stkPtr))
    printf ("The stack is empty.\n");
  else
    printf ("Top element: %d\n", stkPtr->contents[stkPtr->top]);
}

void destroy (Stack *stkPtr)
{
  stkPtr->top = -1;
}
