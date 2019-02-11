#include "../util/header.h"

void copyEntries(t_field *f) {
  int i, entryIndex, column, entryCount;
  entryCount = loadEntries(f, 4);
  printEntries(f, 4, true);
  printf("\nWhich entry would you like to copy? Please enter a number: ");
  scanf("%d", &entryIndex);
  fflush(stdin);
  if(!checkInputSelection(1, entryCount, entryIndex)) waitForExit();

  f -> mom = f -> first;
  while(i < entryIndex - 1) {
    f -> mom = f -> mom -> after;
  }
  strcpy(f -> characterName, f -> mom -> characterName);
  strcpy(f -> cardName, f -> mom -> cardName);
  strcpy(f -> cardType, f -> mom -> cardType);
  strcpy(f -> damageNumber, f -> mom -> damageNumber);
  strcpy(f -> effectType, f -> mom -> effectType);
  printf("\nYou selected:\t%-20s  %-20s  %-15s  %-10s  %-20s",
              f -> characterName,
              f -> cardName,
              f -> cardType,
              f -> damageNumber,
              f -> effectType);
  printf("\nWould you like to edit the entry before duplicating it? [y/n] ");
  if(userQuery()) editEntry(f);
  else addData(f);
}

void editEntry(t_field *f) {
  int selection;
  char edit[30];
  selection = selectEditColumn();
  printf("What do you want to replace the value with? Please enter a value: ");
  scanf(" %[^\n]", edit);
  fflush(stdin);
  switch(selection) {
    case 1:
      strcpy(f -> characterName, edit);
      break;
    case 2:
      strcpy(f -> cardName, edit);
      break;
    case 3:
      strcpy(f -> cardType, edit);
      break;
    case 4:
      strcpy(f -> damageNumber, edit);
      break;
    case 5:
      strcpy(f -> effectType, edit);
      break;
    case 6:
      return;
  }
  addData(f);
  printf("Entry edited and added to save file.");
}
