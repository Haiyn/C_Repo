#include "../util/header.h"

void importEntries(t_field *f) {
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
    if(userQuery()) importEntries(f);
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
