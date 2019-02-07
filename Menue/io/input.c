#include "../util/header.h"

// DATA READING (USER INPUT)

void inputEntry(t_field *f) {
  system("clear");

  printf("#DEBUG Starting read process...\n");

  bool aborted = readInputData(f);
  if(aborted) return;                   // if the action was aborted, return to the main menu
  printf("\n#DEBUG Read process finished. Starting write process...\n");
  addData(f);
  printf("#DEBUG Data writing finished.\n");

  printf("Would you like to add another entry? [y/n] ");
  if(userQuery())  {
    memset(&card, 0, sizeof(card));     // reset the memory of the struct to avoid false data from previous input
    inputEntry(f);
  }
}

// Read data from user input
bool readInputData(t_field *f) {
  fflush(stdin);
  printf("\nEnter 'e' to abort and exit the sub-routine.\n");
  printf("\nPlease enter a character name: ");
  scanf(" %10[^\n]", f -> characterName);
  fflush(stdin);
  if(f -> characterName[0] == 'e') return true;       // if character 'e' was entered, abort the process and return to the main menu

  printf("\nPlease enter a card name: ");
  scanf(" %30[^\n]", f -> cardName);
  fflush(stdin);
  if(f -> cardName[0] == 'e') return true;

  printf("\nPlease enter a card type: ");
  scanf(" %20[^\n]", f -> cardType);
  fflush(stdin);
  if(f -> cardType[0] == 'e') return true;

  // only if the card type is "Attack" it can have a damage number != 0
  if(strcmp(f -> cardType, "Attack") == 0) {
    printf("\nPlease enter a damage number: ");
    scanf(" %10[^\n]", f -> damageNumber);
    fflush(stdin);
    if(f -> damageNumber[0] == 'e') return true;
  } else strcpy(f -> damageNumber, "0");


  printf("\nPlease enter eventual effects: ");
  scanf(" %30[^\n]", f -> effectType);
  fflush(stdin);
  if(f -> effectType[0] == 'e') return true;
  return false;
}


// INPUT FROM IMPORT FILE

void importData(t_field *f) {
  FILE *fp;
  char path[80];
  int selection, addedEntries;
  selection = selectImportFile();
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
    if(userQuery()) importData(f);
    else return;
  }
  while(!feof(fp)) {
    char firstChar = fgetc(fp);
    if(firstChar == '*') {
      while(fgetc(fp) != '\n') {
        if(feof(fp)) break;
        fseek(fp, 1, SEEK_CUR);
      }
    }
    else  {
      ungetc(firstChar, fp);
      fscanf(fp, "%[^/]/%[^/]/%[^/]/%[^/]/%[^\n]\n", f -> characterName, f -> cardName, f -> cardType, f -> damageNumber, f -> effectType);
      listAdd(f);   // adds the read entry to the struct
      addData(f);   // writes the entry to data.txt
      addedEntries++;
    }
  }
  fclose(fp);
  printf("\nFile scanning finished. Imported %d entry(s).", addedEntries);
  if(selection == 1) resetImportFile();    // reformats the import.txt
  waitForExit();
}
