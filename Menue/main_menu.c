#include "./util/card_header.h"

#include "./io/card_load.c"
#include "./io/card_hex.c"
#include "./io/card_write.c"
#include "./edit/card_delete.c"
#include "./edit/card_sort.c"


int main() {
  // STRUCT POINTERS
  t_field field;
  t_field *f = &field;
  f -> mom = 0;
  f -> start = 0;
  f -> last = 0;


  // Call main menu and validate input
  int selection = showMainMenu();
  if(!checkInputSelection(1, 6, selection)) showMainMenu();

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
      mainWrite(f);
      break;
    case 4:
      system("clear");
      importData(f);
      break;
    case 5:
      mainDelete(f);
      break;
    case 6:
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
