#include <stdio.h>
#include <string.h>

int maint() {
  strcpy(text, "Haus");           //kopiert zweiten Parameter in den ersten
  //Prototyp: char * strcpy(char*, char*)
  strcpy(text_var, text_var2);    //Beide Parameter können variablen sein


  strncpy(t2, t1, 3);             //Der Dritte Parameter begrenzt die Länge von t1

  strcpy(t1, "Hannes");
  strcpy(t2, " ist schlau.");
  strcat(t1, t2);                 //Fügt t2 an t1 an --> "Hannes ist schlau."

  strncat(t1, t2, 4);             //Begrenzt die Einfügung auf 4 Zeichen --> "Hannes ist"

  int length;
  length = strlen("Hannes");      //Gibt die Länge des Strings aus --> length = 4

  char t1[]= "Hugo";
  strrev(t1);                     //Kehr string um --> "oguH"

  char* z;
  z = strtok(t1, "ist");          //Gibt ersten Auftritt von den einzelnen Characters von "ist" (i, s, t) zurück
  z = strstr(t1, "ist");          //Gibt ersten Auftritt von "ist" zurück

  int rc;
  t1 = "Hugo";
  t2 = "Hugo";
  t3 = "HuGo";
  rc = strcmp(t1, t2);            //Vergleicht (subtrahiert) zwei Strings. Wenn gleich, dann 0: Hugo\0 - Hugo\0 = 00000
  rc = strcmp(t1, t3);            // Hugo\0 - HuGo\0 = 0032BREAK --> 32 > 0 --> rc > 0

}
