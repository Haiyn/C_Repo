// DELETING DATA IN CHAINED LISTS

// needs basic struct (found in chained_lists.c)

deleteData(t_field *f) {
  int deleteFlag, i = 0;
  showData(f);                                      // show all existing data entries
  printf("\nEnter the entry number you want to delete: ");
  scanf("%d", deleteFlag);
  fflush(stdin);

  // incement the current pointer to to the entry number that was given by user in deleteFlag:
  f -> mom = f - start;                             // initiliases the current pointer as the starting pointer (first entry)
  while(f -> mom && i++ < deleteFlag) {             // is there a current pointer thats deletable?
    f -> mom = f -> mom -> after;                   // increments the current pointer as the following pointer (next entry)
  }

  // Check which entry was selected (cannot use switch case because theres no numbers)
  if(f -> mom == 0) {                                         // entry does not exist
    printf("\nEntry does not exist.\n", );
  } else if(f -> mom -> after && f -> mom -> previous) {      // entry has previous and following entry
    // delete the entry from the chained list
    f -> mom -> before -> after = f -> mom -> after;
    f -> mom -> after -> before = f -> mom -> before;
    // free the allocated space for the current pointer
    free(f -> mom);
    // set current pointer to start to avoid a NullPointerException
    f -> mom = f -> start;
  } else if(f -> mom -> previous) {                           // entry only has a previous entry (last entry)
    
  } else if(f -> mom -> after) {                              // entry only has a following entry (first entry)

  } else {                                                    // last possible entry (only entry)

  }

}
