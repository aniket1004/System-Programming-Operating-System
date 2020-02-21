#include <stdio.h>
#include <stdlib.h>

struct queue
{
	char val;
	struct queue *next;
}*first=NULL,*last=NULL;
struct queue * createQ(struct queue *temp,struct queue *temp1,int f)
{
	int i=0;
	struct queue *newn=NULL;
	
	for (i=0;i<f;i++)
	{
		newn=(struct queue *)malloc(sizeof(struct queue));
		newn->next=NULL;

		if (temp==NULL)
		{
			temp=newn;
			temp1=newn;
		}
		else
		{
			temp1->next=newn;
			temp1=newn;
		}
	}
	last=temp1;
	return temp;
}
int main()
{
	int f=0,i=0,j=0,pf=0,k=0,flag=0;
	struct queue *temp=NULL,*newn=NULL,*temp1=NULL,*temp2=NULL,*temp3=NULL;
	printf ("Enter the no. of frames :");
	scanf ("%d",&f);
	first=createQ(first,last,f);
	temp=first;
	char ch[15]={'3','4','5','6','3','4','7','3','4','5','6','7','2','4','6'};
	for (i=0;i<15;i++)
	{

		if (i==0)
		{
			temp->val=ch[i];
			temp=temp->next;
			pf++;
			k++;	
		}
		else if (k<f)
		{
			for (temp3=first;temp3!=NULL;temp3=temp3->next)
			{
				if (temp3->val==ch[i])
					break;
			}
			if (temp3==NULL)
			{
				temp->val=ch[i];
				temp=temp->next;
				pf++;
				k++;
			}
		}
		else if (k>=f)
		{
			for (temp3=first;temp3!=NULL;temp3=temp3->next)
                        {
                                if (temp3->val==ch[i])
                                        break;
                        }
			if (temp3==NULL)
			{
				newn=(struct queue *)malloc(sizeof(struct queue));
				newn->next=NULL;
				newn->val=ch[i];
				last->next=newn;
				last=newn;
				temp1=first->next;
				first->next=NULL;
				first=temp1;
				pf++;
			}
		}
		
		for(temp2=first,j=0;(temp2!=NULL)&&(j<=i);temp2=temp2->next,j++)
		{
			printf ("%c ",temp2->val);
		}
		
		printf ("\n");
	}
	printf ("Total Page Fault is :%d",pf); 
	return 0;
}
