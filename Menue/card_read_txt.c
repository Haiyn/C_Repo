#include <stdio.h>

int main() {
  int entryAmount, i = 0, start = 0;
  FILE *fp;
  fp = fopen("card_data.txt", "r");
  if(!fp) {
    printf("File not found.");
    return 404;
  }
  printf("\nHow many entries would you like to show? Please enter a number: ");
  scanf("%d", &entryAmount);
  fflush(stdin);


  for(int i; i < entryAmount; i++) {
    if(feof(fp)) {
      return 0;
    }
    char all[61];
    char characterName[10];
    char cardName[20];
    char cardType[10];
    char damageNumber[1];
    char afflictionType[10];
    fgets(all, 61, fp);
    printf("%-10s\n", all);

    start += 61;
  return 0;
  }
}
