#include <stdio.h>
#include <string.h>

int main() {
  int length, len, output, currentNumber, j, sum = 0, proofNumber;
  char input[30+1];
  scanf("%s", input);
  fflush(stdin);
  length = strlen(input);
  len = length;
  printf("Länge: %i\n", length);
  printf("Len: %i\n", len);
  for(j = 2; j <= 7; j++) {
      if(len > 0) {
        printf("%i, ", j);
        currentNumber = (int)input[len];
        printf("(%i) ", currentNumber);
        sum = sum + (currentNumber * j);
        len--;
        if((j==7) && (len > 0))   j=1;
      }
  }
  printf("Prüfziffer vor mod: %i\n", proofNumber);
  printf("Sum mod 11: %i\n", sum%11);
  proofNumber = 11 - (sum % 11);
  if((proofNumber == 10) || (proofNumber == 11))    proofNumber = 0;
  printf("Prüfziffer: %i\n", proofNumber);
  main();
  return 0x4;
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
