#include "card_header.h"

// UI MENUS
int showMainMenu() {
  system("clear");
  int selection;
  printSeparator('-', 65, false);
  printf("|\t\t\t\t\t\t\t\t|\n");                                 // 2 | chars + 5 horizontal tabs (5*8 whitespaces)
  printf("|\tChoose a sub-routine:\t\t\t\t\t|\n");
  printf("|\t\t\t\t\t\t\t\t|\n");
  printSeparator('-', 63, true);
  printf("|\t\t\t\t\t\t\t\t|\n");
  printf("|   [1] Show & sort entries\t\t\t\t\t|\n");
  printf("|         Show and sort saved entries.\t\t\t\t|\n");
  printf("|\t\t\t\t\t\t\t\t|\n");
  printf("|   [2] Show pointers\t\t\t\t\t\t|\n");
  printf("|         Shows the pointers (hex) of all entries.\t\t|\n");
  printf("|\t\t\t\t\t\t\t\t|\n");
  printf("|   [3] Add new entries\t\t\t\t\t\t|\n");
  printf("|         Open the prompt that lets you add new entries.\t|\n");
  printf("|\t\t\t\t\t\t\t\t|\n");
  printf("|   [4] Import data\t\t\t\t\t\t|\n");
  printf("|         Import data from a formatted file.\t\t\t|\n");
  printf("|\t\t\t\t\t\t\t\t|\n");
  printf("|   [5] Delte existing entries\t\t\t\t\t|\n");
  printf("|         Choose an entry to delete it.\t\t\t\t|\n");
  printf("|\t\t\t\t\t\t\t\t|\n");
  printf("|   [6] Exit menu\t\t\t\t\t\t|\n");
  printf("|\t\t\t\t\t\t\t\t|\n");
  printSeparator('-', 65, false);
  printf("Please enter a number: ");
  scanf("%d", &selection);
  fflush(stdin);
  return selection;
}

int showEntryAmountMenu() {
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
  return entryAmount;
}

// PROCEED AFTER SHOWING ENTRIES
int selectProceedAction() {
  int selection;
  printf("\n\nWhat would you like to do?");
  printf("\n  [1] Show next 10 entries");
  printf("\n  [2] Sort entries");
  printf("\n  [3] Return to the main menu");
  printf("\n\nPlease enter a number: ");

  scanf("%d", &selection);
  fflush(stdin);
  if(!checkInputSelection(1, 3, selection)) selectProceedAction();

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
  printf("\n  [4] Effect Type");
  printf("\n  [5] Exit");
  printf("\n\nPlease enter a number: ");
  scanf("%d", &column);
  if(!checkInputSelection(1, 5, column))  selectSortColumn();
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

int selectSortType() {
  int sortType;
  printf("\n\nSort Method:");
  printf("\n  [1] Use Bubblesort");
  printf("\n  [2] Use Quicksort");
  printf("\n  [3] Exit");
  printf("\n\nPlease enter a number: ");
  scanf("%d", &sortType);
  if(!checkInputSelection(1, 3, sortType)) selectSortType();
  return sortType;
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
