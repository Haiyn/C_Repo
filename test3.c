#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	typedef struct m_lied
	{
		char lied_name[30+1];
		char saenger_name [30+1];

		struct m_lied *davor;
		struct m_lied *danach;
	} t_lied;

	typedef struct
	{
		char lied_name[30+1];
		char saenger_name[30+1];

		t_lied *mom;
		t_lied *start;
		t_lied *zwischen;
	} t_feld;

void add_entry();
void up_listeAdd();

void main()
{
	int i;
	t_feld feld;
	t_feld *f = &feld;
	f -> mom = 0;
	f -> start = 0;
	f -> zwischen = 0;

	for(i=0; i<3;i++)
	{
		printf ("Gib %d Lied ein:", i+1);//ovo %d je samo kao nekako radi lipsega izgleda
		scanf("%s", f -> lied_name);
		fflush(stdin);
		printf("Gib %d den Saenger ein: ", i+1);
		scanf("%s", f -> saenger_name);
		fflush(stdin);
		up_listeAdd(f);

	}
	/*up_hex(f)*/
}

void add_entry(t_feld *f)
{
	strcpy(f -> mom -> lied_name, f->lied_name);
	strcpy(f -> mom -> saenger_name, f ->saenger_name);
}

void up_listeAdd(t_feld *f)
{
	f -> mom = (t_lied *) malloc(sizeof(t_lied));
	add_entry(f);
	printf("add_entry completed.\n");
	f -> mom -> davor = f -> zwischen;
	f -> mom -> danach = 0;

		if(f -> zwischen == 0) f ->start = f -> mom;
		else f -> zwischen -> danach = f -> mom;
		f -> zwischen = f -> mom;
}
