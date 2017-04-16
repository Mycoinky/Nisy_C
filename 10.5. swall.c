#include "swall.h"

void initwall(swall * wall)
{
	int i = 0;
	for(i = 0; i <WALLLEN; i++)
	{
		wall->x[i] = WALLLEN;
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

