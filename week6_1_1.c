#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main() {
    int fd[2];  
    pid_t pid;
    char write_msg[] = "hi Akshat here";
    char read_msg[20];

    if (pipe(fd) == -1) {
        printf("pipe failed\n");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        printf("fork failed\n");
        return 1;
    }

    if (pid == 0) {
        // Child process
        close(fd[0]); // Close unused read end
        write(fd[1], write_msg, sizeof(write_msg)); // Write message into pipe
        close(fd[1]);
    } else {
        // Parent process
        close(fd[1]); // Close unused write end
        read(fd[0], read_msg, sizeof(read_msg)); // Read message from pipe
        printf("read %s\n", read_msg);
        close(fd[0]);
    }
}
