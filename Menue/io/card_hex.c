#include "../util/card_header.h"

void mainHex(t_field *f) {
  // Load the entries to the strucht from text file
  loadEntries(f, 4);
  int i = 1;
  f -> mom = f -> start;
  printf("\n%-4s %-12s %-10s %-10s %-10s %-20s %-15s %-15s %-15s",
                "Nr.",
                "Char. Name",
                "Card Name",
                "Card Type",
                "Damage",
                "Effects",
                "BEFORE",
                "MOM",
                "AFTER");
  while (f -> mom != 0) {
    printf("\n[%-2d] %-12s %-10s %-10s %-10s %-20s %-15p %-15p %-15p",
                  i,
                  f -> mom -> characterName,
                  f -> mom -> cardName,
                  f -> mom -> cardType,
                  f -> mom -> damageNumber,
                  f -> mom -> effectType,
                  f -> mom -> before,
                  f -> mom,
                  f -> mom -> after);
    f -> mom = f -> mom -> after;
    i++;
  }

  // Keep the menu open until user confirms exit
  waitForExit();
  return;
}
