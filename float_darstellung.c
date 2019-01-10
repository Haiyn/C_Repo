#include <stdio.h>
#include <stdlib.h>
#include "./functions/itoa.c"

struct {
  int i;
  float f;
  unsigned char c[4];
}zahl;

int main() {
  /*printf("Eingabe der Gleitkommazahl: ");
  scanf("%f", &zahl.f);
  fflush(stdin);
  printf("\neingegebene Zahl: %f", zahl.f);*/
  zahl.f = 12.625;
  char htext[80+1];
  strcpy(htext, itoa(zahl.c[1], htext, 2));
  printf("%c", &htext);
  return 0;
}
