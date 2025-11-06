#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct file {
    int file_no;
    char file_name[20];
    int start_in;
    int block_size;
    struct file* next; 
} file;

file* create_node(int file_no, char* file_name, int start_in, int block_size) {
    file* new_file = (file*)malloc(sizeof(file));
    new_file->file_no = file_no;
    strcpy(new_file->file_name, file_name);
    new_file->start_in = start_in;
    new_file->block_size = block_size;
    new_file->next = NULL;
    return new_file;
}

void insert_at_tail(file** head, int file_no, char* file_name, int start_in, int block_size) {
    file* new_file = create_node(file_no, file_name, start_in, block_size);
    if (*head == NULL) {
        *head = new_file;
        return;
    }
    file* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_file;
}

void print_files(file* head) {
    file* temp = head;
    while (temp != NULL) {
        printf("File %d: %s, Start = %d, Size = %d\n",
               temp->file_no, temp->file_name, temp->start_in, temp->block_size);
        temp = temp->next;
    }
}

int main() {
    int n;
    printf("Enter number of files: ");
    scanf("%d", &n);

    file* head = NULL;

    printf("Enter details: <file_no> <file_name> <start_index> <block_size>\n");
    for (int i = 0; i < n; i++) {
        int file_no, start_in, block_size;
        char file_name[20];
        scanf("%d %19s %d %d", &file_no, file_name, &start_in, &block_size);
        insert_at_tail(&head, file_no, file_name, start_in, block_size);
    }

    printf("\nFile Details:\n");
    print_files(head);

   

    return 0;
}
