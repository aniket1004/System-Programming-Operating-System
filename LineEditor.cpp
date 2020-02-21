#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char *line;
	struct node *next;
}NODE,*PNODE;
  
PNODE head,last;



void readBuff (PNODE head,char *filename)
{
	NODE *temp=NULL;
	char str[80]={'\0'};
	FILE *fp=NULL;
	if ((fp=fopen(filename,"r"))!=NULL)
	{
		
		while (!feof(fp))
		{
			if (!fgets(str,80,fp))
				break;

			temp=(PNODE)malloc (sizeof(NODE));
			temp->next=NULL;
			temp->line=(char*) malloc(strlen(str));
			strcpy(temp->line,str);
			last->next=temp;
			last=temp;
		}
	}
}
int lines (PNODE head)
{
	int icnt=0;
	PNODE temp=head->next;
	while (temp!=NULL)
	{
		icnt++;
		temp=temp->next;
	}
	return icnt;
}

void Insert (PNODE head ,int n1)
{
	char str[80]={'\0'};
	PNODE temp1=head->next;
	PNODE temp=(PNODE)malloc(sizeof(NODE));
	temp->next=NULL;
	printf ("\nEnter the line that you want to insert: ");
	fgets(str,80,stdin);
	temp->line=(char *)malloc(strlen(str));
	strcpy (temp->line,str);

	if (n1==1)
	{
		temp->next=head->next;
		head->next=temp;
	}
	else if (n1==(lines(head))+1)
	{
		last->next=temp;
		last=temp;
	}
	else
	{
		while (n1>2)
		{
			temp1=temp1->next;
			n1--;
		}
		temp->next=temp1->next;
		temp1->next=temp;
	}
	printf ("\nInserted successfully");
}

void Save (PNODE head)
{
	PNODE temp=head->next;
	FILE *fp=NULL;
	char fname[25]={'\0'};

	printf ("\nEnter filename: ");
	fgets (fname,25,stdin);

	if ((fp=fopen(fname,"w"))!=NULL)
	{
		while (temp!=NULL)
		{
			fputs (temp->line,fp);
			temp=temp->next;
		}
	}
}

void Print (PNODE head,int n1,int n2)
{
	PNODE temp1=head->next;
	PNODE temp2=head->next;
		if ((n1==0)&&(n2==0))
		{
			while (temp1!=NULL)
			{
				printf ("%s\n",temp1->line);
				temp1=temp1->next;
			}
		}
		else
		{
		while (n1>1)
		{
			temp1=temp1->next;
			n1--;
		}
		while (n2>1)
		{
			temp2=temp2->next;
			n2--;
		}
		if ((n1>0)&&(n2>0))
		{
		while (temp1!=temp2->next)
		{
			printf ("%s\n",temp1->line);
			temp1=temp1->next;
		}
		}
		}
}
void Delete (PNODE head,int n1,int n2)
{
	PNODE temp=head->next;
	PNODE temp1=NULL,t1=NULL,t2=NULL,t3=NULL;
	PNODE temp2=head->next;
	if ((n1<0)&&(n1>(lines(head))))
	{
		return;
	}
	if ((n2<0)&&(n2>(lines(head)))&&(n2<n1))
	{
		return;
	}
	while (n2>1)
	{
		temp2=temp2->next;
		n2--;
	}
	if (n1==1)
	{
		temp1=temp2->next;
		while (temp->next!=temp1)
		{
			t1=temp;
			temp=temp->next;
			free(t1);
		}
		head->next=temp1;
	}
	else if (n1==lines(head))
	{
		while (temp->next!=last)
		{
			temp=temp->next;
		}
		free(temp->next);
		temp->next=NULL;
		last=temp;
	}
	else
	{
		while (n1>2)
		{
			temp=temp->next;
			n1--;
		}
		t2=temp2->next;
		t1=temp->next;
		while (t1->next!=t2)
		{
			t3=t1;
			t1=t1->next;
			free(t3);	
		}
		temp->next=t2;
	}
}
void Move (PNODE head,int n1,int n2)
{
	PNODE temp1=head->next;
	PNODE temp2=head->next;
	char str[80]={'\0'};
	while (n1>1)
	{
		temp1=temp1->next;
		n1--;
	}
	while (n2>1)
	{
		temp2=temp2->next;
		n2--;
	}
	strcpy (str,temp1->line);
	strcpy (temp1->line,temp2->line);
	strcpy (temp2->line,str);

}
void Copy (PNODE head,int n1,int n2)
{
	PNODE temp1=head->next;
	PNODE temp2=head->next;
	PNODE temp=(PNODE)malloc(sizeof(NODE));
	temp->next=NULL;
	temp->line=(char *)malloc ((n2-n1+1)*80);
	last->next=temp;
	last=temp;
	while (n1>1)
	{
		temp1=temp1->next;
		n1--;
	}
	while (n2>1)
	{
		temp2=temp2->next;
		n2--;
	}
	while (temp1!=temp2->next)
	{
		temp=(PNODE)malloc(sizeof(NODE));
		temp->next=NULL;
		temp->line=(char *)malloc (80);
		last->next=temp;
		last=temp;
		strcpy(temp->line,temp1->line);
		temp1=temp1->next;
	}
}

int main (int argc,char *args[])
{
	char str[50]={'\0'},c1='\0',name[30]={'\0'};
	char command[4][80];
	int n=0,c2=0,c3=0,c4=0;
	head=(PNODE)malloc (sizeof(NODE));
	head->next=NULL;
	last=head;
	if (argc>1)
	{
		readBuff(head,args[1]);
	}
	printf ("\nNo. of lines: %d\n",lines(head));
	

	while(1)
	{
		fflush(stdin);
		strcpy(str,"");

		printf ("\nTerminal ->");
		fgets(str,80,stdin);

		n=sscanf(str,"%c %d %d %d",&c1,&c2,&c3,&c4);
		
		switch (c1)
		{
		case 'p':
					Print (head,c2,c3);
					break;

		case 'i':
					Insert (head,c2);
					break;

		case 's':
					Save (head);
					break;

		case 'd':
					Delete(head,c2,c3);
					break;

		case 'm':
					Move (head,c2,c3);
					break;

		case 'c':
					Copy(head,c2,c3);
					break;

		case 'q':
					exit(0);
		}
	}
	return 0;
}

