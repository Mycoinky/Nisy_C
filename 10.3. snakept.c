#include "snakept.h"

void initsnakepoint(snakepoint * spoint, swall* wall)
{
	int i;
	spoint->x = (rand() % 76)+1;
	spoint->y = (rand() % 21)+3;
	
	for(i=0;i<WALLLEN;i++)
	{
		if((spoint->x==wall->x[i])&&(spoint->y==wall->y[i]))
			{
				initsnakepoint(spoint, wall);                         /*检测是否与墙重复了*/
				return;
			}
	}

}

void showsnakepoint(snakepoint * spoint)
{
	gotoxy(spoint->x,spoint->y);
	printf("*");
}

void delesnakepoint(snakepoint * spoint)
{
	gotoxy(spoint->x,spoint->y);
	printf(" ");
}




