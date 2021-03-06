#include "../util/header.h"

// calls all methods needed for deleting
void deleteEntries(t_field *f) {
    bool success = false;
    // load data from txt and print all existing entries
    int entryCount = loadEntries(f, 4);
    InitPrintEntries(f, 4);

    // Flag and delete entered entry range
    success = flagEntry(f);
    if(!success) printf("\n\n###ERR Error deleting entry.");
    else printf("\n\nDeleted successfully.");
    waitForExit();
    return;
}

// let the user decide which entry(s) to delete
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
  f -> mom = f -> first;
  while(f -> mom && ++i < deleteFlagTo) {
    f -> mom = f -> mom -> after;
    if(f -> mom == 0) {
      printf("\n##WARN Entry does not exist.");
      return false;
    }
  }
  deleteFlaggedEntry(f, deleteFlagTo, deleteFlagFrom);
  return true;
}

// deletes the entry(s) the user chose
void deleteFlaggedEntry(t_field *f, int deleteFlagTo, int deleteFlagFrom) {
  for(int i = 0; i <= deleteFlagTo - deleteFlagFrom; i++) {
    if(f -> mom -> after && f -> mom -> before) {      // Middle entry
      f -> mom -> before -> after = f -> mom -> after;
      f -> mom -> after -> before = f -> mom -> before;
      free(f -> mom);
    } else if(f -> mom -> before) {      // last entry
      f -> mom -> before -> after = 0;
      f -> last = f -> mom -> before;
      free(f -> mom);
    } else if(f -> mom -> after) {      // first entry
      f -> mom -> after -> before = 0;
      f -> first = f -> mom -> after;
      free(f -> mom);
    } else {                            // only entry
      free(f -> mom);
    }
    f -> mom = f -> mom -> before;
  }
  f -> mom = f -> first;
  ReplaceData(f);
}
