#include <stdio.h>
#include <string.h>

int main()
{
	char str[256] = "";
	while(1)
	{
		char temp[64];
		scanf("%s", temp);
		if(!strcmp(temp, "#")) break;
		else
		{
			if(strlen(str) == 0)
			{
				strcpy(str, temp);
			}
			else
			{
			strcat(str, " ");
			strcat(str, temp);
			}
			
		}
	}
	int p=strlen(str)-1;
	for (int i=p; 1; i--)
	{
		if(str[i] == 32)
		{
			char temp[64]="";
			strncpy(temp, str+i+1, p-i);
			temp[strlen(temp)]='\0';
			printf("%s ", temp);
			p=i-1;
		}
		if(i == 0)
		{
			char temp[64]="";
			strncpy(temp, str, p+1);
			temp[strlen(temp)]='\0';
			printf("%s ", temp);
			break;
		}
	}
	return 0;
}
