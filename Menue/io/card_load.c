#include "../util/card_header.h"

void mainRead(t_field *f) {
  int entryAmount = showEntryAmountMenu();
  if(entryAmount == 5) return;
  f -> mom = f -> start;
  if(!f -> mom) {
    bool readSuccess = loadEntries(f, entryAmount);
    if(!readSuccess) {
      printf("\n###ERR Reading process failed at card_load.c \nWould you like to retry? Enter 0 for no, 1 for yess: ");
      if(retry()) mainRead(f);
      else return;
    }
  }

  else printf("\n#DEBUG Entries read. Printing %d entries...\n\n\n", entryAmount*10);    //TODO time measurement
  printEntries(f, entryAmount, true);
  selectionMenu(f, entryAmount);
  return;
}



// DATA IMPORT

void txtRead(t_field *f) {

}



// UNIVERSAL LOADING & STRUCT ADDING

// Reads the entries from the txt file and loads them into the struct
bool loadEntries(t_field *f, int entryAmount) {
  printf("#DEBUG Read process started. Creating pointers...\n");
  FILE *fp;
  fp = fopen("./data/card_data.txt", "a+");
  if(!fp) {
    printf("###ERR at loadEntries: File not found.");
    waitForExit();
    return false;
  }

  printf("#DEBUG Pointers created. Scanning file...\n");
  while(!feof(fp)) {
    fscanf(fp, "%[^/]/%[^/]/%[^/]/%[^/]/%[^\n]\n", f -> characterName, f -> cardName, f -> cardType, f -> damageNumber, f -> effectType);
    listAdd(f);
    /*strncpy(f -> characterName, entry, CHARACTER_NAME_LN);
    strncpy(f -> cardName, entry + CHARACTER_NAME_LN, CARD_NAME_LN);
    strncpy(f -> cardType, entry + CHARACTER_NAME_LN + CARD_NAME_LN, CARD_TYPE_LN);
    strncpy(f -> damageNumber, entry + CHARACTER_NAME_LN + CARD_NAME_LN + CARD_TYPE_LN, DAMAGE_NUMBER_LN);
    strncpy(f -> effectType, entry + CHARACTER_NAME_LN + CARD_NAME_LN + CARD_TYPE_LN + DAMAGE_NUMBER_LN, EFFECT_TYPE_LN);
    listAdd(f);*/
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
  if(f -> last == 0)  f -> start = f -> mom;
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
  if(firstCall) f -> mom = f -> start;
  printf("%-4s   %-20s %-20s %-15s %-10s %-20s\n",
              "Nr.",
              "Character Name",
              "Card Name",
              "Card Type",
              "Damage",
              "Effects\n");
  for(int i = 0, index = 1; i < entryAmount*10; i++, index++) {
    if(entryAmount == 4) i = 0;
    if(f -> mom == 0) {
      printf("\n\n#DEBUG End of entries. Terminated print loop.\n");
      break;
    }
    printf("[%-2d]   %-20s %-20s %-15s %-10s %-20s\n",
                index,
                f -> mom -> characterName,
                f -> mom -> cardName,
                f -> mom -> cardType,
                f -> mom -> damageNumber,
                f -> mom -> effectType);

    f -> mom = f -> mom -> after;
  }
}


// UI HANDLER

void selectionMenu(t_field *f, int entryAmount) {
  int selection, column, direction, sortType;

  // Show the options the user has to proceed
  selection = showProceedSelectionMenu();
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
      break;
  }
}
