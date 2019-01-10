#include <stdio.h>

/*Aufgabe
Schreiben Sie ein Programm, welches ASCII Dateien durchblättern kann. Sowohl seiten- als auch zeilenweises vor- und zurückblättern soll unterstützt werden.

Am Anfang einer Zeile soll eine fünfstellige Zeilenangabe gefolgt von einem Doppelpunkt und einem Leerzeichen ausgegeben werden. Danach folgt der eigentlich Zeileninhalt.
Eine Zeile darf, egal wie lang sie ist, nur innerhalb einer Zeile auf dem Bildschirm dargestellt werden, muß also spätestens nach 73 Zeichen abgetrennt werden.
*/
int main(void) {
  FILE *fp;
  int i;
  char str[68], input[5];

  fp = fopen("ascii300.txt", "r");
  if(fp == NULL) {
    perror("Error opening file.");
    return (-1);
  }
  for(int page = 1; page <= 100000;) {
    scanf("%c", input);
    switch((char)input) {
      case '+':
        page++;
      case '-':
        page--;
      case 'exit':
        break;
    }
    printf("\n/*  PAGE %d   */\n", page);
    for(int row = 1; row <= 100000; row++) {
        fgets(str, 60, fp);
        if(str != NULL) {
          printf("\n%d\t:? %s", row, str);
        }
        if(row >=10) {
          row = 1;
          break;
        }
    }
  }



  return 0;
}
