 #include<stdio.h>
 #include<unistd.h>
 #include<sys/types.h>


 int main(){
    
    pid_t id;

    id=fork();
    if(id<0){
        printf("sorry fork failed. \n");
        return 1;
    }
    else if(id==0){
        printf("child process is running .....\n");
        printf("child p_id  : %d \n",getpid());
        printf("parent p_id(child) : %d \n ",getppid());
    }
    else{
        printf("parent process is running ....\n");
        printf("parent p_id : %d\n",getpid());
        printf("child id(parent) : %d \n",id);
    }
return 0;

}