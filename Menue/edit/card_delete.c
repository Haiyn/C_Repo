#include "../util/card_header.h"

void mainDelete(t_field *f) {
    bool success = false;
    // load data from txt and print all existing entries
    loadEntries(f, 4);
    printEntries(f, 4, true);

    // Flag and delete entered entry range
    success = flagEntry(f);
    if(!success) printf("\n\n###ERR Error deleting entry.");
    else printf("\n\nDeleted successfully.");
    waitForExit();
    return;
}

bool flagEntry(t_field *f) {
  int deleteFlagFrom, deleteFlagTo, i = 0;
  bool exists;

  // read the user input
  printf("\nEnter the entry area you want to delete.\nFrom entry: ");
  scanf("%d", &deleteFlagFrom);
  fflush(stdin);
  printf("\nTo entry: ");
  scanf("%d", &deleteFlagTo);
  fflush(stdin);


  // increment the current pointer to to the entry number that was given by user in deleteFlag:
  f -> mom = f -> start;
  while(f -> mom && ++i < deleteFlagTo) {
    f -> mom = f -> mom -> after;
    if(f -> mom == 0) {
      printf("\n##WARN Entry does not exist.");
      return false;
    }
  }
  exists = true;
  deleteFlaggedEntry(f, deleteFlagTo, deleteFlagFrom);
  return true;
}


void deleteFlaggedEntry(t_field *f, int deleteFlagTo, int deleteFlagFrom) {
  //f -> mom = f -> start;
  for(int i = 0; i <= deleteFlagTo - deleteFlagFrom; i++) {
    if(f -> mom -> after && f -> mom -> before) {      // Middle entry
      f -> mom -> before -> after = f -> mom -> after;
      f -> mom -> after -> before = f -> mom -> before;
      free(f -> mom);
      // set current pointer to start to avoid a NullPointerException
      //f -> mom = f -> start;
    } else if(f -> mom -> before) {      // last entry
      f -> mom -> before -> after = 0;
      f -> last = f -> mom -> before;
      free(f -> mom);
      //f -> mom = f -> start;
    } else if(f -> mom -> after) {      // first entry
      f -> mom -> after -> before = 0;
      f -> start = f -> mom -> after;
      free(f -> mom);
      //f -> mom = f -> start;
    } else {                            // only entry
      free(f -> mom);
    }
    f -> mom = f -> mom -> before;
  }
  f -> mom = f -> start;
  entryCount - (deleteFlagTo-deleteFlagFrom);
  ReplaceData(f);
}
