#include "header.h"

// DATA LOADING

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
  printf("#DEBUG Scanning completed. Loaded %d entries.\n", entryCount);
  return true;
}

// reserves memory and adds to the struct
void listAdd(t_field *f) {
  f -> mom = (t_card*)malloc(sizeof(t_card));      // reserves the size of the struct in main memeory, typecast needed because malloc's return value is a void pointer
  addEntry(f);
  f -> mom -> before = f -> last;
  f -> mom -> after = 0;
  if(f -> last == 0)  f -> first = f -> mom;
  else f -> last -> after = f -> mom;
  f -> last = f -> mom;
}

// copies read values to struct
void addEntry(t_field *f) {
  strcpy(f -> mom -> characterName, f -> characterName);
  strcpy(f -> mom -> cardName, f -> cardName);
  strcpy(f -> mom -> cardType, f -> cardType);
  strcpy(f -> mom -> damageNumber, f -> damageNumber);
  strcpy(f -> mom -> effectType, f -> effectType);
}


// DATA WRITING

// Add a new entry at the end of the file
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

// Replace the txt file with the whole struct (after deleting an entry)
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

void copyEntry(t_field *f) {
  int entryIndex;
  entryIndex = selectEntryToCopy();
  f -> mom = f -> start;
  while(i < entryIndex - 1) {
    f -> mom = f -> mom -> after;
  }
  // TODO
}

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