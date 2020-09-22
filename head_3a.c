#include <stdio.h>


/*
	File name :head_3a.c
	Day 	  :6
	Purpose   :head of  n lines
*/

int main(int argc,char *argv[])
{
	if(argc != 3)
	{
		puts("Usage error. Try: head n <file-name>");
		exit (1);
	}
	FILE *fp;
	char ch;
	int line = 1;
	int n = atoi(argv[1]);
	fp = fopen(argv[2],"r");
	if(fp == NULL)
	{
		perror("Error opening the file");
		exit (2);
	}
	while ((ch = fgetc(fp))!=EOF)
	{
		if( ch == '\n')
		{
			line++;
		}
		if( line > n)
		{
			fclose(fp);
			return 0;
		}
		printf("%c",ch);
	}
	fclose(fp);
	return 0;
}

