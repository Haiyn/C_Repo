#include "../util/header.h"

void searchEntries(t_field *f) {
  system("clear");
  int entryCount, foundEntries = 0;
  char keyword[30], pointerArray[5][30];

  printf("\nEnter 'e' to abort and exit the sub-routine.\n");
  printf("\nWhat would you like to search for? Please enter a keyword: ");
  scanf(" %30[^\n]", keyword);
  fflush(stdin);
  if (keyword[0] == 'e') return;

  clock_t startTime = clock();
  entryCount = loadEntries(f, 4);
  f -> mom = f -> first;

  for(int i = 0; i < entryCount; i++) {
    strcpy(pointerArray[0], f -> mom -> characterName);
    strcpy(pointerArray[1], f -> mom -> cardName);
    strcpy(pointerArray[2], f -> mom -> cardType);
    strcpy(pointerArray[3], f -> mom -> damageNumber);
    strcpy(pointerArray[4], f -> mom -> effectType);
    for(int j = 0; j < 5; j++) {
      if(strcmp(pointerArray[j], keyword) == 0) {
        if(foundEntries == 0) printHeader();
        printf("| [%-2d]  %-20s | %-20s | %-15s | %-10s | %-20s |\n",
                    foundEntries+1,
                    f -> mom -> characterName,
                    f -> mom -> cardName,
                    f -> mom -> cardType,
                    f -> mom -> damageNumber,
                    f -> mom -> effectType);
        foundEntries++;
        break;
        }

      }
    f -> mom = f -> mom -> after;
  }
  printFooter(foundEntries, startTime);
  printf("\n\nWould you like to try searching for something else? [y/n] ");
  if(userQuery()) searchEntries(f);
}

void printHeader() {
    printf("\nFound following entry(s):\n\n");
    printSeparator('-', 107, false);
    printf("| %-4s  %-20s | %-20s | %-15s | %-10s | %-20s |\n",
                "Nr.",
                "Character Name",
                "Card Name",
                "Card Type",
                "Damage",
                "Effects");
    printSeparator('-', 105, true);
}

void printFooter(int foundEntries, int startTime) {
  clock_t endTime = clock();
  if(foundEntries == 0) printf("\nCouldn't find any entries for that keyword.");
  else {
    printSeparator('-', 107, false);
    printf("\nFound %d entry(s).", foundEntries);
  }
  printf("\nSearching finished successfully after %.4f seconds.", (double)(endTime - startTime)/1000);

}
