#include <stdio.h>

int main(void)
{
  int sum = 0;
  int br[8];
  printf("Please enter a number: ");
  scanf("%i", br);
  printf("%i", br);

  for(int i; i < 9; i++) {
    if((i != 3) || (i != 7)) {
      if((i % 2) == 0) {
        sum = sum  + (br[i] * 1);
      }
      else {
        sum = sum + (br[i] * 2);
      }
    }
  }
  printf("%i", sum);
  return(0);
}

/*Bsp:
191-056-1


Beispiele:
003-160-9
078-355-5
078-474-4
103-113-7
110-249-0
118-024-9
151-021-3
191-099-1
212-227-3
212-258-8
323-021-6
401-508-7
*/
