#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>
int main(){
    DIR *dir;
    struct dirent *entry;
    dir=opendir(".");
    if(dir==NULL){
         printf("error");
    }
    while(entry=readdir(dir)!=NULL){
        print("%s",entry->d_name);
    }
    closedir(dir);
    return 0;
}