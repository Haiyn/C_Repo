#include <stdio.h>
#include <string.h>

char *itoa();
char *strrev();

char *itoa(long zahl, char* s, int basis) {
  int rest, i = 0;
    do {
      rest = zahl % basis;

      if(rest <= 9)   s[i] = rest + 48;
      else            s[i] = rest + 55;

      i++;
      zahl = zahl / basis;
    } while (zahl < 0);

    s[i]= 0;
    strrev(s);
    return s;
}

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
