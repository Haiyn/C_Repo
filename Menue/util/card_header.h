#ifndef CARD_HEADER_H
#define CARD_HEADER_H

// LIBRARIES
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curses.h>   // Linux equivalent of conio header
#include <time.h>

// TOOLS
#include "functions.c"
#include "ui.c"


// CONSTANT MAX LENGHTS
#define CHARACTER_NAME_LN 20
#define CARD_NAME_LN 30
#define CARD_TYPE_LN 20
#define DAMAGE_NUMBER_LN 10
#define EFFECT_TYPE_LN 30
#define ENTRY_LN 112           // Length of all struct vars + 2 for \n at the end of line

// GLOBAL AVAILABLE PROPERTIES
int entryCount;

// STRUCTS
struct card {
  char characterName[CHARACTER_NAME_LN];
  char cardName[CARD_NAME_LN];
  char cardType[CARD_TYPE_LN];
  char damageNumber[DAMAGE_NUMBER_LN];
  char effectType[EFFECT_TYPE_LN];
} card;

typedef struct m_card {
  char characterName[CHARACTER_NAME_LN];
  char cardName[CARD_NAME_LN];
  char cardType[CARD_TYPE_LN];
  char damageNumber[DAMAGE_NUMBER_LN];
  char effectType[EFFECT_TYPE_LN];

  struct m_card *before;
  struct m_card *after;
} t_card;

typedef struct {
  char characterName[CHARACTER_NAME_LN];
  char cardName[CARD_NAME_LN];
  char cardType[CARD_TYPE_LN];
  char damageNumber[DAMAGE_NUMBER_LN];
  char effectType[EFFECT_TYPE_LN];

  t_card *mom,
         *start,
         *last;
} t_field;



// CARD WRITE PROTOTYPES
bool readData();
void addData();
void ReplaceData();
void writeData();
bool checkInput();
bool retry();

// CARD LOAD PROTOTYPES
void printEntries(t_field *f, int entrySelection, bool firstCall);
bool loadEntries();
void listAdd();
void addEntry();
void selectionMenu();

// CARD HEX PROTOTYPES
void mainHex();

// CARD DELETE PROTOTYPES
void mainDelete(t_field *f);
bool flagEntry();
void deleteFlaggedEntry();

// SORT PROTOTYPES
void mainSort();
void bubblesort();
void checkDirection();
void switchEntries();

// FUNCTIONS PROTOTYPES
bool checkInputSelection();
void waitForExit();

// UI PROTOTYPES
int showMainMenu();
int showEntryAmountMenu();
int showProceedSelectionMenu();
int selectSortColumn();
int selectSortDirection();
int selectSortType();


#endif
