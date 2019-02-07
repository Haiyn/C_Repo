#include "./util/header.h"

#include "./io/input.c"
#include "./io/output.c"
#include "./edit/delete.c"
#include "./edit/sort.c"
#include "./edit/search.c"
#include "./util/data_functions.c"


int main() {
  // STRUCT POINTERS
  t_field field;
  t_field *f = &field;
  f -> mom = 0;
  f -> first = 0;
  f -> last = 0;


  // Call main menu and validate input
  int selection = selectMainMenuAction();
  if(!checkInputSelection(1, 7, selection)) selectMainMenuAction();

  // run the selected sub-routine
  switch(selection) {
    case 1:
      system("clear");
      viewEntries(f);
      break;
    case 2:
      system("clear");
      printHex(f);
      break;
    case 3:
      system("clear");
      mainSearch(f);
      break;
    case 4:
      system("clear");
      inputEntry(f);
      break;
    case 5:
      system("clear");
      importData(f);
      break;
    case 6:
      deleteEntries(f);
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
