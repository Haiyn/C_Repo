#include <stdio.h>

int main() {
  //SIEZOF          Gibt die Länge eines Arrays in Byte zurück

  int a = 7;
  int l;

  l = siezof(int);

  int mat[3][5];
  l = siezof(mat);    //60 = 4 (1 Byte) * ( 3*5 )



  //TYPECAST
  int a = 7;
  int erg;
  char b = 'A';
  float f = 2.89;
  double d = 3.85;

  erg = a +     (int) b     +     (int) f      +      (int) d
          /*imliziter cast    expliziter cast    expliziter cast
          n. erforderlich               erforderlich*/


  //BITWEISE VERSCHIEBUNG

  int a = 7;
  int b = a >> 2;       //7/20² = 1     da nur Ganzzahldivison --> Nachkommastellen abgeschnitten
    a = 7;
    b = a << 3;       //7*2³ = 52     ... 0000 0111 --> 0111 0000




  //?:

  a>b? b=4 : a =4
  //     true  false

  // ist das gleiche wie:

  if(a>b) b=4;
  else    a=4;

  return 0;
}
