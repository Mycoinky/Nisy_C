#include "snakebd.h"
#include "snakept.h"
#include "canvas.h"
#include "swall.h"

#define UP     0X4800
#define DOWN   0X5000
#define LEFT   0X4b00
#define RIGHT  0X4d00
#define EXIT   0X11B

main()
{
	snakebody sbody;
	snakepoint spoint;
	swall wall;
	int key = 0X4800;
	int i;
	clrscr();
	initcanvas();
	initwall(&wall);
	showwall(&wall);
	initsnake(&sbody);
	showsnake(&sbody);
	initsnakepoint(&spoint,&wall);
	showsnakepoint(&spoint);
	
	do
	{
		if(kbhit())
			{
				key = bioskey(0);
			}
			
		delay(50);
		
		switch(key)
		{
			case UP:
				movesnake(&sbody);
				sbody.y[0] = sbody.y[0] == 2 ? 23 : sbody.y[0] - 1;
				break;
			case DOWN:
				movesnake(&sbody);
				sbody.y[0] = sbody.y[0] == 23 ? 2 : sbody.y[0] + 1;
				break;
			case LEFT:
				movesnake(&sbody);
				sbody.x[0] = sbody.x[0] == 2 ? 77 : sbody.x[0] - 1;
				break;
			case RIGHT:
				movesnake(&sbody);
				sbody.x[0] = sbody.x[0] == 77 ? 2 : sbody.x[0] + 1;
				break;
			default:
				break;
		}
		
		if((sbody.x[0]==spoint.x)&&(sbody.y[0]==spoint.y))
			{
				addsnakepoint(&sbody);
				showsnake(&sbody);
				initsnakepoint(&spoint,&wall);
				showsnakepoint(&spoint);
			}
		else
			{
				showsnake(&sbody);
			}
		
		for(i = 0; i< WALLLEN; i++)
		{
			if((sbody.x[0]==wall.x[i])&&(sbody.y[0]==wall.y[i]))
				{
					gotoxy(33,12);
					printf("Game Over!");
					return;
				}
		}
				
		if(sbody.length == sbody.max_len)
			{
					gotoxy(33,12);
					printf("WIN!");
					return;
			}
		
					
	}while(key!=EXIT);

}
