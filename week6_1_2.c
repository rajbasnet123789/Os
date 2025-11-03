#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX 100

// Define a structure for the message
struct msg_buffer {
    long msg_type;        // message type (must be >0)
    char msg_text[MAX];   // message data
};

int main() {
    struct msg_buffer message;
    key_t key;
    int msgid;

    // Generate a unique key using ftok
    key = ftok("progfile", 65);

    // Create a message queue (or get existing one)
    msgid = msgget(key, 0666 | IPC_CREAT);

    if (fork() == 0) {
        // ---------- Child Process ----------
        message.msg_type = 1;

        printf("Child: Enter message for parent: ");
        fgets(message.msg_text, MAX, stdin);

        // Send message to the message queue
        msgsnd(msgid, &message, sizeof(message.msg_text), 0);

        printf("Child: Message sent to parent.\n");
    }
    else {
        // ---------- Parent Process ----------
        sleep(2);  // Give child time to send the message

        // Receive message of type 1
        msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0);

        printf("Parent: Message received from child: %s", message.msg_text);

        // Destroy the message queue
        msgctl(msgid, IPC_RMID, NULL);
    }

    return 0;
}
