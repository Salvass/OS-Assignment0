#include<stdio.h> 
#include <string.h> 

void inver(char *arr) {
    int i=0,j=strlen(arr)-1;
    char tmp;
    while (i < j) {
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
        i++;
        j--;
    }
}

int hasVow(char *arr) {
    int count = 0, i=0;
    for(i=0; i<strlen(arr); i++) {
        if(arr[i] == 'A' || arr[i] == 'a' || arr[i] == 'E' || arr[i] == 'e' ||
        arr[i] == 'I' || arr[i] == 'i' || arr[i] == 'O' || arr[i] == 'o' ||
        arr[i] == 'U' || arr[i] == 'u') {
            count++;
        }
    }
    return count;
}
int main(int argc, char *argv[])
{ 
	FILE* fp;
	int count=0;
	printf("%s\n",argv[1] );
	if(strcmp(argv[1],"a")==0)
	{
		fp = fopen("q3_a.txt","r");
	}
	else if(strcmp(argv[1],"b")==0)
	{
		fp = fopen("q3_b.txt","r");
	}
	else
	{
		printf("%s\n","Invalid input or file not found");
		return 0;
	}

	char buffer[500];
	char arr[50][129];
    int ct = 0;
	while(fscanf(fp, "%s", buffer)!=-1)
	{
		char sending[450];
	    sending[0] = '\0';

	    char *ptr = strtok(buffer, " ");
	    while(ptr != NULL) {
			
			if(hasVow(ptr) == 0) {
				  inver(ptr);
	        }
	        printf("%s\n", ptr);

	        ptr = strtok(NULL, " ");
	        ct++;
	    }
	}
}