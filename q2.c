#include<stdio.h> 
#include<string.h>
struct student
{
	char name[200];
	char rollno[200];
	char email[200];
};
void prepend(char* s, const char* t)
{
    size_t len = strlen(t);
    memmove(s + len, s, strlen(s) + 1);
    memcpy(s, t, len);
}
void printStudent(struct student s)
{
	printf("%s\n", s.name);
	printf("%s\n", s.rollno);
	printf("%s\n", s.email);
}
int main(int argc, char *argv[])
{ 
	FILE* fp;
	fp = fopen("q2_file.txt","r");
	char buff[500];
	struct student arr[5];
	int i = 0;
	while(fgets(buff, sizeof(buff), fp) != NULL) {
		strcpy(arr[i].name,buff);

		fgets(buff, sizeof(buff), fp);	
		strcpy(arr[i].rollno,buff);	

		fgets(buff, sizeof(buff), fp);	
		strcpy(arr[i].email,buff);	
		
		i++;
	}

	int j;
	for (j = 0; j < i; j++)
	{
		printf("%s\n", arr[j].name);
		printf("%s\n", arr[j].rollno);
		printf("%s\n", arr[j].email);
	}
	fclose(fp);
	while(1)
	{
		printf("%s\n","Select one from menu");
		int testInteger;
	    printf("%s\n","1 to add records \n2 to view records\n3 to delete records\n0 to exit ");
		scanf("%d", &testInteger);


		if(testInteger==1)
		{
			int newinput;
			printf("%s\n","1 to edit/add 1st friend records\n 2 to edit/add 2nd friend delete records ");
			scanf("%d", &newinput);
			if(newinput==1 || newinput==2)
			{
				printf("%s\n", "Enter name");
				scanf("%s",arr[newinput].name);
				prepend(arr[newinput].name, "Name: ");
				strcat(arr[newinput].name, "\n");

				printf("%s\n", "Enter rollno");
				scanf("%s",arr[newinput].rollno);
				prepend(arr[newinput].rollno, "Roll No. ");
				strcat(arr[newinput].rollno, "\n");

				printf("%s\n", "Enter email");
				scanf("%s",arr[newinput].email);
				prepend(arr[newinput].email, "Email: ");
				strcat(arr[newinput].email, "\n");

				if(newinput==2)
				{
					i=3;
				}
			}

		}
		else if(testInteger==2)
		{

	 		printf("%s\n","0 to view your own records \n1 to view 1st friend records\n2 to view 2nd friend records ");
			int newinput;
			scanf("%d", &newinput);
			
			if(newinput>=0 && newinput<=2)
			{
				printStudent(arr[newinput]);
			}

		}
		else if(testInteger==3)
		{
			printf("%s\n","0 to delete your own records \n1 to delete 1st friend records\n2 to delete 2nd friend records ");
			int newinput;
			scanf("%d", &newinput);
			if (newinput==0 || newinput==1)
			{
				int x;
				for (x=newinput; x < i-1; ++x)
				{
					arr[x]=arr[x+1];
				}
			}
			i--;
			

		}
		else if(testInteger==0)
		{
			break;
		}

	}
fp = fopen("q2_file.txt","w");
int x = 0;
for (; x < i; ++x)
{
	fputs(arr[x].name, fp);
	fputs(arr[x].rollno, fp);
	fputs(arr[x].email, fp); 
	
}


}