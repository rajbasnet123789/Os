#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    key_t key = ftok("shmfile", 65);          // Create a unique key
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);  // Create a shared memory segment

    char *str = (char*) shmat(shmid, NULL, 0);  // Attach shared memory

    if (fork() == 0) {
        // ---------- Child Process ----------
        printf("Child: Enter some text for parent: ");
        fgets(str, 1024, stdin);                // Write user input to shared memory
        printf("Child: Data written to shared memory.\n");
    } else {
        // ---------- Parent Process ----------
        wait(NULL);                             // Wait for child to complete
        printf("Parent: Data read from shared memory: %s", str);
        shmdt(str);                             // Detach shared memory
        shmctl(shmid, IPC_RMID, 0);             // Delete shared memory segment
    }
    return 0;
}
