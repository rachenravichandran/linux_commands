#include <stdio.h>


/*
	File name :append_4.c
	Day 	  :6
	Purpose   :Append source to destination
*/

int main(int argc,char *argv[])
{
	if(argc < 2 || argc > 3)
	{
		puts("Usage error. Try: append [source] <destination>");
		exit (1);
	}
	if(argc == 3)
	{
		FILE *source,*dest;
		char ch;
		source = fopen(argv[1],"r");
		dest = fopen(argv[2],"a");
		if(source == NULL || dest == NULL)
		{
			perror("Error opening the file");
			exit (2);
		}
		while ((ch = fgetc(source))!=EOF)
		{
			fputc(ch,dest);
		}
		puts("File appending done");
		fclose(source);
		fclose(dest);
	}
	if(argc == 2)
	{
		FILE *fp;
		char ch;
		fp = fopen(argv[1],"a");
		if(fp == NULL)
		{
			perror("Error opening the file");
			exit (2);
		}
		while ((ch = getchar())!=EOF)
		{
			fputc(ch,fp);
		}
		puts("File appending done");
		fclose(fp);
	}
	return 0;
}

