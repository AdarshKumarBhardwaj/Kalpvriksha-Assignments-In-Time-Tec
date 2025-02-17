#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_ROOM_NAME_LENGTH 50
#define MAX_COMMAND_LENGTH 100
#define MAX_ROOMS 100

typedef struct {
    char name[MAX_ROOM_NAME_LENGTH];
    char lightStatus[4];
    pthread_mutex_t mutex;
} Room;

int numRooms;
Room rooms[MAX_ROOMS];

void turnOn(Room* room) {
    pthread_mutex_lock(&room->mutex);
    strcpy(room->lightStatus, "ON");
    pthread_mutex_unlock(&room->mutex);
}

void turnOff(Room* room) {
    pthread_mutex_lock(&room->mutex);
    strcpy(room->lightStatus, "OFF");
    pthread_mutex_unlock(&room->mutex);
}

void checkStatus(Room* room, char* statusBuffer) {
    pthread_mutex_lock(&room->mutex);
    strcpy(statusBuffer, room->lightStatus);
    pthread_mutex_unlock(&room->mutex);
}

Room* findRoomByName(const char* name) {
    for (int i = 0; i < numRooms; i++) {
        if (strcmp(rooms[i].name, name) == 0) {
            return &rooms[i];
        }
    }
    return NULL;
}

void* processCommands(void* arg) {
    char command[MAX_COMMAND_LENGTH];

    while (fgets(command, sizeof(command), stdin) != NULL) {
        command[strcspn(command, "\n")] = 0;

        if (command[0] == '\0') {
            break;
        }

        char operation[20] = {0};
        char roomName[MAX_ROOM_NAME_LENGTH] = {0};

        char* token = strtok(command, " ");
        if (token != NULL) {
            strncpy(operation, token, sizeof(operation) - 1);
            operation[sizeof(operation) - 1] = '\0';

            token = strtok(NULL, " ");
            if (token != NULL) {
                strncpy(roomName, token, sizeof(roomName) - 1);
                roomName[sizeof(roomName) - 1] = '\0';
            }
            else {
                
                continue;
            }
        }
        else {
            continue;
        }

        Room* room = findRoomByName(roomName);
        if (!room) {
            printf("Room not found: %s\n", roomName);
            continue;
        }

        if (strcmp(operation, "TURN_ON") == 0) {
            turnOn(room);
        }
        else if (strcmp(operation, "TURN_OFF") == 0) {
            turnOff(room);
        }
        else if (strcmp(operation, "STATUS") == 0) {
            char status[4];
            checkStatus(room, status);
            printf("%s\n", status);
        } 
        else {
            printf("Invalid command\n");
        }
    }
    return NULL;
}

int main() {
    scanf("%d", &numRooms);
    getchar();

    for (int i = 0; i < numRooms; i++) {
        fgets(rooms[i].name, sizeof(rooms[i].name), stdin);
        rooms[i].name[strcspn(rooms[i].name, "\n")] = '\0';
        strcpy(rooms[i].lightStatus, "OFF");
        pthread_mutex_init(&rooms[i].mutex, NULL);
    }

    pthread_t commandThread;
    pthread_create(&commandThread, NULL, processCommands, NULL);
    pthread_join(commandThread, NULL);

    for (int i = 0; i < numRooms; i++) {
        pthread_mutex_destroy(&rooms[i].mutex);
    }

    return 0;
}

