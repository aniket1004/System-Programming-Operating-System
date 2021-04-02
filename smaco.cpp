#include <stdio.h>
#include <stdlib.h>



int mem[1000];
int pc,lc,REG[4],cc[6];

void Load (char filename[])
{
	FILE *fp=fopen(filename,"r+");
	int address=0,content=0;
	
	
	if (fp!=NULL)
	{
		while (fscanf (fp,"%d %d",&address,&content)!=EOF)
		{
			if (address==-1)
			{
				pc=content;
			}
			else
			{
				lc=address;
				mem[address]=content;
			}
		}
	}
	

}

void print ()
{
	int ic=pc;
	for (ic=pc;ic<=lc;ic++)
	{
		printf ("%d\n",mem[ic]);
	}
}
void Execute (int pc)
{
	int ic=pc,op=0,reg=0,opd=0,d=0;

	while (ic<=lc)
	{
		op=mem[ic]/10000;
		reg=((mem[ic]%10000)/1000)-1;
		opd=mem[ic]%1000;

		if (op==0)
		{
			break;
		}
		switch (op)
		{
		

		case 1:
					REG[reg]+=mem[opd];
					ic++;
					break;

		case 2:
					REG[reg]=mem[opd]-REG[reg];
					if (REG[reg]<0)
					{
						REG[reg]=-(REG[reg]);
					}
					ic++;
					break;

		case 3:
					REG[reg]*=mem[opd];
					ic++;
					break;
		
		case 4: 
					REG[reg]=mem[opd];
					ic++;
					break;

		case 5:
					mem[opd]=REG[reg];
					ic++;
					break;

		case 6:
					for (int i=0;i<6;i++)
					{
						cc[i]=0;
					}
					if (mem[opd]>REG[reg])
						cc[0]=1;
					if (mem[opd]>=REG[reg])
						cc[1]=1;
					if (mem[opd]==REG[reg])
						cc[2]=1;
					if (mem[opd]<REG[reg])
						cc[3]=1;
					if (mem[opd]<=REG[reg])
						cc[4]=1;
					ic++;break;
					

		case 7:
					if ((cc[reg]==1)||(reg==5))
						ic=opd;
					else
						ic++;
					break;
		case 8:
					REG[reg]/=mem[opd];
					ic++;
					break;

		case 9:
					printf ("Enter data: ");
					scanf ("%d",&mem[opd]);
					ic++;
						break;

		case 10:
				printf ("Answer is :%d",mem[opd]);
				ic++;
					break;
		
		}
		
	}
}

void Accept (char filename[])
{
	FILE *fp=fopen(filename,"w");
	char content[20]={'\0'};
	int address=0,con=0;
	do
	{
		printf ("\nEnter data");
		fgets(content,20,stdin);
		fprintf (fp,"%s",content);
		sscanf(content,"%d %d",&address,&con);
	}while (address!=-1);

	fclose(fp);
}

int main()
{
	char fname[20]={'\0'};
	int ch=0;
	do
	{
	printf ("\nMenu drive");
	printf ("\n1.Load\n2.Print\n3.Accept\n4.Run\n5.Trace\n6.Quit");
	printf ("\nEnter your choice:");
	scanf ("%d",&ch);

	switch(ch)
	{
	case 1:
				printf ("\nEnter filename: ");
				scanf ("%s",fname);
				Load(fname);
				printf ("\nFile load successfully");
				break;

	case 2:
				print();
				break;

	case 3:
				printf ("\nEnter filename where you want to store data:");
				scanf ("%s",fname);
				Accept (fname);
				break;

	case 4:
				Execute (pc);
				break;



	}
	}while (ch!=6);

	return 0;
}
