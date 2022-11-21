// Sidharth S CS4A Roll No 54
// SJF
#include<stdio.h>

int main() {
  int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
  float avg_wt,avg_tat;

  printf("\n SJF \n");

  printf("\n Enter number of process : ");
  scanf("%d",&n);
  printf("\n Enter Burst Time :");

  for(i=0;i<n;i++) {
    printf(" %d : ", i+1);
    scanf("%d",&bt[i]);
    p[i]=i+1;         
  }
  
  for(i=0;i<n;i++){
    pos=i;
    for(j=i+1;j<n;j++) {
      if(bt[j]<bt[pos])
        pos=j;
    }
    temp=bt[i];
    bt[i]=bt[pos];
    bt[pos]=temp;

    temp=p[i];
    p[i]=p[pos];
    p[pos]=temp;
  }
   
  wt[0]=0;            
   
  for(i=1;i<n;i++) {
    wt[i]=0;
    for(j=0;j<i;j++)
      wt[i]+=bt[j];
      total+=wt[i];
  }
  
  avg_wt=(float)total/n;      
  total=0;
  
  printf("\n Process Burst Time Waiting Time Turn Around Time\n");
  for(i=0;i<n;i++) {
    tat[i]=bt[i]+wt[i];   
    total+=tat[i];
    printf("\t %d\t\t\t%d\t\t\t%d\t\t\t%d\n",p[i],bt[i],wt[i],tat[i]);
  }
  
  avg_tat=(float)total/n;    
  printf("\n The average waiting time : %f", avg_wt);
  printf("\n The average turnaround time : %f", avg_tat);
  printf("\n");
  return 0;
}
