#include <stdio.h>
#include <curses.h>

#define CHARACTER_NAME_LN 20
#define CARD_NAME_LN 20
#define CARD_TYPE_LN 10
#define DAMAGE_NUMBER_LN 2
#define AFFLICTION_TYPE_LN 20

struct card {
  char characterName[CHARACTER_NAME_LN];
  char cardName[CARD_NAME_LN];
  char cardType[CARD_TYPE_LN];
  char damageNumber[DAMAGE_NUMBER_LN];
  char afflictionType[AFFLICTION_TYPE_LN];
} card;

bool readData();
void writeData();
bool checkInput();
void sleep();

void mainWrite() {
  system("clear");
  printf("#DEBUG Starting read process...\n");

  bool aborted = readData();
  if(aborted) return;         // if the action was aborted, return to the main menu
  printf("\n#DEBUG Read process finished. Starting write process...\n");
  writeData();
  printf("#DEBUG Data writing finished.\n");

  // Let the user decide if he wants to add another entry, otherwise return to the main menu
  printf("Would you like to add another entry? [y/n] ");
  char retrySelection[2];
  scanf("%s", retrySelection);
  fflush(stdin);
  if(retrySelection[0] == 'y') mainWrite();
  return;
}

bool readData() {
  fflush(stdin);
  printf("\nPlease enter a character name: ");
  scanf("%s", card.characterName);
  fflush(stdin);
  if(card.characterName[0] == 'e') return true;       // if character 'e' was entered, abort the process and return to the main menu

  printf("\nPlease enter a card name: ");
  scanf("%s", card.cardName);
  fflush(stdin);
  if(card.cardName[0] == 'e') return true;

  printf("\nPlease enter a card type: ");
  scanf("%s", card.cardType);
  fflush(stdin);
  if(card.cardType[0] == 'e') return true;

  printf("\nPlease enter a damage number: ");
  scanf("%s", card.damageNumber);
  fflush(stdin);
  if(card.damageNumber[0] == 'e') return true;

  printf("\nPlease enter eventual afflictions: ");
  scanf("%s", card.afflictionType);
  fflush(stdin);
  if(card.afflictionType[0] == 'e') return true;
  return false;
}

void writeData() {      //TODO Fix: fwrite writes unreadable characters if char arrays aren't filled completely
  FILE *fp;
  if(!fp) {
    printf("###ERR Could not find file.");
    return;
  }
    // open and close the file with every write process so the previous entries arent overwritten
    fp = fopen("card_data.txt", "a+");      // a+ opens the file appended (pointer moves to eof)
    fwrite(card.characterName, CHARACTER_NAME_LN, 1, fp);
    fwrite(card.cardName, CARD_NAME_LN, 1, fp);
    fwrite(card.cardType, CARD_TYPE_LN, 1, fp);
    fwrite(card.damageNumber, DAMAGE_NUMBER_LN, 1, fp);
    fwrite(card.afflictionType, AFFLICTION_TYPE_LN, 1, fp);
    fwrite("\n", 1, 1, fp);

    // Possible fix: Don't use fixed entry lengths but the lengths of the values entered, then seperate with /
    /*fwrite(card.characterName, strlen(card.characterName), 1, fp);
    fwrite("/", 1, 1, fp);
    fwrite(card.cardName, strlen(card.cardName), 1, fp);
    fwrite("/", 1, 1, fp);
    fwrite(card.cardType, strlen(card.cardType), 1, fp);
    fwrite("/", 1, 1, fp);
    fwrite(card.damageNumber, strlen(card.damageNumber), 1, fp);
    fwrite("/", 1, 1, fp);
    fwrite(card.afflictionType, strlen(card.afflictionType), 1, fp);
    fwrite("/", 1, 1, fp);*/
    fclose(fp);

}
