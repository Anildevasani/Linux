#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Define the message structure
struct message {
    long priority;
    char text[100];
};

int main() {
    key_t key;
    int msgid;
    struct message msg;

    // Generate a unique key for the message queue
    key = ftok("/tmp", 'A');
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // Create a message queue with read and write permissions
    msgid = msgget(key, IPC_CREAT | 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    // Write three messages to the message queue with different priorities
    // Priority values are used to determine the order in which messages are received

    // Message 1
    msg.priority = 1;
    strcpy(msg.text, "This is message 1 with priority 1.");
    if (msgsnd(msgid, &msg, sizeof(msg.text), 0) == -1) {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }

    // Message 2
    msg.priority = 3;
    strcpy(msg.text, "This is message 2 with priority 3.");
    if (msgsnd(msgid, &msg, sizeof(msg.text), 0) == -1) {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }

    // Message 3
    msg.priority = 2;
    strcpy(msg.text, "This is message 3 with priority 2.");
    if (msgsnd(msgid, &msg, sizeof(msg.text), 0) == -1) {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }

    printf("Messages written to the message queue.\n");

    // Remove the message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    return 0;
}

