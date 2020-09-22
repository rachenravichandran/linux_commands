#include <stdio.h>


/*
	File name :wc_3b.c
	Day 	  :6
	Purpose   :word count for  n lines
*/

int main(int argc,char *argv[])
{
	if(argc != 2)
	{
		puts("Usage error. Try: wc <file-name>");
		exit (1);
	}
	FILE *fp;
	char ch, prevch = 'a';
	int line = 0, word=0;
	fp = fopen(argv[1],"r");
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
			if(prevch == '\n' || prevch == ' ')
			{
				prevch = ch;
				continue;
			}
			else
			{
				word++;
			}
		}
		if( ch == ' ' && prevch != ' ' && prevch != '\n') 
		{
			word++;
		}
		prevch = ch;
	}
	printf("Line Count\t%d\nWord Count\t%d\nCharacter Count\t%d\n",line,word,ftell(fp));
	fclose(fp);
	return 0;
}

