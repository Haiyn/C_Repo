#include <stdio.h>

int main (void) {
  char text [100+1];
  FILE *read;                                            // FILE is own data type
  read = fopen("dummy_data.txt", "r");                    // opens dummy_data.txt in read mode and assigns it to the FILE pointer
  // if the file does not exist, fopen() creates a null pointer
  // null pointer handling
  if(!read)
  {
    printf("Empty file.");
  }
  else {
    fgets(text, 80, read);                              // reads 80 characters from *read
    while(!feof(read)) {                                // as long as the end of file is not reached...
      printf("\n%s", text);                             // ...process the read text
      fgets(text, 80, read);                            // ...and read the rest of the lines in *read
    }
    fclose(read);
  }
  //return 0;
}
