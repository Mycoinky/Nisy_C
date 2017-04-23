
typedef struct
{
	int x[27];  
	int y[27];
	int max_len;
	int length;	
	int tailx;  /*保存尾部数据*/
	int taily;
}snakebody;


void initsnake(snakebody * sbody);
void addsnakepoint(snakebody * sbody);
void movesnake(snakebody * sbody);
void showsnake(snakebody * sbody);
void resetsnake(snakebody * sbody);







