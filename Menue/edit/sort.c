#include "../util/header.h"

void mainSort(t_field *f, int column, int direction, int sortType, int entryAmount) {
  printf("\n#DEBUG mainSort");
  switch(sortType) {
    case 1:
      bubblesort(f, column, direction);

      break;
    case 2:
      //quicksort();
      break;
    default:
      printf("\n\n###ERR Not a sortType");
      break;
  }
}

void bubblesort(t_field *f, int column, int direction, int entryAmount) {
  printf("\n#DEBUG Bubblesort in progress.");
  clock_t startTime = clock();
  f -> mom = f->  first;
  for (int i = 0; i < entryCount - 1; i++) {
    printf(".");
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
          printf("\n\n###ERR Column seletion failed.");
          waitForExit();
          return;
      }
      f -> mom = f -> mom -> after;
    }
    f -> mom = f -> first;
  }
  clock_t endTime = clock();
  printf("\n#DEBUG Sorting finished successfully after %.4f seconds.\n\n", (double)(endTime - startTime)/1000);
  printEntries(f, entryAmount, false);
  selectionMenu(f, entryAmount);

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
