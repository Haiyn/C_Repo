#include <stdio.h>
#include <string.h>

int main() {
  int length, output, currentNumber, j, sum = 0, proofNumber;
  char input[31+1];

  scanf("%s", input);
  fflush(stdin);
  length = strlen(input);

  for(length, j = 2; j <= 7, length >= 1; length--, j++) {
        currentNumber = (int)input[length-1] - '0';
        sum = sum + (currentNumber * j);
        if(j == 7)   j=1;
  }
  proofNumber = 11 - (sum % 11);
  if((proofNumber >= 10))    proofNumber = 0;
  printf("\nPrüfziffer: %i\n", proofNumber);
  return 1;
}

/*
Beispiele:
1234567
3344556
7531642
>>>
>>>
>>>
Prüfziffer 4
Prüfziffer 3
Prüfziffer 9
>>>
>>>
>>>
12345674
33445563
75316429
*/
