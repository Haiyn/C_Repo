#include "./util/header.h"

#include "./sub/add.c"
#include "./sub/copy.c"
#include "./sub/delete.c"
#include "./sub/import.c"
#include "./sub/search.c"
#include "./sub/sort.c"
#include "./sub/view.c"
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
  system("clear");
  // run the selected sub-routine
  switch(selection) {
    case 1:
      viewEntries(f);
      break;
    case 2:
      viewHex(f);
      break;
    case 3:
      searchEntries(f);
      break;
    case 4:
      sortEntries(f);
      break;
    case 5:
      inputEntries(f);
      break;
    case 6:
      copyEntries(f);
      break;
    case 7:
      importEntries(f);
      break;
    case 8:
      deleteEntries(f);
      break;
    case 9:
      exit(0);
    default:
      printf("\n###ERR Input not recognised\n");
      waitForExit();
      break;
  }
  main();
  return 0;
}
