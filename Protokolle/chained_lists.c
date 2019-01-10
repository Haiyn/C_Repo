#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// list as a new type for list entries
typedef struct m_card {
  char characterName[20+1];
  char cardName[20+1];
  int damageNumber;

  struct m_card *before;         // address pointer for previous entry
  struct m_card *after;          // address pointer for following enry
} t_card;

// list as a new type without entry pointers (for reading data)
typedef struct {
  char characterName[20+1];
  char cardName[30+1];
  char cardType[10+1];
  int damageNumber;

  t_card *mom,
         *start,
         *last;
} t_field;

void list_add();
void add_entry();
void debug();

int main() {

  t_field field;                    // local pointers
  t_field *f = &field;
  f -> mom = 0;
  f -> start = 0;
  f -> last = 0;
  // read 3 data sets
  int i;
  for(i = 0; i < 3; i++) {
    char input[3+1];
    printf("\nPlease enter a Character name: ");
    scanf("%s", f -> characterName);
    fflush(stdin);

    list_add(f);
  }
  debug(f);
  return 0;
}

void list_add(t_field *f) {
  f -> mom = (t_card*)malloc(sizeof(t_card));      // reserves the size of the strucht in main memeory, typecast needed because malloc's return value is a void pointer
  add_entry(f);                                    // copies read element to the list
  f -> mom -> before = f -> last;
  f -> mom -> after = 0;
  if(f -> last == 0)  f -> start = f -> mom;
  else f -> last -> after = f -> mom;

  f -> last = f -> mom;
}

void add_entry(t_field *f) {
  strcpy(f -> mom -> characterName, f -> characterName);
}

void debug(t_field *f) {
  f -> mom = f -> start;
  while (f -> mom) {
    printf("\n %-10s %X %X %X",
                  f -> mom -> characterName,
                  f -> mom,
                  f -> mom -> before,
                  f-> mom -> after);

    f -> mom = f -> mom -> after;
  }
}
