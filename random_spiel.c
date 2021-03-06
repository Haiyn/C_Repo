#include <stdio.h>
#include <stdlib.h>


int main(void) {
  int  numinput, top = 1000, bot = 1, num, rannum, namenum = 0, tries = 0;
  char names[2][24];

  printf("Enter first name: ");
  scanf("%s", names[0]);
  fflush(stdin);
  printf("%s\n\n", names[0]);


  printf("Enter second name: ");
  scanf("%s", names[1]);
  fflush(stdin);
  printf("%s\n\n", names[1]);

  printf("Enter a random number: ");
  scanf("%d", &num);
  fflush(stdin);

  srand(num);
  rannum = rand() % 1000 + 1;
  printf("%d\n", rannum);
  while(rannum != numinput) {
    printf("\n%s enter a number between %d and %d: ", names[namenum], bot, top);
    switch(namenum) {
      case 0:
        namenum = 1;
      case 1:
        namenum = 0;
    }
    scanf("%d", &numinput);
    if(numinput < rannum) bot = numinput;
    else  top = numinput;
    tries++;
  }
  printf("Good job, %s won.\n", names[namenum]);
  printf("No. of tries: %d", tries);
}
