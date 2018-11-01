/* Header file: linked_list_stack.h
 *
 * Υλοποίηση στοίβας με συνδεδεμένη λίστα 
 *
 */

/* κόμβος συνδεδεμένης λίστας */
typedef struct node {
    int data; // αποθηκεύουμε τα δεδομένα του κόμβου 
    struct node *nextPtr; // αποθηκεύουμε τη διεύθυνση του επόμενου κόμβου
} Node;

/* Δομή στοίβας που περιλαμβάνει όλα τα στοιχεία που χρειαζόμαστε για αυτήν */
typedef struct stack {
    Node *top; // Δείκτης προς τον κόμβο κορυφής 
    int count; // Αριθμός στοιχείων της στοίβας
} Stack;

void create(Stack *stkPtr);
int topelement(Stack *stkPtr);
void push(Stack *stkPtr, int data);
int pop(Stack *stkPtr);
int empty(Stack *stkPtr);
void print_stack (Stack *stkPtr);
void delete(Stack *stkPtr);
int stack_count(Stack *stkPtr);


/* Δημιουργία άδειας στοίβας */
void create (Stack *stkPtr)
{
    stkPtr->top = NULL;
    stkPtr->count = 0;
}

/* Επιστρέφουμε τον αριθμό των στοιχείων της στοίβας */
int stack_count(Stack *stkPtr)
{
    return stkPtr->count;
}

/* Προσθήκη (push) ενός στοιχείου στην κορυφή της στοίβας */
void push (Stack *stkPtr, int data)
{
    Node *new_top; // η νέα κορυφή 

    if (stkPtr->top == NULL) // H περίπτωση που η στοίβα είναι άδεια
    {
        stkPtr->top = (Node *) malloc (1 * sizeof (Node));
        stkPtr->top->nextPtr = NULL;
        stkPtr->top->data = data;
    }
    else
    {
        // Δέσμευσε μνήμη για το νέο κόμβο 
        new_top = (Node *) malloc ( 1 * sizeof (Node));
        // Πρόσθεσε τα στοιχεία που θα αποθηκεύει ο κόμβος
        new_top->data = data;
        // Θέσε ως δεύτερο στοιχείο την προηγούμενη κορυφη (κόμβο)
        new_top->nextPtr = stkPtr->top;
        // Θέσε ως νέα κορυφή τον καινούριο κόμβο που δημιουργήσαμε
        stkPtr->top = new_top;
        new_top = NULL;
    }

    stkPtr->count++; // Αυξάνουμε τον μετρητή της στοίβας
}

/* Τύπωσε τη στοίβα στο stdout */
void print_stack (Stack *stkPtr)
{
    Node *temp;
    if (empty(stkPtr))
    {
        printf ("|   |\n");
        printf ("|---|\n\n");
        return;
    }
    else
    {
        temp = stkPtr->top;
        int count = 0;
        while (temp != NULL)
        {
            if (count == 0)
                printf ("| %5d | Top\n", temp->data);
            else
                printf ("| %5d |\n", temp->data);
            temp = temp->nextPtr;
            count++;
        }
        printf ("|-------| \n");
    }
 }

/* Αφαίρεση στοιχείου από την κορυφή της στοίβας */
int pop(Stack *stkPtr)
{
	int value; /* Η τιμή που αφαιρέθηκε από τη στοίβα (θα την επιστρέψουμε) */
    Node *old_top; /* Ο κόμβος που θα διαγράψουμε */ 

    if (stkPtr->top == NULL) // Έλεγχος αν η στοίβα είναι άδεια 
    {
        printf("\n Error : Trying to pop from empty stack");
        exit (1);
    }
    else
    {
        // Ο κόμβος που θα διαγράψουμε (βρίσκεται στην κορυφή)
        old_top = stkPtr->top;
        // Τα δεδομένα του κόμβου που θα διαγράψουμε 
		value = old_top->data;
        printf ("Pop value %d\n", value);

        // Αποθηκεύουμε τη νέα κορυφή της στοίβας 
        stkPtr->top = stkPtr->top->nextPtr;
    }

    // Ελευθερώνουμε τη μνήμη του κόμβου που μόλις διαγράψαμε
    free(old_top);
    // Μειώνουμε το μετρητή της στοίβας 
    stkPtr->count--;

	return value;
}

/* Επέστρεψε το στοιχείο της κορυφής */
int topelement(Stack *stkPtr)
{
    return stkPtr->top->data;
}

/* Έλεγχος αν η στοίβα είναι άδεια */
int empty(Stack *stkPtr)
{
    if (stkPtr->top == NULL)
        return 1;
    else
        return 0;
}

/* Διέγραψε όλα τα στοιχεία της στοίβας */
void delete (Stack *stkPtr)
{
    // O κόμβος κορυφής
    Node *temp = stkPtr->top;

    if (stkPtr->top == NULL)
    {
        printf("\n Stack is empty");
        return;
    }

    while (stkPtr->top != NULL)
    {
        // Διαγράφουμε έναν έναν τους κόμβους ξεκινώντας από την κορυφή
        temp = stkPtr->top;
        stkPtr->top = stkPtr->top->nextPtr;
        free(temp); // Ελευθερώνουμε τη μνήμη του κόμβου που διαγράψαμε 
    }

    printf("\n All stack elements deleted");
    stkPtr->count = 0; // Θέτουμε τον μετρητή της στοίβας σε 0
}
