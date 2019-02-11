#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHARACTER_NAME_LN 20
#define CARD_NAME_LN 20
#define CARD_TYPE_LN 10
#define DAMAGE_NUMBER_LN 2
#define AFFLICTION_TYPE_LN 20

typedef struct m_card {
  char characterName[CHARACTER_NAME_LN];
  char cardName[CARD_NAME_LN];
  char cardType[CARD_TYPE_LN];
  char damageNumber[DAMAGE_NUMBER_LN];
  char afflictionType[AFFLICTION_TYPE_LN];

  struct m_card *before;
  struct m_card *after;
} t_card;

typedef struct {
  char characterName[CHARACTER_NAME_LN];
  char cardName[CARD_NAME_LN];
  char cardType[CARD_TYPE_LN];
  char damageNumber[DAMAGE_NUMBER_LN];
  char afflictionType[AFFLICTION_TYPE_LN];

  t_card *mom,
         *start,
         *last;
} t_field;

void InitPrintEntries();
bool readEntries();
void listAdd();
void addEntry();
void selectionMenu();

void mainRead() {
  int entryAmount;
  //LIST POINTERS
  t_field field;
  t_field *f = &field;
  f -> mom = 0;
  f -> start = 0;
  f -> last = 0;

  printf("\nHow many entries would you like to show?\n");
  printf("\n\t[1] 10");
  printf("\n\t[2] 20");
  printf("\n\t[3] 30");
  printf("\n\t[4] Return to the main menu");
  printf("\nPlease enter a number: ");
  scanf("%d", &entryAmount);
  fflush(stdin);
  if(entryAmount == 4) return;
  bool readSuccess = readEntries(f, entryAmount);
  if(!readSuccess) {
    printf("\n###ERR Reading process failed at card_read.c \nWould you like to retry? Enter 0 for no, 1 for yess: ");
    int retrySelection;

    if(scanf("%d", &retrySelection) == 1)  mainRead();
    else return;
  }
  else printf("\nEntries read. Printing %d entries...\n\n\n", entryAmount*10);    //TODO time measurement
  InitPrintEntries(f, entryAmount);
  selectionMenu();
  return;
}

bool readEntries(t_field *f, int entryAmount) {
  FILE *fp;
  fp = fopen("card_data.txt", "a+");
  if(!fp) {
    printf("###ERR File not found.");
    return false;
  }

  int entryCount = 1;
  char entry[72];
  fgets(entry, 72, fp);
  printf("\n%s", entry);
  while(!feof(fp)) {
    entryCount++;
    strncpy(f -> characterName, entry, CHARACTER_NAME_LN);
    strncpy(f -> cardName, entry + CHARACTER_NAME_LN, CARD_NAME_LN);
    strncpy(f -> cardType, entry + CARD_NAME_LN, CARD_TYPE_LN);
    strncpy(f -> damageNumber, entry + CARD_TYPE_LN, DAMAGE_NUMBER_LN);
    strncpy(f -> afflictionType, entry + DAMAGE_NUMBER_LN, AFFLICTION_TYPE_LN);
    listAdd(f);
    printf("\n%s", entry);
    fgets(entry, 72*entryCount, fp);
  }
  fclose(fp);
  printf("Reading completed. Found %d entries.\n", entryAmount*10);
  return true;
}



void listAdd(t_field *f) {
  f -> mom = (t_card*)malloc(sizeof(t_card));      // reserves the size of the struct in main memeory, typecast needed because malloc's return value is a void pointer
  addEntry(f);
  f -> mom -> before = f -> last;
  f -> mom -> after = 0;
  if(f -> last == 0)  f -> start = f -> mom;
  else f -> last -> after = f -> mom;
  f -> last = f -> mom;
}

void addEntry(t_field *f) {
  strcpy(f -> mom -> characterName, f -> characterName);
  strcpy(f -> mom -> cardName, f -> cardName);
  strcpy(f -> mom -> cardType, f -> cardType);
  strcpy(f -> mom -> damageNumber, f -> damageNumber);
  strcpy(f -> mom -> afflictionType, f -> afflictionType);
}

void InitPrintEntries(t_field *f, int entryAmount) {
  f -> mom = f -> start;
  for(int i = 0; i <= entryAmount; i++) {
    if(f -> mom == 0) break;
    printf("Printing...\n");
    printf("%-10s %s %s %s %s\n",
      f -> mom -> characterName,
      f -> mom -> cardName,
      f -> mom -> cardType,
      f -> mom -> damageNumber,
      f -> mom -> afflictionType);
    //printf("mom, after: %X, %X", f -> mom, f -> mom -> after);
    f -> mom = f -> mom -> after;
  }
}

void selectionMenu() {
  int selection;
  printf("\n\n");
  printf("What would you like to do?");
  printf("\n  [1] Sort shown entries");
  printf("\n  [2] Delete an entry");
  printf("\n  [3] Return to the main menu");
  printf("\n\nPlease enter a number: ");

  scanf("%d", &selection);
  fflush(stdin);

  switch(selection) {     //TODO implement
    case 1:
      system("clear");

      break;
    case 2:
      system("clear");

      break;
    case 3:
      system("clear");

      break;
    case 4:
      return;
    default:
      printf("\nERROR: SELECTION OUT OF BOUNDS\n");
      break;
  }
}
