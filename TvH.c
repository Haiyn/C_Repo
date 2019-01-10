#include <stdio.h>

void up_TvH();

int main() {
  int anzahl = 4, scheibe = anzahl, von = 1, nach = 3;
  up_TvH(scheibe, von, nach);
  return 1;
}

void up_TvH(int scheibe, int von, int nach) {
  int zwischen;
  if(scheibe > 1) {
    zwischen = 6 - von - nach;
    up_TvH(scheibe -1, von, zwischen);
    printf("Scheibe %d: Von %d nach %d\n", scheibe, von, nach);
    up_TvH(scheibe-1, zwischen, nach);
  }
  else {
    printf("Scheibe %d Von %d nach %d\n", scheibe, von, nach);
  }
}
