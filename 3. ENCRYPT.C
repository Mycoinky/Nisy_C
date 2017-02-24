main()
{
        char *i;
        int j = 0;
        printf("Please input a string:");
        scanf("%[^\n]",i);
        printf("%s\n",i);

        while(*(i+j))
        {
                *(i+j) = ~*(i+j);
                j++;
                                
        }

        j = 0;
        while(*(i+j))
        {
                printf("%x",*(i+j));
                j++;
        }

        printf("\n");                   

        j = 0;
        while(*(i+j))
        {
                *(i+j) = ~*(i+j);
                j++;
        }

        printf("%s\n",i);                        


}
