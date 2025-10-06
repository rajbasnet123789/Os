#include<stdio.h>
#include<unistd.h>
int main(){
     int p[2];
     int returnstatus;
     char writing[2][25]={"Hello","World"};
     char readmsg[25];
     if(returnstatus==-1){
        printf("pipe not created");
     }
    printf("Writing started");
    write(p[0],writing[0],sizeof(writing[0]));
    read(p[1],readmsg,sizeof(readmsg));
    printf("Reading from pipe");
    return 0;
}