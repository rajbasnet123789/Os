#include<stdio.h>
#include<unistd.h>
int main(){
    int p[2];
    int return_status;
    char writing[2][25]={"Hello","World"};
    char readmsg[25];
    return_status=pipe(p);
    if(return_status==-1){
        printf("pipe not created");
    }
    printf("\nWriting started %s",writing[0]);
    write(p[1],writing[0],sizeof(writing[0]));
    read(p[0],readmsg,sizeof(readmsg));
    printf("\nReading from pipe %s\n",readmsg);
    printf("\nWriting started %s",writing[1]);
     write(p[1],writing[1],sizeof(writing[1]));
     read(p[0],readmsg,sizeof(readmsg));
    printf("\nReading from pipe %s\n",readmsg);
    return 0;
}