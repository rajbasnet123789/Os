#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        sleep(5);
        printf("Child process (PID: %d), Parent PID: %d\n", getpid(), getppid());
        exit(0);
    } else {
        printf("Parent process (PID: %d), Child PID: %d\n", getpid(), pid);
        sleep(2);
        printf("Parent exiting without wait\n");
        exit(0);
    }
}
