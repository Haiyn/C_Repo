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
  while(jahr <= 2100) {
    if((jahr == 1954) || (jahr == 1981)) {                      //In den Jahren 1954 und 1981 kann der Tag nicht berechnet werden!
      printf("%i ist Ostern nicht errechenbar!\n", jahr);
    }
    else {
      a = jahr % 19;
      b = jahr % 4;
      c = jahr % 7;
      d = (19*b + 24) % 30;
      e = (2*b + 4*c + 6*d + 5) % 7;
      tag = d + e + 22;
      if(tag <= 31) {
        printf("%i ist Ostern am %2d.  März.\n", jahr, tag);
      }
      else {
        tag = tag - 31;                                         //Liegt der Tag nicht im März, nimmt er einen Wert >31 an.
        printf("%i ist Ostern am %2d.  April.\n", jahr, tag);   //Damit der richtige Apriltage erreicht werden kann, muss also ein Monat abgezogen werden.
      }
    }
  jahr++;
  }
  return 0;
}
