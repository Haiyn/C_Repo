#include <stdio.h>

main() {
  int l;
  char t1[80+1], t2[80+1];
  strcopy(t1, "Hannes");
  l = stringCopy(t2, t1);
}

int stringCopy(char *t2, char *t1) {
  int length, i;
  length = stringLength(t1);
  for(i = 0; i < length, i++) {
    t2[i] = t1[i];
  }
  t2[i] = 0;    // = '\0'
  return length;
}

int stringLength(char *t) {
  int length = 0;
  while(t[length++] != 0);
  return length;
}

void stringCopyShort(char *t2, char *t1) {
  while(*t2++ = *t1++);
}
