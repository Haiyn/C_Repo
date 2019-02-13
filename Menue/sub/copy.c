#include "../util/header.h"

// lets the user pick an entry to duplicate and edit
void copyEntries(t_field *f) {
  int i = 0, column, entryCount;
  int entry;
  entryCount = loadEntries(f, 4);
  InitPrintEntries(f, 4);

  printf("\nWhich entry would you like to copy? Please enter a number: ");
  scanf("%d", &entry);
  if(!checkInputSelection(1, entryCount, entry)) waitForExit();
  f -> mom = f -> first;
  while(i < entry - 1) {
    f -> mom = f -> mom -> after;
    i++;
  }

  strcpy(f -> characterName, f -> mom -> characterName);
  strcpy(f -> cardName, f -> mom -> cardName);
  strcpy(f -> cardType, f -> mom -> cardType);
  strcpy(f -> damageNumber, f -> mom -> damageNumber);
  strcpy(f -> effectType, f -> mom -> effectType);
  printf("\n\nYou selected:\t%-20s  %-20s  %-15s  %-10s  %-20s",
              f -> characterName,
              f -> cardName,
              f -> cardType,
              f -> damageNumber,
              f -> effectType);

  printf("\n\nWould you like to edit the entry before duplicating it? [y/n] ");
  if(userQuery()) editEntry(f);
  else addData(f);
  printf("\nEntry added:\t%-20s  %-20s  %-15s  %-10s  %-20s",
              f -> characterName,
              f -> cardName,
              f -> cardType,
              f -> damageNumber,
              f -> effectType);
  waitForExit();
}


// if the entry is supposed to be edit before copying, edit it as many times as the user wants
void editEntry(t_field *f) {
  int selection;
  char edit[30];
  selection = selectEditColumn();

  printf("What do you want to replace the value with? Please enter a value: ");
  scanf(" %[^\n]", edit);

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

  printf("\nWould you like to edit another column before duplicating it? [y/n] ");
  if(userQuery()) editEntry(f);
  else addData(f);
}
