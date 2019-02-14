#include "../util/header.h"

// lets the user select the file to import
void importEntries(t_field *f) {
  system("clear");
  FILE *fp;
  char path[80];
  int selection, addedEntries;
  
  selection = selectImportFile();
  switch(selection) {
    case 1:
      fp = fopen("./data/import.txt", "r");
      break;
    case 2:
      printf("\nPlease enter the file path (relative to import.c): ");
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

  addedEntries = scanImportFile(fp, f);
  fclose(fp);
  printf("\nFile scanning finished. Imported %d entry(s).", addedEntries);

  if(selection == 1) resetImportFile();    // reformats the import.txt
  printf("\nWould you like to import another file? [y/n] ");
  if(userQuery()) importEntries(f);
}

// scans the selected file for any entrys and ignores comment lines
int scanImportFile(FILE *fp, t_field *f) {
  int addedEntries = 0;
  while(!feof(fp)) {
    char line[400];
    fscanf(fp, "%[^\n]\n", line);
    // if line does not start with "###", split the char array into tokens
    if(!(line[0] == '#' && line[1] == '#' && line[2] == '#')) {
      strcpy(f -> characterName, strtok(line, "/"));
      strcpy(f -> cardName, strtok(NULL, "/"));
      strcpy(f -> cardType, strtok(NULL, "/"));
      strcpy(f -> damageNumber, strtok(NULL, "/"));
      strcpy(f -> effectType, strtok(NULL, "\n"));
      listAdd(f); // add the saved tokens to the struct
      addData(f); // write the new struct entry to data.txt
      addedEntries++;
    }
  }
  return addedEntries;
}
