
int a;
char bu;
float f1;
double d1;
char text[80+1];

scanf("%d", &a));

scanf("%c", &bu);

scanf("%f", &f1);

scanf("%lf", &d1);

scanf("%s", text);        //text ist bereits ein Pointer, also kein &

//nach jedem scanf sollte gefluscht werden. (fflush(stdin);) Ansonsten kann es sein, dass der Buffer voll ist.
//Bei scanf werden Zeiger benutzt, da es kein return-value gibt. Deshlab wird die Adresse übergeben.
