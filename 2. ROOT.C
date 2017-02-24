main()
{
        int a = 1;
        float b = 3;
        int i = 0;

        while(a)
        {

                printf("Please input an integer:");
                scanf("%d",&a);

                while(i<((int)(a/2)))
                {
                      
                        b = (b+a/b)/2;
                        if (((b - (int)b)<0.0001) && ((b*b == a)))
                                {
                                        break;
                                }
                        i++;
                }
        printf("The rooting of a is: %.5f\n",b);
        printf("i =:%d",i);
        }



}
