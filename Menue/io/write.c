#include "../util/header.h"

// DATA READING (USER INPUT)

void mainWrite(t_field *f) {
  system("clear");

  printf("#DEBUG Starting read process...\n");

  bool aborted = readData(f);
  if(aborted) return;         // if the action was aborted, return to the main menu
  printf("\n#DEBUG Read process finished. Starting write process...\n");
  addData(f);
  printf("#DEBUG Data writing finished.\n");

  printf("Would you like to add another entry? [y/n] ");
  if(retry())  {
    memset(&card, 0, sizeof(card));     // reset the memory of the struct to avoid false data from previous input
    mainWrite(f);
  }
}

// Read data from user input
bool readData(t_field *f) {
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

// Add the input data to the txt file (opens appended)
void addData(t_field *f) {
  FILE *fp;
  fp = fopen("./data/data.txt", "a+");      // a+ opens the file appended (pointer moves to eof)
  if(!validateFile(fp, "addData")) {
    waitForExit();
    return;
  }
  // open and close the file with every write process so the previous entries arent overwritten
  fprintf(fp, "%s/%s/%s/%s/%s\n", f -> characterName, f -> cardName, f -> cardType, f -> damageNumber, f -> effectType);
  fclose(fp);
}



// DATA DELETION

// Replace the txt file with the whole struct (opens the file once with pointer the first)
void ReplaceData(t_field *f) {
  FILE *fp;
  fp = fopen("./data/data.txt", "w");
  if(!validateFile(fp, "ReplaceData")) {
    waitForExit();
    return;
  }

  f -> mom  = f -> first;
  while(f -> mom) {
    fprintf(fp, "%s/%s/%s/%s/%s\n", f -> mom -> characterName, f -> mom -> cardName, f -> mom -> cardType, f -> mom -> damageNumber, f -> mom -> effectType);
    f -> mom = f -> mom -> after;
  }
  fclose(fp);
}




// DATA IMPORT

// Reformats import.txt with the standard header (instructions about usage)
void resetImportFile() {
  FILE *fp;
  fp = fopen("./data/import.txt", "w");
  if(!validateFile(fp, "resetImportFile")) {
    waitForExit();
    return;
  }
  fprintf(fp, "*** IMPORT FILE\n***\n*** This is the import file. Enter sets of data in the following format to import them:\n");
  fprintf(fp, "*** [Character Name]/[Card Name]/[Card Type]/[Damage Number]/[Effects]\n*** Replace [...] with the corresponding value.\n***\n");
  fprintf(fp, "*** This is a comment line, it will be ignored during the import process.\n***\n***\n***----------------------------------------------\n");
  fclose(fp);
}
