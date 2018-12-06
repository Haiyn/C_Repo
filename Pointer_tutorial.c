/* POINTER           Holen sich mit deklarierten Zeigern (*) Werte aus einer Adresse (&a, a=GZ) aus dem Stack

Zeigeroperator *
Adressoperator & */

int a = 7;
int *z_a;
z_a = &a;


char bu = 'A';
char text[20+1];        //Adresse im Stack: 4711
char *z;
//Im Stack steht die Variable 'text' mit der Adresse zum Heap.
//Im Heap steht der eigentliche Inhalt der Variable ('Hannes')

//text = "String";                Diese Zuweisung weist nicht den Text sondern den Adresszeiger zu!
//DESHALB: FALSCH
strcpy(text, "Hannes");         //kopiert den String "Hannes" an die Adresse des Stacks von 'text' --> Heap
z = text;                       //Adresse im Stack: 4711
