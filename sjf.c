#include<stdio.h>
#include<stdlib.h>


void main()
{
    int n=0;
    printf("Enter No. of processes: ");
    scanf("%d",&n);
    int p[n],bt[n],tat[n],wt[n],i,k;
    float tat_tl,wt_tl;
    for(i=0;i<n;i++)
    {
        printf("P%d : ",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }

    for(i=0;i<n;i++)
    {
        int j=i+1;
        for(;j<n;j++)
        {
            if(bt[i]>bt[j])
            {
               bt[i]=(bt[i]+bt[j])-(bt[j]=bt[i]);
               
               p[i]=(p[i]+p[j])-(p[j]=p[i]);
            }
        }
    }
    tat[0]=tat_tl=bt[0];
    wt[0]=wt_tl=0;
    for(i=1;i<n;i++)
    {
        wt[i]=tat[i-1];
        tat[i]=bt[i]+tat[i-1];
        tat_tl+=tat[i];
        wt_tl+=wt[i];
    }

    for(i=0;i<n;i++)
    {
        printf("P%d %d || ",p[i],tat[i]);
    }
    printf("\nAverage Turn Around Time is %f",tat_tl/n);
    printf("Average Waiting Time is %f",wt_tl/n);

    getch();
}