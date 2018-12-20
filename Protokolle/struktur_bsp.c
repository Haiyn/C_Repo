#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void upDatum();

int main(void) {
  char datum[80+1];
  upDatum(datum);
  printf("\n%s", datum);
  return 1;
}

void upDatum(char *datum) {
  char htext[80+1];
  struct tm *zeit;
  long sec;
  time(&sec);     //Sekunden seite 1.1.1970

  zeit = localtime(&sec);

  switch(zeit -> tm_wday) {
    case 0: strcpy(datum, "Sonntag, den"); break;
    case 1: strcpy(datum, "Montag, den"); break;
    case 2: strcpy(datum, "Dienstag, den"); break;
    case 3: strcpy(datum, "Mittwoch, den"); break;
    case 4: strcpy(datum, "Donnerstag, den"); break;
    case 5: strcpy(datum, "Freitag, den"); break;
    case 6: strcpy(datum, "Samstag, den"); break;
    default: printf("Error");
  }

  itoa(zeit -> tm_mday, htext, 10);

  strcat(datum, htext);
  strcat(datum, ".");

  switch(zeit -> tm_wday) {
    case 0: strcpy(datum, "Januar"); break;
    case 1: strcpy(datum, "Februar"); break;
    case 2: strcpy(datum, "März"); break;
    case 3: strcpy(datum, "April"); break;
    case 4: strcpy(datum, "Mai"); break;
    case 5: strcpy(datum, "Juni"); break;
    case 6: strcpy(datum, "Juli"); break;
    case 7: strcpy(datum, "August"); break;
    case 8: strcpy(datum, "September"); break;
    case 9: strcpy(datum, "October"); break;
    case 10: strcpy(datum, "November"); break;
    case 11: strcpy(datum, "Dezember"); break;
    default: printf("Error");
  }
}
