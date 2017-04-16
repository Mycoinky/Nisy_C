#include "date.h"

#define UP 0X4800
#define DOWN 0X5000
#define LEFT 0X4b00
#define RIGHT 0X4d00
#define EXIT 0X11B


void main()
{
	date pdate;
	int week;
	int key = 0;
	input_data(&pdate);
	week = output_week(&pdate);
	show_calendar(&pdate,week);   
	
	do
	{
		printf("\n");
		key = bioskey(0);
		switch(key)
		{
			case UP:
				pdate.year++;
				printf("The date is : %d-%d-%d \n",pdate.year,pdate.month,pdate.day);
				week = output_week(&pdate);
				show_calendar(&pdate,week);
				break;
			case DOWN:
				pdate.year--;
				printf("The date is : %d-%d-%d \n",pdate.year,pdate.month,pdate.day);
				week = output_week(&pdate);
				show_calendar(&pdate,week);
				break;
			default:
				break;
		}
	}while(key!=EXIT);
	
	
	
	
}













