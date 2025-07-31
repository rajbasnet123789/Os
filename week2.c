#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
 typedef struct node{
      int arrival;
      int brust;
      int ct;
      int tat;
      int wt;
      int st;
    }node;
   
    int compare (const void *p1, const void *p2)
{
    int a=((node*)p1)->arrival;
    int b=((node *)p2)->arrival;

if (a<b)
       return -1;
else
       return 1;  
}

int main(){
    int n;
    scanf("%d",&n);
    int sbt=0,swt=0,stat=0;
    node p[n];
    for(int i=0;i<n;i++){
        scanf("%d %d",&p[i].arrival,&p[i].brust);
        p[i].ct=0;
        p[i].tat=0;
        p[i].wt=0;
        p[i].st=0;
    }
     qsort((void*)p,n,sizeof(node),compare);
     for(int i=0;i<n;i++){
         if(i==0){
           p[i].ct=p[i].arrival+p[i].brust;
         }
         else if(p[i-1].ct <= p[i].arrival){
             p[i].ct=p[i].arrival+p[i].brust;
         }
         else{
            p[i].ct=p[i-1].ct+p[i].brust;
         }
        p[i].tat=p[i].ct-p[i].arrival;
        p[i].wt=p[i].tat-p[i].brust;
        p[i].st=p[i].ct-p[i].arrival;

        sbt+=p[i].brust;
        swt+=p[i].wt;
        stat+=p[i].st;
        


     }
    printf("Process\tArrival\tBrust\tCT\tTAT\tWT\tST\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i+1, p[i].arrival, p[i].brust, p[i].ct, p[i].tat, p[i].wt, p[i].st);
    }
    printf("Average Waiting Time: %.2f\n", (float)swt/n);
    printf("Average Turnaround Time: %.2f\n", (float)stat/n);
    printf("Average Service Time: %.2f\n", (float)sbt/n);
    return 0;
    
  
}
