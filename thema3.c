#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define std_count  5
/* Τα δεδομένα μας θα έχουν τα μαθήματα C++, Data Structures, Logic Programming
 */
const char mathima_filter_name[] = "Data Structures";

/* Εγγράφημα φοιτητή */
struct student
{
    char onoma[30];
    char eponymo[30];
    char patronymo[30];
    char mitronymo[30];
    char dieuthinsi[30];
    char epilegmeno_mathima[30];
    char arithmos_statherou[30];
    char arithmos_kinhtou[30];
};
/* Ορισμός πίνακα εγγραφημάτων φοιτητών */
struct student students[std_count]; /* Αποθηκεύουμε όλους τους φοιτητές */


// Γέμισμα πίνακα με στοιχεία φοιτητών
void fill_it(struct student students[])
{
  int i;
  for (i = 0; i < std_count; i++)
    {
      printf("Dose onoma: ");
      scanf("%s",students[0].onoma);
      printf("Dose eponymo: ");
      scanf("%s",students[0].eponymo);
      printf("Dose patronymo: ");
      scanf("%s",students[0].patronymo);
      printf("Dose mitronymo: ");
      scanf("%s",students[0].mitronymo);
      printf("Dose dieu8unsi: ");
      scanf("%s",students[0].dieuthinsi);
      printf("Dose epilegmeno_mathima: ");
      scanf("%s",students[0].epilegmeno_mathima);
      printf("Dose arithmo_kinhtou: ");
      scanf("%s",students[0].arithmos_kinhtou);
      printf("Dose arithmo_statherou: ");
      scanf("%s",students[0].arithmos_statherou);
      printf("-----------------------------\n\n");
    }
}

/* Αναζήτηση φοιτητών που έχουν επιλέξει ένα συγκεκριμένο μάθημα
 * Παράμετροι:
 * 1. πίνακας με δομές φοιτητών
 * 2. πίνακας συμβολοσειράς για το επιλεγμένο μάθημε
 * Επιστρέφει:
 * δείκτη σε πίνακα δομών φοιτητών που έχουν επιλέξει το συγκεκριμένο μάθημα
 */
struct student **filter_students (struct student students[], const char *epilegmeno_mathima)
{
  struct student **filtered_students = malloc (std_count * sizeof (struct student*));
  
  /* Αρχικοποιούμε τον πίνακα φοιτητών με τον NULL pointer */
  for (int i = 0; i < std_count; ++i)
    {
      filtered_students[i] = NULL;
    }


  for (size_t i = 0; i < std_count; i++)
    {
      if (strcmp (students[i].epilegmeno_mathima, epilegmeno_mathima) == 0)
        {
          //printf("Found %s has selected %s\n", students[i].onoma, students[i].epilegmeno_mathima);
          filtered_students[i] = &students[i];
          //printf ("pointer to struct %lu should be the same saved %ld\n", (size_t) &students[i], (size_t)  filtered_students[i]);

          //printf ("Testing the value that the pointer point to...\n");
          //printf ("Pointer %ld points to struct with onoma %s\n", (size_t) filtered_students[i], filtered_students[i]->onoma);
        }
    }


  return filtered_students;
}

void test  ()
{
  /* Προσθέτουμε δοκιμάστικά δεδομένα για να λειτουργήσει το πρόγραμμα */
  strcpy(students[0].onoma, "Aristotelis");
  strcpy(students[0].eponymo, "Christou");
  strcpy(students[0].patronymo, "Nikolaos");
  strcpy(students[0].mitronymo, "Athina");
  strcpy(students[0].dieuthinsi, "Address 1");
  strcpy(students[0].epilegmeno_mathima, "Data Structures");
  strcpy(students[0].arithmos_kinhtou, "123123213");
  strcpy(students[0].arithmos_statherou, "45234343");

  strcpy(students[1].onoma, "Spyros");
  strcpy(students[1].eponymo, "Christou");
  strcpy(students[1].patronymo, "Nikolaos");
  strcpy(students[1].mitronymo, "Athina");
  strcpy(students[1].dieuthinsi, "Address 2");
  strcpy(students[1].epilegmeno_mathima, "C++");
  strcpy(students[1].arithmos_kinhtou, "123223213");
  strcpy(students[1].arithmos_statherou, "454344343");

  strcpy(students[1].onoma, "Pamina");
  strcpy(students[1].eponymo, "Christou");
  strcpy(students[1].patronymo, "Kostas");
  strcpy(students[1].mitronymo, "Anastasia");
  strcpy(students[1].dieuthinsi, "Address 2");
  strcpy(students[1].epilegmeno_mathima, "Logic Programming");
  strcpy(students[1].arithmos_kinhtou, "123223213");
  strcpy(students[1].arithmos_statherou, "454344343");

  int count = 0;
  struct student **filtered_students = filter_students (students, mathima_filter_name);
  struct student *std;
  /* Παρουσιάζουμε τα αποτελέσματα της αναζήτησης */
  printf ("Presenting search results for lesson: \"%s\"\n", mathima_filter_name);
  while (NULL != (std = filtered_students[count]))
    {
      printf ("%d. %s %s \n", (count + 1), std->onoma, std->eponymo);
      count++;
    }

  free (filtered_students);
}

int main (int argc, char *argv[])
{
  test ();

  return 0;
}
