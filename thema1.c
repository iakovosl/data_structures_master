#include <stdio.h>
#define LENGTH 10

/* Δήλωση των συναρτήσεων που θα χρησιμοποιηθούν */
void retrieve (double array[], double *retrieved_number, int index);
void update (double array[], double new_value, int index);
void add_arrays (double arrayA[], double arrayB[], double resultC[]);

/* Συνάρτηση test για έλεγχο καλής λειτουργίας του προγράμματος */
void test();

/* Οι πίνακες με τα δεδομένα τους που θα χρησιμοποιηθούν */
double A[LENGTH] = { 0, 0, 0 , 0, 0, 0, 0, 0, 0, 0};
double B[LENGTH] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
double C[LENGTH] = { 2, 3, 2, 5.4, 1, 5.4, 6, 8, 33, 19 };

int main ()
{
  test ();
  return 0;
}

/* Ζητάμε από έναν πίνακα την τιμή που βρίσκεται σε συγκεκριμένη θέση (index)
 * Παράμετροι:
 * 1. Πίνακας πραγματικών αριθμών (double)
 * 2. Δείκτης σε χώρο μνήμης που θα σώσουμε την τιμή που ζητάμε
 * 3. O δείκτης πίνακα που βρίσκεται η τιμή ζητάμε
 */
void retrieve (double array[], double *retrieved_number, int index)
{
  /* Αποθηκεύουμε την τιμή που βρίσκεται στο συγκεκριμένο index του πίνακα σε 
   * συγκεκριμένη θέση μνήμης.
   */
  *retrieved_number = array[index];
}

/*
 * Ανάθεσε την τιμή που δώθηκε ως δεύτερη παράμετρος στη θέση index του πίνακα 
 * array
 */
void update (double array[], double new_value, int index)
{
  array[index] = new_value;
}

/*
 * Πρόσθεσε δύο πίνακες και αποθήκευσε το αποτέλεσμα σε έναν τρίτο πίνακα
 * A = B + C
 */
void add_arrays (double resultA[], double arrayB[], double arrayC[])
{
  /* Τοπικές μεταβλητές που χρησιμοποιούνται στο βρόγχο
   */
  double valueB;
  double valueC;

  int i; /* Μεταβλητή που θα χρησιμοποιηθεί στο βρόγχο */
  /* Βρόγχος που περνάει από όλα τα στοιχεία των δύο πινάκων */
  for (i = 0; i < 10; i++)
    {
      /* Πάρε την τιμή από τον πίνακα arrayB με θέση index i και αποθήκευσέ την στην
       * τοπική μεταβλητή valueB */
      retrieve (arrayB, &valueB, i);
      /* Πάρε την τιμή από τον πίνακα arrayC με θέση index i και αποθήκευσέ την στην
       * τοπική μεταβλητή valueC */
      retrieve (arrayC, &valueC, i);
      /* Υπολόγισε το άθροισμα των τοπικών μεταβλητών valueB και valueC και 
       * αποθήκευσέ το στο πίνακα resultC στη θέση index i */ 
      update (resultA, (valueB + valueC), i);
    }
}

/* Βοηθητική συνάρτηση εκτύπωσης ενός πίνακα στο stdout
 * Παράμετροι:
 * 1. Ο πίνακας προς εκτύπωση
 * 2. Το μήκος του πίνακα
 */
void print_array (double array[], int length)
{
  printf ("[ ");
  for (int i = 0; i < length; i++)
    {
      if (i == length - 1)
        {
          printf ("%.2f ] ", array[i]);
        }
      else
        {
          printf ("%.2f, ", array[i]);
        }
    }

  printf ("\n");
}

/* Συνάρτηση δοκιμών */
void test()
{
  printf ("\nThema 1\n\n");

  /* Τύπωσε κάθε πίνακα στο stdout */
  printf ("\nB = ");
  print_array (B, LENGTH);
  printf ("\nC = ");
  print_array (C, LENGTH);

  /* Πρόσθεσε του πίνακες B και C και αποθήκευσε το αποτέλεσμα στον πίνακα A */
  add_arrays (A, B, C);
  printf ("\nPerfoming addition: A = B + C\n");
  printf ("\nA = ");
  print_array (A, LENGTH);
}
