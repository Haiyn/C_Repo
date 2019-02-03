#include "../util/card_header.h"

void mainWrite(t_field *f) {
  system("clear");

  printf("#DEBUG Starting read process...\n");

  bool aborted = readData(f);
  if(aborted) return;         // if the action was aborted, return to the main menu
  printf("\n#DEBUG Read process finished. Starting write process...\n");
  addData(f);
  printf("#DEBUG Data writing finished.\n");

  if(!retry(f))  return;
}

// Read data from user input
bool readData(t_field *f) {
  fflush(stdin);
  printf("\nEnter 'e' to abort and exit the sub-routine.\n");
  printf("\nPlease enter a character name: ");
  scanf("%s", f -> characterName);
  fflush(stdin);
  if(f -> characterName[0] == 'e') return true;       // if character 'e' was entered, abort the process and return to the main menu

  printf("\nPlease enter a card name: ");
  scanf("%s", f -> cardName);
  fflush(stdin);
  if(f -> cardName[0] == 'e') return true;

  printf("\nPlease enter a card type: ");
  scanf("%s", f -> cardType);
  fflush(stdin);
  if(f -> cardType[0] == 'e') return true;

  // only if the card type is "Attack" it can have a damage number != 0
  if(strcmp(f -> cardType, "Attack") == 0) {
    printf("\nPlease enter a damage number: ");
    scanf("%s", f -> damageNumber);
    fflush(stdin);
    if(f -> damageNumber[0] == 'e') return true;
  } else f -> damageNumber[0] = 0;


  printf("\nPlease enter eventual effects: ");
  scanf("%s", f -> effectType);
  fflush(stdin);
  if(f -> effectType[0] == 'e') return true;
  return false;
}

// Add the input data to the txt file (opens appended)
void addData(t_field *f) {
  FILE *fp;
  fp = fopen("./data/card_data.txt", "a+");      // a+ opens the file appended (pointer moves to eof)
  if(!fp) {
    printf("\n###ERR at addData: Could not find file.");
    return;
  }
  // open and close the file with every write process so the previous entries arent overwritten
  writeData(f, fp);
  fclose(fp);
}

// Replace the txt file with the whole struct (opens the file once with pointer the start)
void ReplaceData(t_field *f) {
  FILE *fp;
  fp = fopen("./data/card_data.txt", "w+");
  if(!fp) {
    printf("\n###ERR at overwriteData: Could not find file.");
    return;
  }

  f -> mom  = f -> start;
  while(f -> mom) {
    writeData(f, fp);
    f -> mom = f -> mom -> after;
  }
  fclose(fp);
}

// writes the struct to the file
void writeData(t_field *f, FILE *fp) {
  fprintf(fp, "%s/%s/%s/%s/%s\n", f -> characterName, f -> cardName, f -> cardType, f -> damageNumber, f -> effectType);
  /*fwrite(f -> characterName, CHARACTER_NAME_LN, 1, fp);
  fwrite(f -> cardName, CARD_NAME_LN, 1, fp);
  fwrite(f -> cardType, CARD_TYPE_LN, 1, fp);
  fwrite(f -> damageNumber, DAMAGE_NUMBER_LN, 1, fp);
  fwrite(f -> effectType, EFFECT_TYPE_LN, 1, fp);
  fwrite("\n", 1, 1, fp);*/

}

// Let the user decide if he wants to add another entry, otherwise return to the main menu
bool retry(t_field *f) {
  printf("Would you like to add another entry? [y/n] ");
  char retrySelection[2];
  scanf("%s", retrySelection);
  fflush(stdin);
  if(retrySelection[0] == 'y') {
    memset(&card, 0, sizeof(card));     // reset the memory of the struct to avoid false data from previous input
    mainWrite(f);
  }
  else return false;
}
