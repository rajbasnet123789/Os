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

    file f[n]; // Variable-length array (C99 feature)

    printf("Enter details: <file_no> <file_name> <start_index> <block_size>\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %19s %d %d", &f[i].file_no, f[i].file_name, &f[i].start_in, &f[i].block_size);
    }

    printf("\nFile Details:\n");
    for (int i = 0; i < n; i++) {
        printf("File %d: %s, Start = %d, Size = %d\n",
               f[i].file_no, f[i].file_name, f[i].start_in, f[i].block_size);
    }

    return 0;
}
