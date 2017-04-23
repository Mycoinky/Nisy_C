#include "swall.h"

void initwall(swall * wall)
{
	int i = 0;
	for(i = 0; i <WALLLEN; i++)
	{
		wall->x[i] = WALLLEN+i;
		wall->y[i] = WALLLEN+i;
	}
	
}

void secwall(swall * wall)
{
	int i = 0;
	for(i = 0; i <WALLLEN; i++)
	{
		wall->x[i] = 40+WALLLEN+i;
		wall->y[i] = WALLLEN+i;
	}
	
}

void showwall(swall * wall)
{
	int i;
	for(i = 0; i <WALLLEN; i++)
	{
		gotoxy(wall->x[i],wall->y[i]);
		printf("&");
	}
}

void delewall(swall * wall)
{
	int i;
	for(i = 0; i <WALLLEN; i++)
	{
		gotoxy(wall->x[i],wall->y[i]);
		printf(" ");
	}
}