#include "../util/header.h"

void sortEntries(t_field *f) {
  int column, direction, entryCount;
  entryCount = loadEntries(f, 4);
  column = selectSortColumn();
  if(column == 5) return;
  direction = selectSortDirection();
  if(direction == 3) return;
  bubblesort(f, column, direction, entryCount);
  system("clear");
  InitPrintEntries(f, 4);
}

void bubblesort(t_field *f, int column, int direction, int entryCount) {
  clock_t startTime = clock();
  f -> mom = f->  first;
  for (int i = 0; i < entryCount - 1; i++) {
    for (int j = 0; j < entryCount - 1; j++) {
      switch(column) {
        case 1:   // Character Name
          if(direction == 1) {
            if(strcmp(f -> mom -> characterName, f-> mom -> after -> characterName) < 0) switchEntries(f);
          } else if(strcmp(f -> mom -> characterName, f-> mom -> after -> characterName) > 0) switchEntries(f);
          break;
        case 2:   // Card Name
          if(direction == 1) {
            if(strcmp(f -> mom -> cardName, f-> mom -> after -> cardName) < 0) switchEntries(f);
          } else if(strcmp(f -> mom -> cardName, f-> mom -> after -> cardName) > 0) switchEntries(f);
          break;
        case 3:   // Card Type
          if(direction == 1) {
            if(strcmp(f -> mom -> cardType, f-> mom -> after -> cardType) < 0) switchEntries(f);
          } else if(strcmp(f -> mom -> cardType, f-> mom -> after -> cardType) > 0) switchEntries(f);
          break;
        case 4:   // Damage Number
          if(direction == 1) {
            if(strcmp(f -> mom -> damageNumber, f-> mom -> after -> damageNumber) < 0) switchEntries(f);
          } else if(strcmp(f -> mom -> damageNumber, f-> mom -> after -> damageNumber) > 0) switchEntries(f);
          break;
        case 5:   // Effects
          if(direction == 1) {
            if(strcmp(f -> mom -> effectType, f-> mom -> after -> effectType) < 0) switchEntries(f);
          } else if(strcmp(f -> mom -> effectType, f-> mom -> after -> effectType) > 0) switchEntries(f);
          break;
        default:
          printf("\n\n###ERR at sort.c: Column seletion failed.");
          waitForExit();
          return;
      }
      f -> mom = f -> mom -> after;
    }
    f -> mom = f -> first;
  }
  clock_t endTime = clock();
  printf("\nSorting finished successfully after %.4f seconds.\n\n", (double)(endTime - startTime)/1000);
  InitPrintEntries(f, 4);

  printf("Would you like to sort again? [y/n] ");
  if(userQuery()) sortEntries(f);
  return;
}

void switchEntries(t_field *f) {
  char cache[30];
  strcpy(cache, f -> mom -> characterName);
  strcpy(f -> mom -> characterName, f -> mom -> after -> characterName);
  strcpy(f -> mom -> after -> characterName, cache);

  strcpy(cache, f -> mom -> cardName);
  strcpy(f -> mom -> cardName, f -> mom -> after -> cardName);
  strcpy(f -> mom -> after -> cardName, cache);

  strcpy(cache, f -> mom -> cardType);
  strcpy(f -> mom -> cardType, f -> mom -> after -> cardType);
  strcpy(f -> mom -> after -> cardType, cache);

  strcpy(cache, f -> mom -> damageNumber);
  strcpy(f -> mom -> damageNumber, f -> mom -> after -> damageNumber);
  strcpy(f -> mom -> after -> damageNumber, cache);

  strcpy(cache, f -> mom -> effectType);
  strcpy(f -> mom -> effectType, f -> mom -> after -> effectType);
  strcpy(f -> mom -> after -> effectType, cache);

}
