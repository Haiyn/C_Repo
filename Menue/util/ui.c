#include "header.h"

// UI MENUS
int selectMainMenuAction() {
  system("clear");
  int selection;
  printSeparator('-', 65, false);
  printSeparator(' ', 63, true);                                // 2 | chars + 5 horizontal tabs (5*8 whitespaces)
  printf("|\tChoose a sub-routine:\t\t\t\t\t|\n");
  printSeparator(' ', 63, true);
  printSeparator('-', 63, true);
  printSeparator(' ', 63, true);
  printf("|   [1] View entries\t\t\t\t\t\t|\n");
  printf("|         View saved entries.\t\t\t\t\t|\n");
  printSeparator(' ', 63, true);
  printf("|   [2] View pointers\t\t\t\t\t\t|\n");
  printf("|         View the pointers (hex) of all entries.\t\t|\n");
  printSeparator(' ', 63, true);
  printf("|   [3] Search for entries\t\t\t\t\t|\n");
  printf("|         Enter a keyword to find corresponding entries.\t|\n");
  printSeparator(' ', 63, true);
  printf("|   [4] Sort entries\t\t\t\t\t\t|\n");
  printf("|         Sort saved entries.\t\t\t\t\t|\n");
  printSeparator(' ', 63, true);
  printf("|   [5] Add new entries\t\t\t\t\t\t|\n");
  printf("|         Open the prompt that lets you add new entries.\t|\n");
  printSeparator(' ', 63, true);
  printf("|   [6] Copy entry\t\t\t\t\t\t|\n");
  printf("|         Choose an entry to duplicate (and edit).\t\t|\n");
  printSeparator(' ', 63, true);
  printf("|   [7] Import data\t\t\t\t\t\t|\n");
  printf("|         Import data from a formatted file.\t\t\t|\n");
  printSeparator(' ', 63, true);
  printf("|   [8] Delte existing entries\t\t\t\t\t|\n");
  printf("|         Choose an entry to delete it.\t\t\t\t|\n");
  printSeparator(' ', 63, true);
  printf("|   [9] Exit menu\t\t\t\t\t\t|\n");
  printSeparator(' ', 63, true);
  printSeparator('-', 65, false);
  printf("Please enter a number: ");
  scanf("%d", &selection);
  fflush(stdin);
  if(!checkInputSelection(1, 9, selection)) selectMainMenuAction();
  return selection;
}

int selectEntryAmount() {
  int entryAmount;
  printf("\nHow many entries would you like to show?");
  printf("\n\t[1] 10");
  printf("\n\t[2] 20");
  printf("\n\t[3] 30");
  printf("\n\t[4] All");
  printf("\n\t[5] Return to the main menu");
  printf("\nPlease enter a number: ");
  scanf("%d", &entryAmount);
  fflush(stdin);
  if(!checkInputSelection(1, 5, entryAmount)) selectEntryAmount();
  return entryAmount;
}

// PROCEED AFTER SHOWING ENTRIES
int selectProceedAction() {
  int selection;
  printf("\n\nWhat would you like to do?");
  printf("\n  [1] Show next 10 entries");
  printf("\n  [2] Return to the main menu");
  printf("\n\nPlease enter a number: ");
  scanf("%d", &selection);
  fflush(stdin);
  if(!checkInputSelection(1, 2, selection)) selectProceedAction();

  return selection;
}

// SORT SETTINGS MENU
int selectSortColumn() {
  int column;
  printf("\n\nSort by:");
  printf("\n  [1] Character Name");
  printf("\n  [2] Card Name");
  printf("\n  [3] Card Type");
  printf("\n  [4] Damage Number");
  printf("\n  [5] Effect Type");
  printf("\n  [6] Exit");
  printf("\n\nPlease enter a number: ");
  scanf("%d", &column);
  if(!checkInputSelection(1, 6, column))  selectSortColumn();
  return column;
}

int selectSortDirection() {
  int direction;
  printf("\n\nSort Direction:");
  printf("\n  [1] Sort descening  [Z-A, 9-0]");
  printf("\n  [2] Sort ascending [A-Z, 0-9]");
  printf("\n  [3] Exit");
  printf("\n\nPlease enter a number: ");
  scanf("%d", &direction);
  if(!checkInputSelection(1, 3, direction)) selectSortDirection();
  return direction;
}

int selectEditColumn() {
  int selection;
  printf("\n\nColumn you want to edit:");
  printf("\n  [1] Character Name");
  printf("\n  [2] Card Name");
  printf("\n  [3] Card Type");
  printf("\n  [4] Damage Number");
  printf("\n  [5] Effect Type");
  printf("\n  [6] Exit");
  printf("\n\nPlease enter a number: ");
  scanf("%d", &selection);
  if(!checkInputSelection(1, 6, selection)) selectSortDirection();
  return selection;
}


// PICK IMPORT PATH
int selectImportFile() {
  int selection;
  printf("\n\nChoose the import file:");
  printf("\n  [1] default import file (/data/import.txt)");
  printf("\n  [2] Enter costum file path");
  printf("\n  [3] Exit");
  printf("\n\nPlease enter a number: ");
  scanf("%d", &selection);
  if(!checkInputSelection(1, 3, selection)) selectImportFile();
  return selection;
}
