#include "../util/header.h"

// DATA READING (USER INPUT)

void inputEntries(t_field *f) {
  system("clear");
  bool aborted = readInputData(f);
  if(aborted) return;                   // if the action was aborted, return to the main menu
  addData(f);

  printf("\nWould you like to add another entry? [y/n] ");
  if(userQuery())  inputEntries(f);
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
