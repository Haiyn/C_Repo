//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curses.h>   // Linux equivalent of conio header

#include "card_read.c"
#include "card_write.c"



int main() {
  system("clear");
  int selection;
  printf("-----------------------------------------------------------------\n");    //64 horizontal
  printf("|\t\t\t\t\t\t\t\t|\n");                                 // 2 | chars + 5 horizontal tabs (5*8 whitespaces)
  printf("|\tWhat would you like to do?\t\t\t\t|\n");
  printf("|\t\t\t\t\t\t\t\t|\n");
  printf("|   [1] Read saved entries\t\t\t\t\t|\n");
  printf("|         Show saved entries and sort them.\t\t\t|\n");
  printf("|\t\t\t\t\t\t\t\t|\n");
  printf("|   [2] Add new entries\t\t\t\t\t\t|\n");
  printf("|         Open the prompt that lets you add new entries.\t|\n");
  printf("|\t\t\t\t\t\t\t\t|\n");
  printf("|   [3] Delte existing entries\t\t\t\t\t|\n");
  printf("|         Choose an entry to delete it.\t\t\t\t|\n");
  printf("|\t\t\t\t\t\t\t\t|\n");
  printf("-----------------------------------------------------------------\n");
  printf("Please enter a number: ");
  scanf("%d", &selection
);
  fflush(stdin);

  switch(selection) {
    case 1:
      system("clear");
      mainRead();
      break;
    case 2:
      system("clear");
      mainWrite();
      break;
    case 3:
      system("clear");
      printf("Not yet implemented.");
      break;
    default:
      printf("\nERROR: SELECTION OUT OF BOUNDS\n");
      break;
  }
  main();
  return 0;
}
