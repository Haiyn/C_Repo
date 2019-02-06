#include "../util/header.h"

void mainHex(t_field *f) {
  // If the struct ist empty, load all entries (4) to the struct from text file
  if(!f -> mom) {
    bool readSuccess = loadEntries(f, 4);
    if(!readSuccess) {
      printf("\n###ERR Reading process failed at load.c \nWould you like to retry? Enter 0 for no, 1 for yess: ");
      if(retry()) mainRead(f);
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
