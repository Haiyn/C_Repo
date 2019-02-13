#include "header.h"

// USER INPUT CHECKS
// Checks whether the input number is greater or smaller than the possible selections in a selection menu
bool checkInputSelection(int lowerBoundary, int upperBoundary, int input) {
  if(input < lowerBoundary || input > upperBoundary) {
    printf("\nSorry, that input isn't valid!\n");
    return false;
  }
  else return true;
}

// Makes the sub-routine wait until user inputs a '1'
void waitForExit() {
  char num[1];
  printf("\n\nTo exit the sub-routine, enter '1': ");
  do
    scanf(" %[^ \n]", num);
  while(num[0] != '1');
  return;
}

// Asks the user if he wants to run the sub-routine again. Return
bool userQuery() {
  char retrySelection[1];
  scanf(" %[^\n]", retrySelection);
  if(retrySelection[0] == 'y')  return true;
  else {
    return false;
  }
}


// UI FUNCTIONS
// Prints a given amount of a specifc character (with or without a | border), acting as a seperator
void printSeparator(char separator, int amount, bool border) {
  if(border) printf("|");
  for(int i = 0; i < amount; i++) {
    printf("%c", separator);
  }
  if (border) printf("|\n");
  else printf("\n");
}


// FILE VALIDATION
bool validateFile(FILE *fp, char functionName[30]) {
  if(!fp) {
    printf("\n###ERR at %s: Could not find file.", functionName);
    return false;
  }
  return true;
}
