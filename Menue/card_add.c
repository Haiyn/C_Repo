#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// list as a new type
typedef struct m_card {         // m_card is a struct so it needs pointers
  char characterName[20+1];
  char cardName[20+1];
  char cardType[10+1];
  int damageNumber;

  struct m_card *before;         // address pointer for previous list entry
  struct m_card *after;          // address pointer for next list entry
} t_card;

// list as a new type without pointer (for reading data)
typedef struct {
  char characterName[20+1];
  char cardName[30+1];
  char cardType[10+1];
  int damageNumber;

  t_card *mom,               // current pointer
         *last,              // last pointer
         *start;             // first pointer
} t_field;

void listRead();
void listAdd();
void addEntry();
void debug();

int main() {

  // read 3 data sets
  listRead();
  //debug();
  return 0;
}

void listRead(void) {                             // reads one list entry of type t_card
  // local pointers
  t_field field;
  t_field *f = &field;                          // points to list
  f -> mom = 0;
  f -> start = 0;
  f -> last = 0;
  for(int i = 0; i < 3; i++) {


    printf("\nPlease enter a character name: ");
    scanf("%s", f -> characterName);
    fflush(stdin);
    listAdd(f, 0);

    printf("\nPlease enter a card name: ");
    scanf("%s", f -> cardName);
    fflush(stdin);
    listAdd(f, 1);

    printf("\nPlease enter the card type: ");
    scanf("%s", f -> cardType);
    fflush(stdin);
    listAdd(f, 2);

    int value;
    printf("\nPlease enter the cards damage number: ");
    scanf("%d", &value);
    fflush(stdin);
    printf("read value: %d\n", value);
    f -> damageNumber = value;
    printf("adding int value...\n");
    listAdd(f, 3);
    printf("int value add successful. Debugging...\n");
    debug(f);
    printf("debugged. Exiting...\n");
  }
}

void listAdd(t_field *f, int param) {
  f -> mom = (t_card*)malloc(sizeof(t_card));               // Reserviert Größe des structs im Hauptspeicher, Typecast nötig, da return value von malloc Void-Zeiger ist
  addEntry(f, param);                                              // Kopiert eingelesenes in die Liste
  f -> mom -> before = f -> last;
  f -> mom -> after = 0;
  if(f -> last == 0)  f -> start = f -> mom;
  else f -> last -> after = f -> mom;

  f -> last = f -> mom;
}

void addEntry(t_field *f, int param) {                          // adds the current entry as a list entry
  switch(param) {
    case 0:
      strcpy(f -> mom -> characterName, f -> characterName);
      break;
    case 1:
      strcpy(f -> mom -> cardName, f -> cardName);
      break;
    case 2:
      strcpy(f -> mom -> cardType, f -> cardType);
      break;
    case 3:
      f -> mom -> damageNumber, f -> damageNumber;
      break;
    default:
      printf("Error while detecting struct entry\n");
      return;
  }
}

void debug(t_field *f) {
  f -> mom = f -> start;
  while (f -> mom) {
    printf("%-20s %s %s %d %X %X %X\n",
                  f -> mom -> characterName,
                  f -> mom -> cardName,
                  f -> mom -> cardType,
                  f -> mom -> damageNumber,
                  f -> mom,
                  f -> mom -> before,
                  f-> mom -> after);
    f -> mom = f -> mom -> after;
  }
  return;
}
