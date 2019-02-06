#include "../util/header.h"



// UNIVERSAL LOADING & STRUCT ADDING

// Initiates output and sort functions
void mainRead(t_field *f) {
  int entryAmount = selectEntryAmount();
  system("clear");
  if(entryAmount == 5) return;
  f -> mom = f -> first;
  if(!f -> mom) {
    bool readSuccess = loadEntries(f, entryAmount);
    if(!readSuccess) {
      printf("\n###ERR Reading process failed at load.c \nWould you like to retry? Enter 0 for no, 1 for yess: ");
      if(retry()) mainRead(f);
      else return;
    }
  }

  else printf("\n#DEBUG Entries read. Printing %d entries...\n\n\n", entryAmount*10);    //TODO time measurement
  printEntries(f, entryAmount, true);
  selectionMenu(f, entryAmount);
  return;
}

// Reads the entries from the txt file and loads them into the struct
bool loadEntries(t_field *f, int entryAmount) {
  entryCount = 0;
  printf("#DEBUG Read process started. Creating pointers...\n");
  FILE *fp;
  fp = fopen("./data/data.txt", "a+");
  if(!validateFile(fp, "loadEntries")) {
    waitForExit();
    return false;
  }

  printf("#DEBUG Pointers created. Scanning file...\n");
  while(!feof(fp)) {
    fscanf(fp, "%[^/]/%[^/]/%[^/]/%[^/]/%[^\n]\n", f -> characterName, f -> cardName, f -> cardType, f -> damageNumber, f -> effectType);
    listAdd(f);
    entryCount++;
  }
  fclose(fp);
  printf("#DEBUG Scanning completed. Found %d entries.\n", entryCount);
  return true;
}

void listAdd(t_field *f) {
  f -> mom = (t_card*)malloc(sizeof(t_card));      // reserves the size of the struct in main memeory, typecast needed because malloc's return value is a void pointer
  addEntry(f);
  f -> mom -> before = f -> last;
  f -> mom -> after = 0;
  if(f -> last == 0)  f -> first = f -> mom;
  else f -> last -> after = f -> mom;
  f -> last = f -> mom;
}

void addEntry(t_field *f) {
  strcpy(f -> mom -> characterName, f -> characterName);
  strcpy(f -> mom -> cardName, f -> cardName);
  strcpy(f -> mom -> cardType, f -> cardType);
  strcpy(f -> mom -> damageNumber, f -> damageNumber);
  strcpy(f -> mom -> effectType, f -> effectType);
}


// OUPTUT

void printEntries(t_field *f, int entryAmount, bool firstCall) {
  if(firstCall) f -> mom = f -> first;
  printSeparator('-', 107, false);
  printf("| %-4s  %-20s | %-20s | %-15s | %-10s | %-20s |\n",
              "Nr.",
              "Character Name",
              "Card Name",
              "Card Type",
              "Damage",
              "Effects");
  printSeparator('-', 105, true);
  for(int i = 0, index = 1; i < entryAmount*10; i++, index++) {
    if(entryAmount == 4) i = 0;
    if(!f -> mom) break;
    printf("| [%-2d]  %-20s | %-20s | %-15s | %-10s | %-20s |\n",
                index,
                f -> mom -> characterName,
                f -> mom -> cardName,
                f -> mom -> cardType,
                f -> mom -> damageNumber,
                f -> mom -> effectType);

    f -> mom = f -> mom -> after;
  }
  printSeparator('-', 107, false);
}


// UI HANDLER

void selectionMenu(t_field *f, int entryAmount) {
  int selection, column, direction, sortType;

  // Show the options the user has to proceed and return the choice
  selection = selectProceedAction();
  switch(selection) {
    case 1: // SHOW NEXT 10 ENTRIES
      system("clear");
      printEntries(f, 1, false);
      selectionMenu(f, entryAmount);
      break;
    case 2: // SORT ENTRIES
      // Show the different settings menus
      column = selectSortColumn();
      if(column == 5) return;
      direction = selectSortDirection();
      if(direction == 3) return;
      sortType = selectSortType();
      // select sort type (bubble or quicksort)
      switch(sortType) {
        case 1: mainSort(f, column, direction, sortType, entryAmount);//bubblesort(f, column, direction);
        case 2: //quicksort(f, column, direction);
        case 3: return;
      }
      printEntries(f, entryAmount, false);
      break;
    case 3:
      system("clear");
      return;
    default:
      return;
  }
}


// DATA IMPORT

void importData(t_field *f) {
  FILE *fp;
  char path[80];
  int selection = selectImportFile();
  switch(selection) {
    case 1:
      fp = fopen("./data/import.txt", "r");
      break;
    case 2:
      printf("\nPlease enter the file path (relative to load.c): ");
      scanf(" %s", path);
      fp = fopen(path, "r");
      break;
    case 3:
      return;
    default:
      return;
  }
  if(!validateFile(fp, "readImportFile")) {
    printf("Would you like to retry? [y/n]\n");
    if(retry()) importData(f);
    else return;
  }
  while(!feof(fp)) {
    char firstChar = fgetc(fp);
    if(firstChar == '*') {
      printf("\n#DEBUG Detected comment line.");
      while(fgetc(fp) != '\n') {
        fseek(fp, 1, SEEK_CUR);
      }
    }
    else  {
      ungetc(firstChar, fp);
      printf("\n#DEBUG Detected data line.");
      fscanf(fp, "%[^/]/%[^/]/%[^/]/%[^/]/%[^\n]\n", f -> characterName, f -> cardName, f -> cardType, f -> damageNumber, f -> effectType);
      printf("\nENTRY: %s%s%s%s%s", f -> characterName, f -> cardName, f -> cardType, f -> damageNumber, f -> effectType);
      listAdd(f);   // adds the read entry to the struct
      addData(f);   // writes the entry to data.txt
    }
  }
  fclose(fp);
  if(selection == 1) resetImportFile();    // reformats the import.txt
  waitForExit();
}
