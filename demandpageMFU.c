#include <stdio.h>
#include <stdlib.h>

struct frames
{
	int pno,freq;
}frame[30];
int f=0;


int find_page(int fno)
{
	int i=0;
	for (i=0;i<f;i++)
	{
		if (frame[i].pno==fno)
			return i;
	}
	return -1;
}
int empty_frame()
{
	int i=0;
	for (i=0;i<f;i++)
	{
		if (frame[i].pno==-1)
			return i;
	}
	return -1;
}
int find_mfu()
{
	int i=0,max=frame[0].freq,j=0;
	for (i=0;i<f;i++)
	{
		if (frame[i].freq>max)
		{
			max=frame[i].freq;
			j=i;
		}
	}
	return j;/*
	int fno;
  	int selfno=0;
  	for (fno=1; fno<f; fno++)
    		if(frame[fno].freq>frame[selfno].freq)
    			selfno=fno;
  	printf ("selfno:%d",selfno);
	return selfno;*/
}
int main()
{
	int req[]={5,8,10,14,10,9,5,10,8,5,1,10,9,12,10};
	int size=15,i=0,j=0,page=0,fno=0;
	printf ("\nEnter no of frame");
	scanf ("%d",&f);
	for (i=0;i<f;i++)
	{
		frame[i].pno=-1;
		frame[i].freq=0;
	}
	for (i=0;i<size;i++)
	{
		j=find_page(req[i]);
		if (j==-1)
		{
			j=empty_frame();
			if (j==-1)
				j=find_mfu();
			frame[j].pno=req[i];
			frame[j].freq=1;
			page++;
			printf ("\n");
			for(fno=0;fno<f;fno++)
			{
				if (frame[fno].pno!=-1)
				{
					printf ("%d\t",frame[fno].pno);
				}
			}
		}
		else
		{
			frame[j].freq++;
			printf("\n");
			for(fno=0;fno<f;fno++)
			{
				if (frame[fno].pno!=-1)
				{
					printf ("%d\t",frame[fno].pno);
				}
			}
		}
	}
	printf ("\nPage fault :%d",page);
	return 0;
}

