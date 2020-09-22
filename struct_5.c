#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h>

/*
	File name :struct_5.c
	Day 	  :6
	Purpose   :Database of Crews
*/

struct CREW
	{
	int crewId;
	char name[30];
	int age;
	char grade;
	float salary;
	};  
	
void readStruct(struct CREW *);
void printDetails(struct CREW *,int );
void dispGrade(struct CREW *,int );
void salaryCrew(struct CREW *, int);
void searchId(struct CREW *, int);
	    
int main()
{
	int n,ch,i,lines = 0;
	char choice,dummy;
	
	system("clear");
	struct CREW *members;
	FILE *fp;
	fp = fopen("crew.csv","a+");
	
	puts("Reading crew.csv file");
	i = 0;
	while(!feof(fp))
	{
	     if(i==0)
	     {
		members = (struct CREW *)malloc(sizeof(struct CREW));	     
		if(members == NULL)
		{
			puts("Memory allocation error");
			exit (1);
		}
	     }
	     else
	     {
		members = (struct CREW *)realloc(members, (i+1) * sizeof(struct CREW));	     
		if(members == NULL)
		{
			puts("Memory allocation error");
			exit (1);
		}
	     }
	     fscanf(fp,"%d%[,]c",&members[i].crewId,&dummy);
	     fscanf(fp,"%[^,]s",&members[i].name);
	     fscanf(fp,"%[,]c",&dummy);
	     fscanf(fp,"%d%[,]c",&members[i].age,&dummy);
	     fscanf(fp,"%[^,]c",&members[i].grade);
	     fscanf(fp,"%[,]c",&dummy);
	     fscanf(fp,"%f%[\n]c",&members[i].salary,&dummy);		
	     lines++;
	     i++;
	}	
	n = lines;
	printf("\nThere are %d crews in the file.\n"
	       "Do you want to add some more to the file(y/n)?\n",lines);

	__fpurge(stdin);
	scanf("%c",&choice);
	if(choice == 'y' || choice == 'Y')
	{
		printf("Enter the Number of crews :\n");
		scanf("%d",&n);
		n = n + lines;
		members = (struct CREW *)realloc(members, n  * sizeof(struct CREW));	     
		if(members == NULL)
		{
			puts("Memory allocation error");
			exit (1);
		}
		for(i=lines;i<n;i++)
	 	{
	     		system("clear");
             		printf("Enter the details of member %d :\n",i+1);
			readStruct(&members[i]);
			fprintf(fp,"%d,%s,%d,%c,%f\n",members[i].crewId,members[i].name,
						      members[i].age,members[i].grade,
						      members[i].salary);
	 	}
	}
	fclose(fp);
		
	while(1)
	{
		system("clear");
		printf("Enter your choice\n1.Print the Crew database\n"
		       "2.Display all the crew whose salary is more than a specified salary\n"
		       "3.Search for a given crew based on an id\n"
		       "4.List all crew members for a specified grade\n5.Quit\n");
		scanf("%d",&ch);
 		switch(ch)
		{
			case 1:
			   printDetails(members,n);
			   break;
			case 2:
			   salaryCrew(members,n);
			   break;
			case 3:
			   searchId(members,n);
			   break;
			case 4:
			   dispGrade(members,n);
			   break;
			case 5:
			   puts("Quitting");
			   exit(0);
			default:
			   printf("Invalid option\n");
		}
		puts("Do you want to continue?(y/n)\n");
		__fpurge(stdin);
		scanf("%c",&choice);	   
		if( choice == 'n' || choice == 'N')
		{
			exit(0);
		}		
	}
	return 0;
}

void readStruct(struct CREW *mem)
{
	puts("Enter the crew id:");
	scanf("%d",&(mem->crewId));
	puts("Enter the member name:");
	__fpurge(stdin);
	scanf("%[^\n]s",mem->name);
	puts("Enter the age:");
	scanf("%d",&(mem->age));
	__fpurge(stdin);
	puts("Enter the grade:");
	scanf("%c",&(mem->grade));
	puts("Enter the salary:");
	scanf("%f",&(mem->salary));	
}

void printMem(struct CREW *mem, int i)
{
	printf("\t\tMember %d\nCrew id\t\t%d\nName\t\t%s"
	       "\nAge\t\t%d\nGrade\t\t%c\nSalary\t\t%f\n\n",
               i+1,mem[i].crewId,mem[i].name,mem[i].age,mem[i].grade,mem[i].salary);
}

void printDetails(struct CREW *mem,int n)
{
	int i;
	for(i=0;i<n;i++)
	{	
		printf("\t\tMember %d\nCrew id\t\t%d\nName\t\t%s"
		       "\nAge\t\t%d\nGrade\t\t%c\nSalary\t\t%f\n\n",
                       i+1,mem[i].crewId,mem[i].name,mem[i].age,mem[i].grade,mem[i].salary);
	}
}

void salaryCrew(struct CREW *mem, int n)
{
	int i,flag = 0;
	float sal;
	printf("Enter the salary amount:\n");
	scanf("%f",&sal);
	for(i=0;i<n;i++)
	{
		if(mem[i].salary > sal)
		{
			printMem(mem,i);
			flag = 1;
		}
	}
	if(flag != 1)
	{
		printf("No member is found\n");
	}
}
void searchId(struct CREW *mem, int n)
{
	int i,search;
	puts("Enter the ID to be searched:");
	scanf("%d",&search);
	for(i=0; i < n ;i++)
	{
		if(mem[i].crewId == search)
		{
			printf("The ID is found at %d\n",i+1);
			printMem(mem,i);
			return;
		}
	}
	printf("The ID is not found\n");
}

void dispGrade(struct CREW *mem, int n)
{
	int i,flag =0;
	char search;
	puts("Enter the grade to be searched:");
	__fpurge(stdin);
	scanf("%c",&search);
	for(i=0; i < n ;i++)
	{
		if(mem[i].grade == search)
		{
			printf("The Grade is found at %d\n",i+1);
			printMem(mem,i);
			flag = 1;
		}
	}
	if(flag != 1)
	{
		printf("Grade is not found\n");
	}
}
