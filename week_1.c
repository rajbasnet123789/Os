#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){
    __pid_t pid;
    pid=fork();
    if(pid<0){
        printf("failed to make process");
    }
    else if(pid==0){
          printf("First Child piid is %d\n",getpid());

          execlp("ls","ls","-l",NULL);
          printf("\n");
        
          exit(1);
    }
    else{
          wait(NULL);
          
          pid_t pid2=fork();
          if(pid2<0){
              printf("failed to make process");
          }
          else if(pid2==0){
                printf("Second Child piid is %d\n",getpid());
          }
          else{
              printf("parent child piid is %d\n",getpid());
          }
    }
}