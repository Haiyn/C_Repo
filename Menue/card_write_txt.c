#include <stdio.h>

struct {
  char characterName[10];
  char cardName[20];
  char cardType[10];
  int damageNumber[1];
  char afflictionType[20]
} card;

char readData();
void writeData();

int main() {
  printf("Starting read process...\n");
  char input = readData();
  printf("Read process finished. Starting write process...\n");
  writeData(input);
  printf("Data writing finished. Exiting...\n");
  return 0;
}

char readData() {
  printf("\nPlease enter a character name: ");
  scanf("%s", card.characterName);
  fflush(stdin);

  printf("\nPlease enter a card name: ");
  scanf("%s", card.cardName);
  fflush(stdin);

  printf("\nPlease enter a card type: ");
  scanf("%s", card.cardType);
  fflush(stdin);

  printf("\nPlease enter a damage type: ");
  scanf("%s", card.damageNumber);
  fflush(stdin);

  printf("\nPlease enter eventual afflictions: ");
  scanf("%s", card.afflictionType);
  fflush(stdin);
}

void writeData() {
  FILE *fp;
  if(!fp) {
    printf("Could not find file.");
  }
  else {
    // open and close the file with every write process so the previous entries arent overwritten
    fp = fopen("card_data.txt", "a+");      // a+ opens the file appended (pointer moves to eof)
    fwrite(card.characterName, 10, 1, fp);
    fwrite(card.cardName, 20, 1, fp);
    fwrite(card.cardType, 10, 1, fp);
    fwrite(card.damageNumber, 2, 1, fp);
    fwrite(card.afflictionType, 20, 1, fp);
    fclose(fp);
    }

}
