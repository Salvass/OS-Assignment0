 #include<stdio.h> 
int main(int argc, char *argv[])
{ 
	FILE* fp;
	int count=0;
	if(argv[1]!=NULL)
	{	printf("%s\n",argv[1] );
		if(strcmp(argv[1],"a")==0)
		{
			fp = fopen("q1_a.txt","r");
		}
		else if(strcmp(argv[1],"b")==0)
		{
			fp = fopen("q1_b.txt","r");
		}
		else if(strcmp(argv[1],"c")==0)
		{
			fp = fopen("q1_c.txt","r");
		}
		else
		{
			printf("%s\n","Invalid input or file not found");
			return 0;
		}
		char buff[500];
		while(fscanf(fp, "%s", buff)!=-1)
		{
			int i = 0;
			for (; i < strlen(buff); i++)
			{
				if(buff[i]<='9' && buff[i]>='0')
				{
					count++;
				}
			}
		}

		printf("%i\n", count);
	}
	else
	{
		printf("%s\n","Please specify either a or b to open file" );
	}
}