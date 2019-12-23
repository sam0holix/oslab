#include<stdio.h>

void waitingTime(int processes[], int n, int bt[],int wt[], int at[]) {
  int service_time[n];
  service_time[0] = 0;
  wt[0] = 0;
  for(int i=1;i<n;i++) {
    service_time[i] = service_time[i-1] + bt[i-1];
    wt[i] = service_time[i] - at[i];
    if(wt[i]<0)
      wt[i] = 0;
  }
}

void turnAroundTime(int processes[],int n,int bt[],int wt[],int tat[]) {
  for(int i=0;i<n;i++) {
    tat[i] = bt[i] + wt[i];
  }
}

void avgTime(int processes[],int n, int bt[],int at[]) {
  int wt[n],tat[n];
  waitingTime(processes,n,bt,wt,at);
  turnAroundTime(processes,n,bt,wt,tat);
  printf("PID\tBT\tAT\tWT\tTAT\tCT\n");
  int total_wt = 0,total_tat = 0;
  for(int i = 0;i < n; i++) {
    total_wt +=wt[i];
    total_tat +=tat[i];
    int comp_time = tat[i] + at[i];
    printf("%d\t",i+1);
    printf("%d\t",bt[i]);
    printf("%d\t",wt[i]);
    printf("%d\t",tat[i]);
    printf("%d\n",comp_time);
  }
  float s = (float)total_wt/(float)n;
  float t = (float)total_tat/(float)n;
  printf("\nAvg waiting time = %f",s);
  printf("\nAvg tat = %f",t);
}

void main() {
  int processes[] = {1,2,3};
  int n = sizeof processes / sizeof processes[0];
  int burst_time[] = {5,9,6};
  int arrival_time[] = {0,3,6};
  avgTime(processes,n,burst_time,arrival_time);
}
