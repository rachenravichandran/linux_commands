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
	int i=1,j,lineN[3]={0,0,0}, charN[3]={0,0,0},lcount = 1;
	int scount[3] = {0,0,0}, ecount[3] = {0,0,0};
	fp = fopen(argv[1],"r");
	if(fp == NULL)
	{
		perror("Error opening the file");
		exit (2);
	}
	while ((ch = fgetc(fp))!=EOF)
	{
		if(ch == '\n')
		{
			lcount++;
			i = 1;
			continue;
		}
		if( ch == '{' || ch == '[' || ch == '(')	//(count%2 == 0 && ch == '}'))
		{
			j = check(ch);
			scount[j]++;
			lineN[j] = lcount;
			charN[j] = i;
	        }
		if( ch == '}' || ch == ']' || ch == ')')	//(count%2 == 0 && ch == '}'))
		{
			j = check(ch);
			ecount[j]++;
		}
		if(scount[j] < ecount[j])
		{
			ecount[j]--;
			printf("Error in line number %d at %d\n",lcount,i);
			i++;
			continue;
		}
		i++;
	}
	for(i=0;i<3;i++)
	{
		if(scount[i]>ecount[i])
		{
			printf("Error in line number %d at %d\n",lineN[i],charN[i]);
		}
	}
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
