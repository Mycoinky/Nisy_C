#include "date.h"


int input_data(date * pdate)
{
		do
		{	
		printf("Please input a date:");
		scanf("%d-%d-%d",&pdate->year,&pdate->month,&pdate->day);
		}while(checkdate(pdate));
}

int checkdate(date * pdate)
{
	if((pdate->year<1980)||(pdate->month<1)||(pdate->month>12)||(pdate->day<1)||((pdate->day>29)&&(isleapyear(pdate)))||(pdate->day>28))
		{
			return 1;
		}
	else
		{
			return 0;
		}	
}


int isleapyear(date * pdate)
{
	return (!(pdate->year%4)&&(pdate->year%100)) || !(pdate->year%400);
}


int output_week(date * pdate)   /*返回当日是周几*/
{
	
	int days = 0;
	int final_week;
  int i = 1980;
  int j = 1;
  int n_day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  int l_day[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

  for (i = 1980;i < pdate->year; i++)
  {
  	if((!(i%4)&&(i%100)) || !(i%400) )
  		{
  			days = days + 366;
  		}
  	else
  		{
  			days = days + 365;
  		}
 	}


	for (j=1; j<pdate->month; j++)
	{
		if(isleapyear(pdate))
			{
				days = days + *(l_day + j -1);
			}
		else
			{
				days = days + *(n_day + j -1);
			}
	}

	final_week = (days+2)%7;
	return final_week;  
}



int show_calendar(date * pdate, int week)
{
	int month_day;
  char date[31];
  char j = 0;
  int mark = 0;
  int n_day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  int l_day[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

        /* Judge leapyear */

  if(isleapyear(pdate))
  	{
  		month_day = l_day[pdate->month-1];
  	}
  else
  	{
  		month_day = n_day[pdate->month-1];
    }
        
	while(j < 31)
	{
		*(date+j) = j + 1;
    j++;
  }

	j = 0;

	printf("   S   M   T   W   T   F   S  \n");

	while(mark < week)
	{
		printf("    ");
		mark++;
	}
       
  while(j < month_day)
  {
  	if(!(mark%7))
  		{
  			printf("\n");
  		}

		if(j < 9)
			{
				if(*(date + j)==pdate->day)
					{
						printf(" [ %d]",*(date + j));
					}
					else if((*(date + j)==pdate->day+1)&&(mark%7))
					{
						printf("  %d",*(date + j));
					}
					else
					{
						printf("   %d",*(date + j));
					}
			}
		else
			{
				if(*(date + j)==pdate->day)
					{
						printf(" [%d]",*(date + j));
					}
				else if((*(date + j)==pdate->day+1)&&(mark%7))
					{
						printf(" %d",*(date + j));
					}
				else
					{
						printf("  %d",*(date + j));
					}
      }
                
		j++;
		mark++;
  }	
	
	
}









