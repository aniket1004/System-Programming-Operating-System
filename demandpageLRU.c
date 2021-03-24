#include <stdio.h>
#include <stdlib.h>

int f=0;
int getPos(int arr[],int frame[],int pos)
{
	int i=0,j=0,p=0,k=0,min=99999;
	for (j=0;j<f;j++)
	{
	for(i=pos-1;i>=0;i--)
	{
		if(arr[i]==frame[j])
		{
			if (min>i)
			{
				k=j;
				min=i;
				break;
			}
		}
		
	}
	}
	return k;
}
int main()
{
	int i=0,j=0,pos=0,k=0,l=0,pf=0;
	int arr[]={7,0,1,2,0,3,0,4,2,3,0,3,2,3};
	printf ("Enter no. of frames :");
	scanf ("%d",&f);
	int frame[f];
	for (i=0;i<f;i++)
		frame[i]=-1;

	
	for (i=0;i<14;i++)
	{
		
		if(j<f)
		{
			for (l=0;l<f;l++)
			{
				if (frame[l]==arr[i])
					break;
			}
			if (l==f)
			{
				pf++;
			frame[j]=arr[i];
			j++;
			}
		}
		else if(j>=f)
		{
			for(l=0;l<f;l++)
			{
				if (frame[l]==arr[i])
					break;
			}
			if (l==f)
			{
			pos=getPos(arr,frame,i);
			frame[pos]=arr[i];
			pf++;
			}
		}
		printf ("\n");
		for (k=0;k<j;k++)
			printf ("%d ",frame[k]);
		
	}
	printf ("Total Page fault :%d",pf); 
	return 0;
}
