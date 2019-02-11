#include "../util/header.h"

void viewEntries(t_field *f) {
  int entryCount, entryAmount = selectEntryAmount();
  system("clear");
  if(entryAmount == 5) return;
  f -> mom = f -> first;
  if(!f -> mom) entryCount = loadEntries(f, entryAmount);
  else printf("\nEntries loaded. Found %d entries.\n\n\n", entryCount);    //TODO time measurement
  printEntries(f, entryAmount, true);
  selectionMenu(f, entryAmount);
  return;
}

void viewHex(t_field *f) {
  // If the struct ist empty, load all entries (4) to the struct from text file
  if(!f -> mom) {
    bool readSuccess = loadEntries(f, 4);
    if(!readSuccess) {
      printf("\n###ERR Reading process failed at load.c \nWould you like to retry? Enter 0 for no, 1 for yess: ");
      if(userQuery()) viewHex(f);
      else return;
    }
  }
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
  // Keep the menu open until user confirms exit
  waitForExit();
  return;
}




// UI HANDLER

void selectionMenu(t_field *f, int entryAmount) {
  int selection, column, direction;

  // Show the options the user has to proceed and return the choice
  selection = selectProceedAction();
  switch(selection) {
    case 1: // SHOW NEXT 10 ENTRIES
      system("clear");
      printEntries(f, 1, false);
      selectionMenu(f, entryAmount);
      break;
    case 2:
      system("clear");
      return;
    default:
      return;
  }
}
