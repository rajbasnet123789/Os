#include <stdio.h>
#include <stdlib.h>

typedef struct file {
    int file_no;
    char file_name[20];
    int start_in;
    int block_size;
} file;

int main() {
    int n;
    printf("Enter number of files: ");
    scanf("%d", &n);
    bool block[100000]=false;
    file f[n]; 

    printf("Enter details: <file_no> <file_name> <start_index> <block_size>\n");
    for (int i = 0; i < n; i++) {
        
        scanf("%d %19s %d %d", &f[i].file_no, f[i].file_name, &f[i].start_in, &f[i].block_size);
        while(1){
            int flag=0;
            for(int j=f[i].start_in;j<f[i].start_in+f[i].block_size;j++){
                if(block[j]==true){
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                printf("Blocks from %d to %d are already allocated. Enter different start index: ",f[i].start_in,f[i].start_in+f[i].block_size-1);
                scanf("%d",&f[i].start_in);
            }
            else{
                for(int j=f[i].start_in;j<f[i].start_in+f[i].block_size;j++){
                    block[j]=true;
                }
                break;
            }
        }
    }

    printf("\nFile Details:\n");
    for (int i = 0; i < n; i++) {
        printf("File %d: %s, Start = %d, Size = %d\n",
               f[i].file_no, f[i].file_name, f[i].start_in, f[i].block_size);
    }

    return 0;
}
