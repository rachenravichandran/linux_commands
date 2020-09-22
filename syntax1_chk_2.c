#include <stdio.h>


/*
	File name :syntaxchk_vc_2.c
	Day 	  :6
	Purpose   :Check for braces, paranthesis, square bracket
*/

int check (char );
int main(int argc,char *argv[])
{
	if(argc != 2)
	{
		puts("Usage error. Try: vc <file-name>");
		exit (1);
	}
	FILE *fp;
	char ch;
	int i,count[3] = {0,0,0};
	fp = fopen(argv[1],"r");
	if(fp == NULL)
	{
		perror("Error opening the file");
		exit (2);
	}
	while ((ch = fgetc(fp))!=EOF)
	{
		if( ch == '{' || ch == '[' || ch == '(')	
		{
			i = check(ch);
			count[i]++;
	        }
		if( ch == '}' || ch == ']' || ch == ')')
		{
			i = check(ch);
			count[i]--;
			if(count[i] < 0)
			{
				printf("Unbalanced [],(),{} are present\n");
				exit (1);
			}
			
		}
	}
	for(i=0;i<3;i++)
	{
		if(count[i] != 0)
		{
			printf("Unbalanced [],(),{} are present\n");
			exit (1);
		}
	}
	puts("The program has no error");
	return 0;
}

int check(char ch)
{
	int count;
	if(ch == '{' || ch == '}')
	  return count = 0;
	else if (ch == '[' || ch == ']')
	  return count = 1;
	else
	  count = 2;
	return count;
}
