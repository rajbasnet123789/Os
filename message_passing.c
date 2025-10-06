#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<unistd.h>

struct msg_buffer{
    long msg_type;
    char msg_text[100];
}message;
int main(){
    key_t key;
    int msgid;
    key=ftok("progfile",65);
    msgid=msgget(key,0666|IPC_CREAT);
    message.msg_type=1;
    if(fork()==0){
        strcpy(message.msg_text,"Message from child");
        
    }

}