#include <stdio.h>
#include <string.h>

int main()
{
  int sum = 0;
  char rawnum[10], br[10], *token;
  printf("\nPlease enter a number: ");
  scanf("%s", br);
  fflush(stdin);
  printf("%s\n", br);

  token = strstr(br, "-");
  strncpy(rawnum, br, (int)token);
  //strncat(rawnum, br+4, 7);
  //strncat(rawnum, br+);
  printf("%s\n", rawnum);

  /*for(int i; i < 9; i++) {
    if((i != 3) || (i != 7)) {
      if((i % 2) == 0) {
        sum = sum  + (br[i] * 1);
      }
      else {
        sum = sum + (br[i] * 2);
      }
    }
  }*/
  printf("%i", sum);
  main();
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
