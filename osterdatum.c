/*  Dividiert man die Jahreszahl durch 19 erhält man den Rest A,
    dividiert man die Jahreszahl durch 4 erhält man den Rest B,
    dividiert man die Jahreszahl durch 7 erhält man den Rest C.
    Die Division (19*A + 24) durch 30 ergebe den Rest D,
    die Division (2*B + 4*C + 6*D + 5) durch 7 den Rest E.
    Der Ostersonntag fällt dann auf (D + E) Tage nach dem 22.   */

#include <stdio.h>

int main() {
  int a, b, c, d, e, tag;
  int jahr = 1900;
  int flag = 0;             //registers output to print "..." to save lines
  while(jahr <= 2100) {
    if((jahr == 1954) || (jahr == 1981)) {
      printf("%i ist Ostern nicht errechenbar!\n", jahr);
      flag = 0;
    }
    if(jahr >= 2094) {      //output the last 5 lines before the end of the programm
      flag = 0;             //by setting flag to zero
    }
    a = jahr % 19;
    b = jahr % 4;
    c = jahr % 7;
    d = (19*b + 24) % 30;
    e = (2*b + 4*c + 6*d + 5) % 7;
    tag = d + e + 22;
    if(tag <= 31) {
      if(flag <= 1) {
        printf("%i ist Ostern am %2d.  März.\n", jahr, tag);
        flag++;
      }
      else if(flag >= 3) {
      }
      else {
        printf("...\n\n");
        flag++;
      }
    }
    else {
      if(flag <= 1) {
        tag = tag - 31;
        printf("%i ist Ostern am %2d.  April.\n", jahr, tag);
        flag++;
      }
      else if(flag >= 3) {
      }
      else {
        printf("...\n\n");
        flag++;
      }
    }
  jahr++;
  }
  printf("--> weiter mit ENTER\n");
  return 0;
}
