3   17  68  24  72  11  96  28  34  19  86  18  7   26  54
                            __
-->     __                Median                    __ <--
      größer              tausche                 kleiner
        26                                          68
                7                               72
                        18                  96
//keine Elemente mehr links von Median, die größer sind, aber noch Elemente auf der rechten Seite, die kleiner sind
                            19      28
                                  Median
                                28  34

3   17  26   24  7  11  18  19  28  34  86  96  72  68  54
             __                 ||
           Median
        19                  26
             18         24


/*Sobald ein Sort für einen Median erledigt ist und die Zahlensequenz noch nicht richtig sortiert ist, werden am
Median aufgespalten und jeweils für die rechte und linke Seite wiederholt (Median suchen, tauschen,...) bis die
Sortierung fertig ist.*/

/*    2^x = n
      x   = ld n --> Tiefe (Anzahl Rekursive Durchläufe)    */


// SORT BY NAMES

typedef struct {
  char array[ANZAHL];
} t_feld;

void main() {
  init(f);
  sort(...);
}

void init(t_feld *f) {
  char *temp;
  laenge = ... rand()....
  temp = (char*)malloc(lange);
}

void sort(...) {
  // NO MORE INTEGERS TO COMPARE, USE STRCMP TO COMPARE STRINGS
  if(strcmp(f->array[i], f -> array[j] > 0))

  // TO SWITCH, JUST SWITCH POINTERS
}
