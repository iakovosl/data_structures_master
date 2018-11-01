#include <stdio.h>
#include <stdlib.h>
#include "array_stack.h"

/* Thema 6 */
/* expression: [(10+2) x (8-3)] + 2 */

/* Αλγόριθμος */
/* ---------- */

/* Μετατρέπουμε την έκφραση σε postfix notation */
/* Αποθηκεύουμε τους αριθμούς που συναντάμε και κάνουμε push μέχρι να συναντήσουμε κάποια πράξη */
/* Μόλις συναντήσουμε πράξη κάνουμε δύο pop και υπολογίζουμε το αποτέλεσμα */
/* Κάνουμε push το αποτέλεσμα και συνεχίζουμε μέχρι να συναντήσουμε άλλη πράξη */ 
/* Όταν τελειώση η έκφραση (συμβολοσειρά) κάνουμε ένα pop που είναι το αποτέλεσμα */

int main (int argc, char *argv[])
{
	int operandA; // προσωρινές μεταβλητές
	int operandB;

	int result; // Θα αποθηκεύσουμε το αποτέλεσμα της έκφρασης

	printf ("Calculating the expression [(10+2) x (8-3)] + 2\n");
	// Τυπώνουμε τη μετατροπή της έκφρασης σε συμβολισμό postfix
	printf ("Postfix equivalent: 10 2 + 8 3 - x 2 +\n");

	/* Δημιουργία στοίβας */
	Stack s1;
	create (&s1, 40);
	printf ("Stack created\n");
	print_stack (&s1);

	printf ("push 10\n");
	push (&s1, 10);
	print_stack (&s1);
	printf ("push 2\n");
	push (&s1, 2);
	print_stack (&s1);

	operandB = pop (&s1);
	printf ("operandB = pop () = %d\n", operandB);
	operandA = pop (&s1);
	printf ("operandA = pop () = %d\n", operandA);
	print_stack (&s1);
	printf ("push (operandA + operandB)\n");
	push (&s1, operandA + operandB);
	print_stack (&s1);
	puts (" ");

	printf ("push 8\n");
	push (&s1, 8);
	printf ("push 3\n");
	push (&s1, 3);
	print_stack (&s1);

	operandB = pop (&s1);
	printf ("operandB = pop () = %d\n", operandB);

	operandA = pop (&s1);
	printf ("operandA = pop () = %d\n", operandA);
	printf ("push (operandA - operandB)\n");
	push (&s1, operandA - operandB);
	print_stack (&s1);


	operandB = pop (&s1);
	printf ("operandB = pop () = %d\n", operandB);
	operandA = pop (&s1);
	printf ("operandA = pop () = %d\n", operandA);
	push (&s1, operandA * operandB);
	printf ("push (operandA x operandB)\n");
	print_stack (&s1);

	printf ("push %d\n", 2);
	push (&s1, 2);
	print_stack (&s1);

	operandB = pop (&s1);
	printf ("operandB = pop () = %d\n", operandB);
	operandA = pop (&s1);
	printf ("operandA = pop () = %d\n", operandA);
	push (&s1, (operandA + operandB));
	print_stack (&s1);

	/* Τελικό pop για αποτέλεσμα */
	result = pop (&s1);
	printf ("Result: %d\n", result);

	return 0;
}
