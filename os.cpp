#include<stdio.h>
#include<conio.h>
int main()
{
	int pid[10],at[10],bt[10],ct[10],ta[10],wt[10],f[10];
	int n,st=0,tot=0;
	float avgwt=0,avgta=0;
	printf("\nenter the number of process");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("\nenter process p%d Arrival time",i);
		scanf("%d",&at[i]);
		printf("\nenter process p%d brust time",i);
		scanf("%d",&bt[i]);
		pid[i]=i+1;
		f[i]=0;
	}
	while(true)
	{
		int c=n,min=999;
		if(tot==n)
		{
			break;
		}
		for(int i=0;i<n;i++)
		{
			if((at[i]<=st) && (f[i]==0) && (bt[i]<min))
			{
				min = bt[i];
				c=i;
			}
		}
		if(c==n)
		{
			st++;
		}
		else
		{
			ct[c]=st+bt[c];
			st = st+bt[c];
			ta[c] = ct[c]-at[c];
			wt[c] = ta[c]-bt[c];
			f[c] = 1;
			pid[tot]==c+1;
			tot++;
		}
	}
	printf("\npid ... arrival time ... brust time ...complete ... turnaround time ... waiting time");
	for(int i=0;i<n;i++)
	{
		avgwt = avgwt +wt[i];
		avgta = avgta +ta[i];
		printf("\n%d,%d,%d,%d,%d,%d",pid[i],at[i],bt[i],ct[i],ta[i],wt[i]);
	}
	printf("\naverage tat is %f:",avgta/n);
	printf("\naverage wt is %f:",(avgwt/n));
	
}
