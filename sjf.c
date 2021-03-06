#include<stdio.h>
#include<stdlib.h>

struct Process
{
	int id;
	int AT;
	int BT;
	int wt;
	int TT;
	
};

void sort(struct Process list[10], int s)
{
    int i, j;
    struct Process temp;
    
    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < (s - 1-i); j++)
        {
            if (list[j].BT > list[j + 1].BT)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            } 
        }
    }
}

int main()
{
	printf("\n******************SJF non-premeptive*******************\n");
	
	struct Process p[10];
	int n,count = 0,Twt=0,TotalTT=0;
	printf("Enter the no. of processes : ");
	scanf("%d",&n);
	printf("Enter Arrival Time and Burst Time for each Processes\n");
	for(int i=0;i<n;i++)
	{
		p[i].id = i+1;
		printf("\nProcess-%d :-\n",i+1);
		printf("AT : ");
		scanf("%d",&p[i].AT);
		printf("BT : ");
		scanf("%d",&p[i].BT);
	}
	sort(p , n);     //sort acc. to Burst time
	
	for(int i=0;i<n;i++)
	{
		if (p[i].AT == 0)
		{
			p[i].wt = count;
			p[i].TT = p[i].BT+p[i].wt;
			count = count + p[i].BT;
			Twt += p[i].wt;
			TotalTT += p[i].TT;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(p[i].AT != 0 && p[i].AT <= count)
		{
			p[i].wt = count - p[i].AT;
			p[i].TT = p[i].BT + p[i].wt;
			count = count + p[i].BT;
			
			Twt += p[i].wt;
			TotalTT += p[i].TT;
		}
		if(p[i].AT > count)
		{
			count += p[i].AT - p[i-1].BT;
			i--;
		}
	}
	printf("\nProcess AT\tBT\tWT\tTotalTT\n");
	for(int i=0;i<n;i++)
		if(p[i].AT == 0)
			printf("P%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].AT , p[i].BT,p[i].wt,p[i].TT);
	
	for(int i=0;i<n;i++)
		if(p[i].AT != 0)
			printf("P%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].AT , p[i].BT,p[i].wt,p[i].TT);
	
	printf("\n Total waiting time :%d", Twt );
	printf("\n Average waiting time :%f",(double)Twt/n);
	printf("\n Total turn around time :%d",TotalTT);
	printf("\n Average turn around time: :%f",(double)TotalTT/n);
	return 0;

}
