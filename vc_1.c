#include <stdio.h>


/*
	File name :vc_1.c
	Day 	  :6
	Purpose   :Count vowels and consonants
*/

int main(int argc,char *argv[])
{
	if(argc != 2)
	{
		puts("Usage error. Try: vc <file-name>");
		exit (1);
	}
	FILE *fp;
	char ch,vowel[]={'a','e','i','o','u','A','E','I','O','U'};
	int vcount=0,ccount=0,i,flag;
	fp=fopen(argv[1],"r");
	if(fp == NULL)
	{
		perror("Error opening the file");
		exit (2);
	}
	while ((ch = fgetc(fp))!=EOF)
	{
		if( (ch<'A' && ch>'Z') || (ch<'a' && ch>'z') )
		{
                    continue;
		}
		for(i=0,flag=0;i<10;i++)
		{
			if(ch == vowel[i])
			{
				vcount++;
				flag = 1;
				break;
			}
		}
		if(flag != 1)
		{
			ccount++;
		}
	}
	printf("Vowel count : %d\nConsonant count : %d\n",vcount,ccount);
	return 0;
}
