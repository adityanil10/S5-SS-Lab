// Sidharth S CS4A Roll No 54
// FCFS
#include<stdio.h>

void fcfs(int n, int bt[]){
  int wt[n], tat[n], total_wt = 0, total_tat = 0, s, t;

  wt[0] = 0;

  for (int i = 1; i < n ; i++)
    wt[i] = bt[i-1] + wt[i-1];
    
  for (int i = 0; i < n ; i++)
    tat[i] = bt[i] + wt[i];
    
  printf("\n Processes Burst Time Waiting Time Turn Around Time\n");

  for (int i=0; i<n; i++) {
    total_wt = total_wt + wt[i];
    total_tat = total_tat + tat[i];
    printf("\t%d ",(i+1));
    printf("\t\t%d ", bt[i] );
    printf("\t\t\t%d",wt[i] );
    printf("\t\t\t\t%d\n",tat[i] );
  }

  s = (float)total_wt / (float)n;
  t = (float)total_tat / (float)n;
  printf(" The average waiting time : %d",s);
  printf("\n");
  printf(" The average turn around time : %d ",t);
  printf("\n");
}

void main() {
  int burst_time[10], n;
  printf("\n FCFS \n");
  printf("\n Enter no of processes : ");
  scanf("%d", &n);
  printf("\n Enter burst time : ");
  for(int i=0; i<n; i++)
    scanf("%d", &burst_time[i]);

  fcfs(n, burst_time);
}
