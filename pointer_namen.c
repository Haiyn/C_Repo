#include <stdio.h>
#include <string.h>

int main() {
  char namen[3][5+1];
  //            |             |             |
  //0 1 2 3 4 5 | 0 1 2 3 4 5 | 0 1 2 3 4 5 |
  strcpy(namen[0], "Max");
  //M a x 0     |             |             |
  //0 1 2 3 4 5 | 0 1 2 3 4 5 | 0 1 2 3 4 5 |
  printf("---%s---\n", namen[0]);               //---Max---

  strcpy(namen[1], "Elisabeth");
  //M a x 0     | E l i s a b | e t h 0     |
  //0 1 2 3 4 5 | 0 1 2 3 4 5 | 0 1 2 3 4 5 |
  printf("---%s---\n", namen[1]);               //---Elisabeth---

  strcpy(namen[2], "Horst");
  //M a x 0     | E l i s a b | H o r s t 0 |
  //0 1 2 3 4 5 | 0 1 2 3 4 5 | 0 1 2 3 4 5 |
  printf("---%s---\n", namen[2]);               //---Horst---

  printf("---%s---\n", namen[1]);               //ElisabHorst
  // --> Ein Output aus einem Array stoppt nur bei einer Null
}
