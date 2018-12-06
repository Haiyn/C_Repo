#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void) {
  int i;
  char wert = 120;

  for(i = 0; i <= 20; i++, wert++) {
    printf("\n %5d", wert);
  }

  return(0);
}
