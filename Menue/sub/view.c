#include "../util/header.h"

// shows a selected amount of entries
void viewEntries(t_field *f) {
  int entryCount, entryAmount = selectEntryAmount();
  system("clear");
  if(entryAmount == 5) return;

  f -> mom = f -> first;
  if(!f -> mom) entryCount = loadEntries(f, entryAmount);
  else printf("\nEntries loaded. Found %d entries.\n\n\n", entryCount);    //TODO time measurement
  InitPrintEntries(f, entryAmount);
  selectionMenu(f, entryAmount);
  return;
}


// shows all entries and their pointers
void viewHex(t_field *f) {
  int entryCount = loadEntries(f, 4);
  int i = 1;
  f -> mom = f -> first;

  printSeparator('-', 143, false);
  printf("| %-4s %-12s | %-20s | %-10s | %-10s | %-20s | %-15s %-15s %-15s |\n",
                "Nr.",
                "Char. Name",
                "Card Name",
                "Card Type",
                "Damage",
                "Effects",
                "BEFORE",
                "MOM",
                "AFTER");
  printSeparator('-', 141, true);
  while (f -> mom != 0) {
    printf("| [%-2d] %-12s | %-20s | %-10s | %-10s | %-20s | %-15p %-15p %-15p |\n",
                  i,
                  f -> mom -> characterName,
                  f -> mom -> cardName,
                  f -> mom -> cardType,
                  f -> mom -> damageNumber,
                  f -> mom -> effectType,
                  f -> mom -> before,
                  f -> mom,
                  f -> mom -> after);
    f -> mom = f -> mom -> after;
    i++;
  }
  printSeparator('-', 143, false);

  printf("\nEntries loaded. Found %d entries.\n\n\n", entryCount);
  // Keep the menu open until user confirms exit
  waitForExit();
  return;
}



// UI HANDLER
// handles the proceed action
void selectionMenu(t_field *f, int entryAmount) {
  int selection, column, direction;
  // Show the options the user has to proceed and return the choice
  selection = selectProceedAction();
  switch(selection) {
    case 1: // SHOW NEXT 10 ENTRIES
      system("clear");
      printEntries(f, 1);
      selectionMenu(f, entryAmount);
      break;
    case 2: // EXIT TO MAIN MENU
      system("clear");
      return;
    default:
      return;
  }
}
