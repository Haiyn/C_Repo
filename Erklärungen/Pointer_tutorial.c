/* POINTER           Holen sich mit deklarierten Zeigern (*) Werte aus einer Adresse (&a, a=GZ) aus dem Stack

Zeigeroperator *
Adressoperator & */

int a = 7;
int *z_a;
z_a = &a;


char bu = 'A';
char text[20+1];
//Im Stack steht die Variable 'text' mit der Adresse zum Heap.
//Im Heap steht der eigentliche Inhalt der Variable ('Hannes')

//text = "String";          Diese Zuweisung weist nicht den Text sondern den Adresszeiger zu!
//DESHALB: FALSCH
strcpy(text, "Hannes");   //kopiert den String "Hannes" an die Adresse des Stacks von 'text' --> Heap


SIEZOF          //Gibt die Länge eines Arrays in Byte zurück

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
