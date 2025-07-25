#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){
    
    int n;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        
         scanf("%d",&arr[i]);
    }
   __pid_t pid;
    pid=fork();
    if(pid<0){
        printf("failed to make process");
    }
    else if(pid==0){
          printf("The odd number of array is :");
           for(int i=0;i<n;i++){
         if(arr[i]%2!=0){
            printf("%d",arr[i]);
         }
            }
        
        wait(NULL);
    }
    else{
            printf("The even number of array is :");
           for(int i=0;i<n;i++){
         if(arr[i]%2==0){
            printf("%d",arr[i]);
         }
        }
        exit(0);
          
    }
}