#include<stdio.h>  
#include<conio.h>  
  
int main()  
{  
    int i, n, sum=0,count=0, y, quant, wt=0, tat=0, at[10], bt[10], temp[10],id[10];  
    float avg_wt, avg_tat;  
    
    printf(" Total number of process in the system: ");  
    scanf("%d", &n);  
    y = n;  
  
  	printf("\n Enter the Arrival and Burst time of the Processes\n");
	for(i=0; i<n; i++)  
	{  
		  
		printf(" Process-%d \n\tAT :\t",i+1);    
		scanf("%d", &at[i]);  
		printf("\n\tBT :\t");   
		scanf("%d", &bt[i]);
		  
		id[i] = i+1;  
		temp[i] = bt[i];
	}  
	
	printf(" Enter the Time Quantum Value :\t");  
	scanf("%d", &quant);  
	
	printf("\n **********GANTT CHART***********\n");
	printf("\n Process\t\tTS");  
	
	for(sum=0, i = 0; y!=0; )  
	{  
		if(temp[i] <= quant && temp[i] > 0)
		{  
		    sum = sum + temp[i];  
		    temp[i] = 0;  
		    count=1; 
			printf("\n P%d\t\t%d", id[i],sum-at[i]);
	    }     
	    else if(temp[i] > 0)  
	    {  
	        temp[i] = temp[i] - quant;  
	        sum = sum + quant;
			printf("\n P%d\t\t%d", id[i],sum-at[i]);    
	    }  
	    if(temp[i]==0 && count==1)  
	    {  
	        y--; 
	        printf("\n Process-%d Completed!! \tT-Time : %d \tW-Time : %d", i+1, sum-at[i], sum-at[i]-bt[i]);  
	        wt = wt+sum-at[i]-bt[i];  
	        tat = tat+sum-at[i];  
	        count =0;     
	    }  
	    if(i==n-1)  
	    {  
	        i=0;  
	    }  
	    else if(at[i+1]<=sum)  
	    {  
	        i++;  
	    }  
	    else  
	    {  
	        i=0;  
	    }  
	}  
	
	// represents the average waiting time and Turn Around time  
	avg_wt = wt * 1.0/n;  
	avg_tat = tat * 1.0/n;
	  
	printf("\n\nTurn Around Time : %d",tat);
	printf("\n Average Turn Around Time : %f", avg_tat);   
	printf("\n Average Waiting Time : %d",wt);  
	printf("\n Average Waiting Time : %f", avg_wt);
	
	return 0;  
}  
