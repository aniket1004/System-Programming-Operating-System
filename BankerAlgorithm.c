#include <stdio.h>
#include <stdlib.h>


int m=0,n=0;
void Safty_Algo(int avail[m],int A[n][m],int need[n][m],int finish[n]);
void Accept_matrix(int A[n][m],int max[n][m],int avail[m])
{
	int i=0,j=0;
	for (i=0;i<n;i++)
	{
		printf ("\nAllocation for process %d :",i+1);
		for (j=0;j<m;j++)
		{
			scanf ("%d",&A[i][j]);
		}	
	}
	for (i=0;i<n;i++)
	{
		printf ("\nMax for process %d :",i+1);
		for (j=0;j<m;j++)
		{
			scanf ("%d",&max[i][j]);
		}
	}
	printf ("\nEnter available: ");
	for (j=0;j<m;j++)
	{
		scanf ("%d",&avail[j]);
	}
}
void Display_matrix(int A[n][m],int max[n][m],int avail[m])
{	
	int i=0,j=0;
	printf ("\nProcess\t\tAllocation\t\tMax\n");
	printf ("----------------------------------------------------------------------------\n");
	for (i=0;i<n;i++)
	{
		printf ("P%d\t\t",i+1);
		for (j=0;j<m;j++)
			printf ("%d ",A[i][j]);
		printf ("\t\t");
		for (j=0;j<m;j++)
			printf ("%d ",max[i][j]);
		printf ("\n");
	}
	printf ("---Available----\n");
	for (j=0;j<m;j++)
			printf ("%d ",avail[j]);
	
}
void Display_need(int A[n][m],int max[n][m],int need[n][m],int avail[m])
{
	int i=0,j=0;
	printf ("\nProcess\t\tAllocation\t\tMax\t\tNeed\n");
	printf ("----------------------------------------------------------------------------\n");
	for (i=0;i<n;i++)
	{
		printf ("P%d\t\t",i+1);
		for (j=0;j<m;j++)
			printf ("%d ",A[i][j]);
		printf ("\t\t");
		for (j=0;j<m;j++)
			printf ("%d ",max[i][j]);
		printf ("\t\t");
		for (j=0;j<m;j++)
			printf ("%d ",need[i][j]);
		printf ("\n");
	}
	printf ("---Available----\n");
	for (j=0;j<m;j++)
			printf ("%d ",avail[j]);
	
}
void find_need(int A[n][m],int max[n][m],int need[n][m],int avail[m])
{
	int i=0,j=0;
	for (i=0;i<n;i++)
		for (j=0;j<m;j++)
			need[i][j]=max[i][j]-A[i][j];
	Display_need(A,max,need,avail);
}
int proc=0;
void Accept_Req(int req[m])
{	
	int i=0;
	printf ("\nEnter process no :");
	scanf ("%d",&proc);
	for (i=0;i<m;i++)
		scanf ("%d",&req[i]);
}
int compare_need(int p,int need[n][m],int work[m])
{
	int i,j,flag=0;
	for (i=0;i<m;i++)
	{
		if (need[p][j]>work[j])
		{
			flag=1;
			break;
		}
	}
	if (flag==0)
		return p;
	return -1;
}
void Safty_Algo(int avail[m],int A[n][m],int need[n][m],int finish[n])
{
	int i=0,j=0,k=0,l=0;
	int navail[m];
	for (i=0;i<m;i++)
		navail[i]=avail[i];

	while(k<n)
	{
		printf ("%d ",k);
		for (i=0;i<n;i++)
		{
			for (j=0;j<m;j++)
			{
				if (navail[j]<need[i][j])
				{
					break;
				}

			}
			if (j==m)
			{
				for (l=0;l<k;l++)
				{
					if (i==finish[l])
						break;
				}	
				if (l==k)
				{
					for (j=0;j<m;j++)
					{
						navail[j]+=A[i][j];
					}
					finish[k]=i;
					k++;
				}
			}
		}
	}
	for (i=0;i<n;i++)
	{
		printf ("\nProcess%d\n",finish[i]);
	}
	printf ("\nNew allocation");
	for (i=0;i<m;i++)
	{
		printf (" %d ",navail[i]);
	}

}
void Resource_request_algo(int A[n][m],int max[n][m],int need[n][m],int avail[m],int req[m],int finish[n])
{
	int i=0;
	for (i=0;i<m;i++)
	{
		if (req[i]>need[proc][i])
		{
			printf ("error... process exceeds its max demand");
			exit(0);
		}
	}
	for (i=0;i<m;i++)
	{
		if (req[i]>avail[i])
		{
			printf ("Process must wait,resources not available");
			exit(0);	
		}
	}
	for (i=0;i<m;i++)
	{
		avail[i]=avail[i]-req[i];
		A[proc][i]=A[proc][i]+req[i];
		need[proc][i]=need[proc][i]-req[i];
	} 
	Display_matrix(A,max,avail);
}
int main()
{
	int ch=0,i=0;
	
	printf ("Enter no. of processes & no. of resources :");
	scanf ("%d %d",&n,&m);
	int A[n][m],max[n][m],need[n][m],avail[m],req[m],finish[n];
	do
	{
		printf ("\n1.Accept \t 2.Display \t 3.Find need and display \t4.Exit\n");
		printf ("Enter your choice :");
		scanf ("%d",&ch);
		switch(ch)
		{
			case 1:
				Accept_matrix(A,max,avail);
				break;
			case 2:
				Display_matrix(A,max,avail);
				break;
			case 3:
				find_need(A,max,need,avail);
				break;
			
		}
	}while(ch!=4);
	Safty_Algo(avail,A,need,finish);
	for (i=0;i<m;i++)
		printf(" %d ",avail[i]);
	printf ("\n");
	Accept_Req(req);
	Resource_request_algo(A,max,need,avail,req,finish);
	printf("----------");
	for (i=0;i<m;i++)
		printf (" %d ",avail[i]);
	Safty_Algo(avail,A,need,finish);
	return 0;
}
