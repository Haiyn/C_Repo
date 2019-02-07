#ifndef HEADER_H
#define HEADER_H

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
#define NAME_LN 30
#define TYPE_LN 20
#define DAMAGE_NUMBER_LN 10
#define EFFECT_TYPE_LN 30
#define ENTRY_LN 112           // Length of all struct vars + 2 for \n at the end of line

// GLOBAL AVAILABLE PROPERTIES
int entryCount;

// STRUCTS
struct card {
  char characterName[CHARACTER_NAME_LN];
  char cardName[NAME_LN];
  char cardType[TYPE_LN];
  char damageNumber[DAMAGE_NUMBER_LN];
  char effectType[EFFECT_TYPE_LN];
} card;


typedef struct m_card {
  char characterName[CHARACTER_NAME_LN];
  char cardName[NAME_LN];
  char cardType[TYPE_LN];
  char damageNumber[DAMAGE_NUMBER_LN];
  char effectType[EFFECT_TYPE_LN];

  struct m_card *before;
  struct m_card *after;
} t_card;

typedef struct {
  char characterName[CHARACTER_NAME_LN];
  char cardName[NAME_LN];
  char cardType[TYPE_LN];
  char damageNumber[DAMAGE_NUMBER_LN];
  char effectType[EFFECT_TYPE_LN];

  t_card *mom,
         *first,
         *last;
} t_field;



// CARD WRITE PROTOTYPES
bool readData();
void addData();
void ReplaceData();
void writeData();
bool checkInput();
bool retry();
void resetImportFile();

// CARD LOAD PROTOTYPES
void readImportFile();
char readFilePath();
void printEntries(t_field *f, int entrySelection, bool firstCall);
bool loadEntries();
void listAdd();
void addEntry();
void selectionMenu();

// CARD HEX PROTOTYPES
void mainHex();

// CARD SEARCH PROTOTYPES
void mainSearch();
void printHeader();
void printFooter();

// CARD DELETE PROTOTYPES
void mainDelete(t_field *f);
bool flagEntry();
void deleteFlaggedEntry();

// SORT PROTOTYPES
void bubblesort();
void checkDirection();
void switchEntries();

// FUNCTIONS PROTOTYPES
bool checkInputSelection();
void waitForExit();

// UI PROTOTYPES
int selectMainMenuAction();
int selectEntryAmount();
int selectProceedAction();
int selectSortColumn();
int selectSortDirection();
int selectSortType();
int selectImportFile();


#endif
