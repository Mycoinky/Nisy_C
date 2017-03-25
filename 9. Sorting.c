#define total 10

void input_num(int*p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",p+i);
	}
}

void show_num(int*p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",*(p+i));
	}
	printf("\n");
}

int choose( char (*p)[5] , char * str)
{
	int i = 0;

	while(1)
	{
		if(!strcmp(str, *(p+i)))
		{
			return i;	
		}
	i++;
	}	

	return -1;
}

void sort_mix(int*p,int n)
{
	int i;
	int j;
	int temp;
	for(i = 0; i<n-1; i++)
	{
		for(j=0;j<n-i-1;j++)
		{

			if(i%2)
			{

				if(*(p+j)<*(p+j+1))
					{
						temp = *(p+j);
						*(p+j) = *(p+j+1);
						*(p+j+1) = temp;
					}
			}
			else
			{
			
				if(*(p+j)>*(p+j+1))
					{
						temp = *(p+j);
						*(p+j) = *(p+j+1);
						*(p+j+1) = temp;
					}
			}
		}
	}
}

void sort_num(int*p,int n)
{
	int i;
	int j;
	int temp;
	for(i = 0; i<n-1; i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(*(p+j)>*(p+j+1))
				{
					temp = *(p+j);
					*(p+j) = *(p+j+1);
					*(p+j+1) = temp;
				}
		}
	}
}


void sort_mum(int*p,int n)
{
	int i;
	int j;
	int temp;
	for(i = 0; i<n-1; i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(*(p+j)<*(p+j+1))
				{
					temp = *(p+j);
					*(p+j) = *(p+j+1);
					*(p+j+1) = temp;
				}
		}
	}
}


void sort(int*p,int n,int i)
{
	switch(i)
	{
		case 0:
			sort_num(p,n);
			break;
		case 1:
			sort_mum(p,n);
			break;
		case 2:
			sort_mix(p,n);
			break;
		default:
			return;

	}
}


main()
{
 	int * p = (int *) malloc(total * sizeof(int));
 	int n = total;
	int i = 0;
	char * type = (char*)malloc(5*sizeof(char));
	char s[4][5] = {"stl","lts","mix",0};
 	
 	input_num(p,n);
 	
 	while(1)
 	{
	 	printf("Please input the type:");
	 	scanf("%s",type);
		i = choose(s,type);

		sort(p,n,i);
	 	show_num(p,n);
	}

}



