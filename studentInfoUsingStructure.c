#include <stdio.h>
#include <string.h>
#include<stdlib.h> 
#define MAX_STUDENTS 100
#define MAX_GAMES 3
 
typedef struct {
    char id[10];
    int games[MAX_GAMES];
} Student;
 
int findStudentIndex(Student students[], int count, char *id) {
    for (int index = 0; index < count; index++) {
        if (strcmp(students[index].id, id) == 0) {
            return index;
        }
    }
    return -1;
}
 
int compareStudents(const void *a, const void *b) {
    return strcmp(((Student *)a)->id, ((Student *)b)->id);
}
 
int main() {
    int number;
    printf("Enter the number of students: ");
    scanf("%d", &number);
 
    char gameNames[MAX_GAMES][20] = {"badminton", "TT", "cricket"};
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    for (int index = 0; index < MAX_STUDENTS; index++) {
        students[index].games[0] = students[index].games[1] = students[index].games[2] = 0;
    }
 
    for (int index1 = 0; index1 < number; index1++) {
        char id[10], game[20];
        printf("Enter ID and game name: ");
        scanf("%s %s", id, game);
 
        int studentIndex = findStudentIndex(students, studentCount, id);
 
        if (studentIndex == -1) {
            strcpy(students[studentCount].id, id);
            studentIndex = studentCount;
            studentCount++;
        }
 
        for (int index2 = 0; index2 < MAX_GAMES; index2++) {
            if (strcmp(gameNames[index2], game) == 0) {
                students[studentIndex].games[index2] = 1;
                break;
            }
        }
    }
 
    qsort(students, studentCount, sizeof(Student), compareStudents);
    printf("Students enrolled in all three games: ");
    for (int index = 0; index < studentCount; index++) {
        if (students[index].games[0] && students[index].games[1] && students[index].games[2]) {
            printf("%s ", students[index].id);
        }
    }
    printf("\n");
    printf("All unique students enrolled in at least one game: ");
    for (int index = 0; index < studentCount; index++) {
        printf("%s ", students[index].id);
    }
    printf("\n");
 
    return 0;
}

