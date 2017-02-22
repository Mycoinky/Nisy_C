main()
{
        int l;
        int i;
        int j;
        int n;
        int play = 1;

        while(play)
        {
                printf("Please input the side length:");
                scanf("%d",&l);
        
                if(l==0)
                {
                        break;
                }
        
                n = l*2;
                for(i=1;i<n;i++)
                {
                        for(j=1;j<n;j++)
                        {
                                if(((i+j)==(l+1)||(j-i)==(l-1)) || ((i-j)==(l-1)||(i+j)==(l*3-1)))
                                {
                                        printf("*");
                                }
                                else
                                {
                                        printf(" ");
                                }
                                if(j==(n-1))
                                {
                                        printf("\n");
                                }
                        }
                }
        }


}
