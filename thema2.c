#include <stdio.h>
#include <stdlib.h>

void print_source (int from, int to);
void print_array_info (long long arr[3][2][1][2]);
int main (int argc, char *argv[])
{
  long long int A[3][2][1][2] =
      {
          {
              { { 0, 1 } },
              { { 2, 3 } }
          },
          {
              { { 4, 5 } },
              { { 6, 7 } }
          },
          {
              { { 8, 9 } },
              { { 10, 11 } }
          }
      }; // Τέλος αρχικοποίησης πίνακα 4 διαστάσεων

  printf ("Thema2: Calculate the addresses and offsets of a 4-dimansional array \n\n");

  /* Τύπωσε την αρχικοποίηση του 4 διάστατου πίνακα στο stdout
   * (Κώδικας από της γραμμές 8 έως 22)
   */
  print_source (8, 22);

  /* Τύπωσε τα indexes του κάθε στοιχείου του πίνακα με την τιμή, διεύθυνση και
   * offset από την διεύθυνση βάσης.
   */
  print_array_info (A);
  return 0;
}

void print_array_info (long long int arr[3][2][1][2])
{
  long long base = &arr[0][0][0][0];
  printf ("\nBase address:  %llu\n\n", base);

  printf ("%-16s %s %13s %s\n", "Element index", "Value", "Address", "Offset");
  printf ("-------------------------------------------\n");
  for (int i = 0; i < 3; ++i)
    {
      for (int j = 0; j < 2; ++j)
        {
          for (int k = 0; k < 1; ++k)
            {
              for (int l = 0; l < 2; ++l)
                {
                  printf ("arr[%d][%d][%d][%d] %5lld %15lld %5lld\n", i, j, k, l,
						arr[i][j][k][l], // Τιμή πίνακα
						&arr[i][j][k][l], // Διεύθυνση πίνακα
            // Υπολόγισε το offset από τη διεύθυνση βάσης
						(unsigned long long) ((&arr[i][j][k][l] - &arr[0][0][0][0]) * sizeof (arr[0][0][0][0])));
                }
            }
        }
    }
  puts ("");
} /* Τέλος της συνάρτησης print_array_info */

/* Βοηθητική συνάρτηση εκτύπωσης μέρους του κώδικα του προγράμματος στο stdout
 */
void print_source (int from, int to)
{
  char line[150];
  FILE *source;

  /* Άνοιξε το τρέχων αρχείο κώδικα για διάβασμα */
  source = fopen (__FILE__, "r");
  if (source == NULL)
    {
      printf ("Couldn't open %s for reading.\nExiting.\n", __FILE__);
      exit (-1);
    }

  int l_count = 0;
  while (fgets (line, 150, source) != NULL)
    {
      l_count++;
      /* Αν ο μετρητής είναι μεταξύ των παραμέτρων from και to τότε τύπωσε το
       * buffer στο stdout */
      if (l_count >= from && l_count <= to)
        puts (line);
    }

  /* Κλείσε το αρχείο */
  fclose (source);
}
