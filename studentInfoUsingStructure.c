#include <stdio.h>
#include <string.h>

typedef struct
{
    char studentId[10];
    char gamesPlayed[3][10];
    int gameCount;
} Student;

int findStudentIndex(Student students[], int totalStudents, char *studentId)
{
    for (int studentIndex = 0; studentIndex < totalStudents; studentIndex++)
    {
        if (!strcmp(students[studentIndex].studentId, studentId))
        {
            return studentIndex;
        }
    }
    return -1;
}

int main()
{
    Student students[100];
    int totalUniqueStudents = 0;
    int totalInputEntries;
    char inputStudentId[10], inputGame[10];

    printf("Enter the total number of student : ");
    scanf("%d", &totalInputEntries);

    for (int entryIndex = 0; entryIndex < totalInputEntries; entryIndex++)
    {
        printf("Enter student ID and game (separated by space): ");
        scanf("%s %s", inputStudentId, inputGame);

        int studentIndex = findStudentIndex(students, totalUniqueStudents, inputStudentId);

        if (studentIndex == -1)
        {
            strcpy(students[totalUniqueStudents].studentId, inputStudentId);
            strcpy(students[totalUniqueStudents].gamesPlayed[0], inputGame);
            students[totalUniqueStudents].gameCount = 1;
            totalUniqueStudents++;
        }
        else
        {
            int gameAlreadyExists = 0;
            for (int gameIndex = 0; gameIndex < students[studentIndex].gameCount; gameIndex++)
            {
                if (!strcmp(students[studentIndex].gamesPlayed[gameIndex], inputGame))
                {
                    gameAlreadyExists = 1;
                    break;
                }
            }
            if (!gameAlreadyExists && students[studentIndex].gameCount < 3)
            {
                strcpy(students[studentIndex].gamesPlayed[students[studentIndex].gameCount], inputGame);
                students[studentIndex].gameCount++;
            }
        }
    }

    printf("Students who play exactly three games:\n");
    for (int studentIndex = 0; studentIndex < totalUniqueStudents; studentIndex++)
    {
        if (students[studentIndex].gameCount == 3)
        {
            printf("%s ", students[studentIndex].studentId);
        }
    }
    printf("\n");

    printf("All unique students:\n");
    for (int studentIndex = 0; studentIndex < totalUniqueStudents; studentIndex++)
    {
        printf("%s ", students[studentIndex].studentId);
    }
    printf("\n");

    return 0;
}

