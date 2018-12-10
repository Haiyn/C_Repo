#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
	
	FILE *ausgabe, *einlesen;
	
	char name[]="Hannes", text[80+1];
	int  i, j=84, k;
	float f=3.45;
	double d=45.123;
	
		
	ausgabe = fopen("c:\\testfscanf.txt","w");
	
	if(!ausgabe)
		printf("so n Mist!");
	else
	{
		for(i=1 ; i<=5 ; i++)
		{
  	       fprintf(ausgabe,"%3i%-10s%5i%10.2f%10.2lf\n", i, name, j*i,f*i,d*i );	//ohne \n sieht blöd aus
//  	       fprintf(ausgabe,"%i %s %i %f %lf\n", i, name, j*i,f*i,d*i );	// funtioniert nur mit \n
		}
	}
	fclose(ausgabe);
	
	

	einlesen = fopen("c:\\testfscanf.txt","r");
	
	if(!ausgabe)
		printf("so n Mist!");
	else
	{
		for(i=1 ; i<=5 ; i++)
		{
 	       fscanf(einlesen,"%3i%10s%5i%f%lf", &k, text, &j,&f,&d );	
//  	       fscanf(einlesen,"%i %s %i %f %lf", &k, text, &j,&f,&d );	   
  	       fflush(stdin);
  	        printf("%3i, %10s, %5i, %10.2f, %10.2lf\n", k, text, j,f,d );	
		}
	}
	fclose(einlesen);
	
	

	return (42);
}


