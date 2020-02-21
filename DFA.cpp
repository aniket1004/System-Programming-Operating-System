#include<stdio.h>
#include <stdlib.h>
#include <conio.h>
/*struct DFA
{
		int m;				//no of states
		int n;				//no of symbols
		int delta[10][10];	//transition table
		int final[10];		//array of final states
};*/

int m;				//no of states
int n;				//no of symbols
int delta[10][10];	//transition table
int final[10];


char c[10],str[20];
int f=0;


void Display();
void Accept();		//Accepting inputs(state,trasition,symbols)
void Display();		//Display DFA five tuples with trasition table
void execute();
int chk(char ,int);
int main()
{
	char ch='\0';
	
	do 
	{
		
		Accept();
		Display();
		execute();
		printf ("\nDo you want to continue (y/n): ");
		printf ("%c",ch=getch());
		printf ("\n");
	}while ((ch!='n')&&(ch!='N'));
	
	return 0;
}

void Accept()
{
	int i=0,j=0;
	
	printf ("\nEnter the number of states that dfa consist : ");
	scanf ("%d",&m);
	printf ("\nEnter the number of input symbols that dfa consist : ");
	scanf ("%d",&n);

	printf ("\nEnter the input symbols\t");
	for (i=0;i<n;i++)
	{
		printf ("\n%d input \t",i+1);
		printf ("%c",c[i]=getch());
	}

	printf ("\nEnter number of final states : ");
	scanf ("%d",&f);

	for (i=0;i<f;i++)
	{
		printf ("\nEnter the final state %d : q",i+1);
		scanf ("%d",&final[i]);
	}
	
	printf ("\n\nEnter trasition for every input symbol ");

	for(i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
				printf ("\n(q%d,%c)=q",j,c[i]);
				scanf ("%d",&delta[i][j]);
		}
	}
}
void execute()
{
	int i=0,s=0,nf=0;
	printf ("Enter input string :");
	scanf ("%s",str);

	while (str[i]!='\0')
		if ((s=chk(str[i++],s))<0)
		break;
		for (i=0;i<f;i++)
		if (final[i]==s)
		nf=1;
			if (nf==1)
		printf ("\nValid string");
			else
		printf ("\nInvalid string");
			
}	

int chk(char a,int b)
{
	int i=0;

	for (i=0;i<n;i++)
	if (a==c[i])
	return (delta[b][i]);
	return -1;
}
void Display()
{
	int i=0,j=0;
	printf ("\t|");
	for (i=0;i<n;i++)
	{
		printf ("%c\t",c[i]);
	}
	printf ("\n");
	printf ("--------------------------------");
	printf ("\n");
	for (i=0;i<m;i++)
	{
		printf ("q%d\t|",i);
		for (j=0;j<n;j++)
		{
			printf ("q%d\t",delta[j][i]);
		}
		printf ("\n");
	}
}