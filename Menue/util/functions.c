#include "card_header.h"
#include <time.h>

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
  int num;
  printf("\n\nTo exit the sub-routine, enter '1': ");
  do
    scanf("%d\n", &num);
  while(num != 1);
}

// TIME MEASURING
// Measures passed time


// STRING MANIPULATION
// Prases a string input that's seperated by commas into an int array (returned as a pointer)
int* parseSeperatedInput(char str[]) {
  static int array[5];
  int i = 0;
  char *pt;


  pt = strtok (str, ",");
  while (pt != NULL) {
      array[i] = atoi(pt);
      pt = strtok (NULL, ",");
      i++;
  }
  return array;
}
