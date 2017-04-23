#include "snakebd.h"

void initsnake(snakebody * sbody)
{
	sbody->x[0] = 30;
	sbody->y[0] = 10;
	sbody->x[1] = 31;
	sbody->y[1] = 10;	
	sbody->x[2] = 32;
	sbody->y[2] = 10;	
		
	sbody->max_len = 10;
	sbody->length = 2;	
}


void movesnake(snakebody * sbody)
{
	int i;
	sbody->tailx = sbody->x[sbody->length];
	sbody->taily = sbody->y[sbody->length];  

	for(i = sbody->length; i > 0; i--)
	{
		sbody->x[i] = sbody->x[i-1];
		sbody->y[i] = sbody->y[i-1];  		
	}	
}


void addsnakepoint(snakebody * sbody)
{
	sbody->length++;	
	sbody->x[sbody->length] = sbody->tailx;
	sbody->y[sbody->length] = sbody->taily;	
}


void showsnake(snakebody * sbody)
{
	int i;
	gotoxy(sbody->tailx,sbody->taily);
	printf(" ");
	
	for(i = 0;i < (sbody->length+1);i++)
	{
		gotoxy(sbody->x[i],sbody->y[i]);
		printf("*");
	}	

	
}


void resetsnake(snakebody * sbody)
{
	int i;
	for(i=0; i<sbody->length; i++)
	{
		gotoxy(sbody->x[i],sbody->y[i]);
		printf(" ");
	}
	
	for(i=0; i<sbody->length; i++)
	{
		sbody->x[i] = 3;
		sbody->y[i] = 3;
	}
}