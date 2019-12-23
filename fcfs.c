#include<stdio.h>

void waitingTime(int processes[], int n, int bt[], int wt[]) {
  wt[0] = 0;
  for(int i=1;i<n;i++)
    wt[i] = bt[i-1] + wt[i-1];
}

void turnAroundTime(int processes[],int n, int bt[], int wt[], int tat[]) {
  for(int i=0;i<n;i++)
    tat[i] = bt[i] + wt[i];
}

void avgTime(int processes[],int n,int bt[]) {
  int wt[n],tat[n],total_wt = 0, total_tat = 0;
  waitingTime(processes,n,bt,wt);
  turnAroundTime(processes,n,bt,wt,tat);
  printf("PID\tBT\tWT\tTAT");
  for(int i = 0;i<n;i++) {
    printf("\n");
    total_wt +=wt[i];
    total_tat +=tat[i];
    printf("%d\t",i+1);
    printf("%d\t",bt[i]);
    printf("%d\t",wt[i]);
    printf("%d",tat[i]);
  }
  int s = (float)total_wt/(float)n;
  int t = (float)total_tat/(float)n;
  printf("\nAvg waiting time = %d",s);
  printf("\nAvg tat = %d",t);
}

void main() {
  int processes[] = {1,2,3};
  int n = sizeof processes/sizeof processes[0];
  int burst_time[] = {10,5,8};
  avgTime(processes,n,burst_time);
}
