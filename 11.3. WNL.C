void show_wnl(int year, int month, int day, int week)
{
        int month_day;
        char date[31];
        char j = 0;
        int mark = 0;
        int n_day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int l_day[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

        /* Judge leapyear */

        if((!(year%4)&&(year%100)) || !(year%400) )
        {
                month_day = l_day[month-1];
        }
        else
        {
                month_day = n_day[month-1];
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
                        if(*(date + j)==day)
                        {
                                printf(" [ %d]",*(date + j));       
                        }
                        else if(*(date + j)==day+1)
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
                        if(*(date + j)==day)
                        {
                                printf(" [%d]",*(date + j));
                        }
                        else if(*(date + j)==day+1)
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

int output_week(int year,int month, int day)
{
        /*base year = 1980-1-1, Tuesday*/
        int days = 0;
        int final_week;
        int i = 1980;
        int j = 1;
        int n_day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int l_day[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

        for (i = 1980;i < year; i++)
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

        for (j=1; j<month; j++)
        {
                if((!(year%4)&&(year%100)) || !(year%400))
                {
                        days = days + *(l_day + j -1);
                }
                else
                {
                        days = days + *(n_day + j -1);
                }

        }

        /*   days = days + day;        Current date-not need */

        final_week = (days+2)%7;

       /*  printf("%d",final_week);  */ 
       return final_week;  

}



main()
{
        int week;
        int month;
        int day;
        int year;
        int output;

        printf("Please input a date:");
        scanf("%d-%d-%d",&year,&month,&day);
        week = output_week(year,month,day);
        show_wnl(year,month,day,week);   
        
}
