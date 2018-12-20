#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Liste als neuer Typ
typedef struct m_card {         // m_card ist ein Muster, benötigt für die Adresspointer
  char characterName[20+1];
  char cardName[20+1];
  int damageNumber;

  struct m_card *before;         // Adresspointer für vorherigen Listeneintrag
  struct m_card *after;          // Adresspointer für nächsten Listeneintrag
} t_card;

//Liste als neuer Typ ohne Zeiger --> zum Einlesen
typedef struct {
  char characterName[20+1];
  char cardName[30+1];
  char cardType[10+1];
  int damageNumber;

  t_card *mom,
         *start,
         *last;
} t_field;

void list_add();
void add_entry();
void debug();

int main() {

  t_field field;                    // Lokale Pointer
  t_field *f = &field;
  f -> mom = 0;
  f -> start = 0;
  f -> last = 0;
  //Lese 3 Datensätze ein
  int i;
  for(i = 0; i < 3; i++) {
    char input[3+1];
    printf("\nPlease enter a Character name: ");
    scanf("%s", f -> characterName);
    fflush(stdin);

    list_add(f);
  }
  debug(f);
  return 0;
}

void list_add(t_field *f) {
  f -> mom = (t_card*)malloc(sizeof(t_card));          // Reserviert Größe des structs im Hauptspeicher, Typecast nötig, da return value von malloc Void-Zeiger ist
  add_entry(f);                                    // Kopiert eingelesenes in die Liste
  f -> mom -> before = f -> last;
  f -> mom -> after = 0;
  if(f -> last == 0)  f -> start = f -> mom;
  else f -> last -> after = f -> mom;

  f -> last = f -> mom;
}

void add_entry(t_field *f) {
  strcpy(f -> mom -> characterName, f -> characterName);
}

void debug(t_field *f) {
  f -> mom = f -> start;
  while (f -> mom) {
    printf("\n %-10s %X %X %X",
                  f -> mom -> characterName,
                  f -> mom,
                  f -> mom -> before,
                  f-> mom -> after);

    f -> mom = f -> mom -> after;
  }
}
