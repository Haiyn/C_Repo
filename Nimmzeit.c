#include <stdio.h>
#include <conio.h>
//#include <stdlib.h>
//#include <sys\types.h>
#include <sys\timeb.h>
//#include <time.h>

double nimmzeit(void);


void main(void)
{
  double mw1, mw2;
  mw1 = nimmzeit();
  printf("\n... druecke beliebige Taste\n");
  getch();
  mw2 = nimmzeit();
  printf("\nvergangene Zeit: %.3f sec\n",mw2-mw1);
  getch();

}

double nimmzeit(void)
{
    double messwert;
    struct timeb tb;

    ftime(&tb);

    messwert = (double)tb.time + (double)tb.millitm/1000.0;

    return(messwert);

}













/*
struct timeb       ==> aus timeb.h
{
	long	time;
	short	millitm;
	short	timezone;
	short	dstflag;
};

*/
