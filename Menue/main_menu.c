#include "./util/header.h"

#include "./io/load.c"
#include "./io/hex.c"
#include "./io/write.c"
#include "./edit/delete.c"
#include "./edit/sort.c"
#include "./edit/search.c"


int main() {
  // STRUCT POINTERS
  t_field field;
  t_field *f = &field;
  f -> mom = 0;
  f -> first = 0;
  f -> last = 0;


  // Call main menu and validate input
  int selection = selectMainMenuAction();
  if(!checkInputSelection(1, 6, selection)) selectMainMenuAction();

  // run the selected sub-routine
  switch(selection) {
    case 1:
      system("clear");
      mainRead(f);
      break;
    case 2:
      system("clear");
      mainHex(f);
      break;
    case 3:
      system("clear");
      mainSearch(f);
      break;
    case 4:
      system("clear");
      mainWrite(f);
      break;
    case 5:
      system("clear");
      importData(f);
      break;
    case 6:
      mainDelete(f);
      break;
    case 7:
      system("clear");
      exit(0);
    default:
      printf("\n###ERR Input not recognised\n");
      waitForExit();
      break;
  }
  main();
  return 0;
}
